#include "electron.h"

ClassImp(electron);

electron::electron()
{
}
void electron::step(const vector<E_field> E)
{	
	double xo = x, yo = y, zo = z;	

	double tau_c = 1e-2 * collision_time();
	double dl = v_th(m) * tau_c * 1e9;

	int index = find_index(E, x, y, z);
	double Mu = mobility(x, y, z);

	double theta = rand();
	double phi = rand();
	
	x -= Mu * E[index].Ex * tau_c * 1e3;
	y -= Mu * E[index].Ey * tau_c * 1e3;
	z -= Mu * E[index].Ez * tau_c * 1e3;
	
	x += dl * cos(theta) * sin(phi);
	y += dl * sin(theta) * sin(phi);
	z += dl * cos(phi);

	path += sqrt(pow(x0-x,2) + pow(yo-y,2) + pow(zo-z,2));
	t += tau_c;


//DEBUG
	printf("z = %lf\n", z);
//DEBUG
	if(z < 1){
		if(In_anode())	status_val = 2;
		else status_val = 1;
		printf("done\n");
	}
	if(t > 1) status_val = 1;
}
double electron::D_n()
{
	return mobility(x, y, z) * k * T / q;
}
double electron::collision_time()
{
	return 1e-4 * 2 * mobility(x, y, z) * m / q;
} 
double electron::mean_free_path()
{
	return collision_time() * v_th(m);
} 
void electron::rebound()
{
	if(z > DEPTH) z = 2 * DEPTH - z;
	if(x > SIZE_X/2) x = x - SIZE_X/2;
	else if(x < SIZE_X/2) x = x + SIZE_X/2;
	if(y > SIZE_Y/2) y = y - SIZE_Y/2;
	else if(y < SIZE_Y/2) y = y + SIZE_Y/2;
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
