#include "electron.h"

ClassImp(electron);
TF1 * fdist = new TF1("fdist","x * x * TMath::Exp(-9.11e-31*x*x/(2*1.38064852e-23*273))",0,1e6);

electron::electron()
{
}
void electron::step(const vector<E_field> E)
{	
	double xo = x, yo = y, zo = z;	

	double v_xyz[3] = {0, 0, 0};
	double tau_c = collision_time();
	double dl = v_th() * tau_c * 1e9;
	v_drift(v_xyz, E);

	double theta = 2 * TMath::Pi() * gRandom->Rndm();
	double phi = 2 * TMath::Pi() * gRandom->Rndm();
	
	double dx = v_xyz[0] * tau_c * 1e3 + dl * cos(theta) * sin(phi);
	double dy = v_xyz[1] * tau_c * 1e3 + dl * sin(theta) * sin(phi);
	double dz = v_xyz[2] * tau_c * 1e3 + dl * cos(phi) + v_diff() * tau_c;

	x -= dx; y-= dy; z-=dz;

	path += sqrt(pow(xo-x,2) + pow(yo-y,2) + pow(zo-z,2));
	t += tau_c;

	rebound();
	if(trap()) status_val = -1;
#ifdef DEBUG
	if(z < 1) status_val = 1;
#else
	if(z < 1){
		if(In_anode())	status_val = 2;
		else status_val = 1;
	}
#endif
	cnt++;
}
double electron::D_n()
{
	return mobility() * k * T / q;
}
double electron::collision_time()
{
	return 1e-4 * mobility() * m / q;
} 
double electron::mean_free_path()
{
	return collision_time() * v_th();
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
	static double const m_max = 470.5;
	static double const m_min = 44.9;
	static double const N_r = 2.23e17;
	static double const alpha = 0.719;

#ifdef DEBUG
	return m_min + (m_max - m_min) / (1 + pow(1e12/N_r , alpha));
#else
	return m_min + (m_max - m_min) / (1 + pow(doping(x, y, z)/N_r , alpha));
#endif
}
double electron::v_drift(double* v_xyz, const vector<E_field> E)
{
#ifdef DEBUG
    double Mu = mobility();
    v_xyz[0] = Mu * 2.8e-11;
    v_xyz[1] = Mu * 1.9e-10;
    v_xyz[2] = Mu * 198;
#else
    double Mu = mobility();
	interpolate(x, y, z, E, v_xyz); 
	v_xyz[0] *= Mu;
	v_xyz[1] *= Mu;
	v_xyz[2] *= Mu;
#endif
}
double electron::v_diff()
{
#ifdef DEBUG
    double a_k = 0;
    double dn = fabs(ddoping(x, y, z));
	return a_k * dn;
#else
	double dn = fabs(ddoping(x, y, z));
	double j_n = q * D_n() * dn / dl;
	return j_n / (q * doping(x, y, z));
#endif
}
