#include "electron.h"

ClassImp(electron);
TF1 * fdist = new TF1("fdist","x * x * TMath::Exp(0.26*-9.11e-31*x*x/(2*1.38064852e-23*300))",0,1e6);

electron::electron()
{
}
void electron::step(const vector<E_field> E)
{	
	double xo = x, yo = y, zo = z;	

	double tau_c = time_eff();
	double dl = v_th() * tau_c * 1e6;
	v_drift(v_xyz, E);

	double theta = 2 * TMath::Pi() * gRandom->Rndm();
	double phi = 2 * TMath::Pi() * gRandom->Rndm();
	
	dx = v_xyz[0] * tau_c * 1e6 + dl * cos(theta) * sin(phi);
	dy = v_xyz[1] * tau_c * 1e6 + dl * sin(theta) * sin(phi);
	dz = v_xyz[2] * tau_c * 1e6 + dl * cos(phi);
	

	x -= dx; y-= dy; z-=dz;
	//DEBUG
	//double vth_x=(dl*cos(theta)*sin(phi));
	//double vth_y=(dl*sin(theta)*sin(phi));
	vth_z=(dl*cos(phi));
	//double vd_x=(v_xyz[0]*tau_c*1e6);
	//double vd_y=(v_xyz[1]*tau_c*1e6);
	vd_z=(v_xyz[2]*tau_c*1e6);

	path += sqrt(pow(xo-x,2) + pow(yo-y,2) + pow(zo-z,2));
	t += tau_c;
    time_eff();
	rebound();
	if(trap()) status_val = -1;
    if(t > tau) status_val = -1;
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
	cout<< 1/(1/collision_time() + 1/(beta*PI_eq)) << endl;
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
//	return fdist->GetRandom();	
    return sqrt(3*k*T/m);	
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
void electron::v_drift(double* v_xyz, const vector<E_field> E)
{
    double v_sat = 2.4e7 / (1+ 0.8 * TMath::Exp(T/600));

    double Mu = mobility();
	interpolate(x, y, z, E, v_xyz); 
    double v_x = Mu*v_xyz[0] / (1 + Mu*v_xyz[0] / v_sat);
    double v_y = Mu*v_xyz[1] / (1 + Mu*v_xyz[1] / v_sat);
    double v_z = Mu*v_xyz[2] / (1 + Mu*v_xyz[2] / v_sat);

	v_xyz[0] = v_x * 1e-2;
	v_xyz[1] = v_y * 1e-2;
	v_xyz[2] = v_z * 1e-2;
}
double electron::v_diff()
{
#ifdef DEBUG
    double a_k = 0;
    double dn = fabs(ddoping(x, y, z));
	return a_k * dn;
#else
/*
	double dn = fabs(ddoping(x, y, z));
	double j_n = q * D_n() * dn;
	return j_n / (q * doping(x, y, z));
*/
#endif
}
double electron::lifetime()
{
    double dop = doping(x, y, z);
	if(dop < 1e16)
	    return 1e-3 / (1 + dop/5e16);
	else
	    return 5e-5 / (1 + dop/5e16);
}
