#include "electron.h"

ClassImp(electron);
TF1 * fdist = new TF1("fdist","4*TMath::Pi()*TMath::Sqrt(TMath::Power(0.26*9.11e-31/(2*TMath::Pi()*TMath::K()*300),3))* x * x * TMath::Exp(0.26*-9.11e-31*x*x/(2*1.38064852e-23*300))",0,1e6);

electron::electron()
{
}
//void electron::step(const vector<E_field> E)
void electron::step(TH3F* hx1, TH3F* hx2, TH3F* hx3, TH3F* hy1, TH3F* hy2, TH3F* hy3, TH3F* hz1, TH3F* hz2, TH3F* hz3)
{	
	seed = gRandom->GetSeed();

	double tau_c = time_eff();
	double phi = 2 * TMath::Pi() * gRandom->Rndm();
	double uni_rand = -1 + 2 * gRandom->Rndm();
	//double tau_c = CONST_TAU;
	t += tau_c;
	double dl = v_th() * 1e6;
	//v_drift(vd_xyz, E);
	//v_drift(vd_xyz, hx1,hx2,hx3,hy1,hy2,hy3,hz1,hz2,hz3);

	
	dx = dl * TMath::Cos(phi) * TMath::Sqrt((1-uni_rand*uni_rand)) * tau_c;
	dy = dl * TMath::Sin(phi) * TMath::Sqrt((1-uni_rand*uni_rand)) * tau_c;
	dz = dl * uni_rand * tau_c;
    //dx = vd_xyz[0] * 1e6 * tau_c;
    //dy = vd_xyz[1] * 1e6 * tau_c;
    //dz = vd_xyz[2] * 1e6 * tau_c;
	//dx = dl * TMath::Cos(phi) * TMath::Sqrt((1-uni_rand*uni_rand)) * tau_c + vd_xyz[0] * 1e6 * tau_c;
	//dy = dl * TMath::Sin(phi) * TMath::Sqrt((1-uni_rand*uni_rand)) * tau_c + vd_xyz[1] * 1e6 * tau_c;
	//dz = dl * uni_rand * tau_c + vd_xyz[2] * 1e6 * tau_c;

	x -= dx; y-= dy; z-=dz;
	//DEBUG
	path_dl = sqrt(dx*dx + dy*dy + dz*dz);

	path += path_dl;
	rebound();
	if(trap()) status_val = -2;
    if(t > tau) status_val = -2;
	if(z < 1){
		if(In_anode())	status_val = 2;
		else status_val = 1;
	}
	cnt++;
}
double electron::D_n()
{
	return mobility() * k * T / q;
}
double electron::collision_time()
{
	return 1e-4 * 2 * mobility() * m / q;
} 
double electron::time_eff()
{
	return 1/(1/collision_time() + 1/(beta*PI_eq));
} 
void electron::rebound()
{
	while(z < 0 || z > DEPTH){
	    if(z > DEPTH) z = 2 * DEPTH - z;
		else if(z < 0) z++;
	}
	while(x > SIZE_X/2 || x < -SIZE_X/2){
	if(x > SIZE_X/2) x = SIZE_X - x;
	else if(x < -SIZE_X/2) x = -SIZE_X - x;
	}
	while(y > SIZE_Y/2 || y < -SIZE_Y/2){
	if(y > SIZE_Y/2) y = SIZE_Y -y;
	else if(y < -SIZE_Y/2) y = -SIZE_Y - y;
	}
}
bool electron::In_anode()
{
	double x1 = x - PAD_SIZE * ((int)(x+10) / PAD_SIZE);
	double y1 = y - PAD_SIZE * ((int)(y+10) / PAD_SIZE);
	if( ANODE_SIZE < fabs(x1) && fabs(x1) < ANODE_SIZE + SPACING && ANODE_SIZE < fabs(y1) && fabs(y1) < ANODE_SIZE + SPACING)
	return true;
	else return false;

	return false;
}
double electron::v_th()
{
	return fdist->GetRandom();	
    //return sqrt(3*k*T/m);	
}
bool electron::trap()
{
	double t_eff_inverse = beta * PI_eq;
    double P_trap = t_eff_inverse / (t_eff_inverse + 1/collision_time());
	if(gRandom->Rndm() < P_trap) return true;
	else return false;

	return false;
}
double electron::mobility()
{
    static double const Mu0 = 232;
    static double const Mu1 = 1180;
	static double const N_r = 8e16;
	static double const alpha = 0.9;

	return Mu0 + Mu1 / (1 + pow(doping(x, y, z)/N_r , alpha));
}
//void electron::v_drift(double* vd_xyz, const vector<E_field> E)
void electron::v_drift(double* vd_xyz, TH3F* hx1, TH3F* hx2, TH3F*hx3,TH3F* hy1, TH3F* hy2, TH3F* hy3, TH3F* hz1, TH3F* hz2, TH3F* hz3)
{
    double v_sat = 2.4e7 / (1+ 0.8 * TMath::Exp(T/600));

    double Mu = mobility();
	//interpolate(x, y, z, E, vd_xyz); 
	if(z<2.1)
	{
	    vd_xyz[0] = hx1->Interpolate(x,y,z);
	    vd_xyz[1] = hy1->Interpolate(x,y,z);
	    vd_xyz[2] = hz1->Interpolate(x,y,z);
		if(hz1->Interpolate(x,y,z) == 0 || hy1->Interpolate(x,y,z) ==0 || hx1->Interpolate(x,y,z) == 0)
		    printf("Domain 1 : %lf %lf %lf\n",x, y, z);
	}else if(z<17){
	    vd_xyz[0] = hx2->Interpolate(x,y,z);
	    vd_xyz[1] = hy2->Interpolate(x,y,z);
	    vd_xyz[2] = hz2->Interpolate(x,y,z);
		if(hz2->Interpolate(x,y,z) == 0 || hy2->Interpolate(x,y,z) ==0 || hx2->Interpolate(x,y,z) == 0)
		    printf("Domain 2 : %lf %lf %lf\n",x, y, z);
	}else{
	    vd_xyz[0] = hx2->Interpolate(x,y,z);
	    vd_xyz[1] = hy2->Interpolate(x,y,z);
	    vd_xyz[2] = hz2->Interpolate(x,y,z);
		if(hz3->Interpolate(x,y,z) == 0 || hy3->Interpolate(x,y,z) ==0 || hx3->Interpolate(x,y,z) == 0)
		    printf("Domain 3 : %lf %lf %lf\n",x, y, z);
	}
	Ez = vd_xyz[2];

    double v_x = Mu*vd_xyz[0] / (1 + Mu*vd_xyz[0] / v_sat);
    double v_y = Mu*vd_xyz[1] / (1 + Mu*vd_xyz[1] / v_sat);
    double v_z = Mu*vd_xyz[2] / (1 + Mu*vd_xyz[2] / v_sat);

	vd_xyz[0] = v_x * 1e-2;
	vd_xyz[1] = v_y * 1e-2;
	vd_xyz[2] = v_z * 1e-2;
	Vdz = vd_xyz[2];
}
double electron::lifetime()
{
    double dop = doping(x, y, z);
	if(dop < 1e16)
	    return 1e-3 / (1 + dop/5e16);
	else
	    return 5e-5 / (1 + dop/5e16);
}
