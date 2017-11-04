#include <iostream>
#include <fstream>
#include <cmath>
const double m = 9.11e-31;
const double q = 1.602e-19;

struct Efield
{
	int n;
	double x, y, z, Ex, Ey, Ez;
};

double mobility(double);
double doping(double);
double distance(double x1, double y1, double z1, double x0, double y0, double z0);
void ReadE(Efield* E);
int first_index(double, double, double, Efield* );
int second_index(double, double, double, Efield* );
void interpolate(double x, double y, double z, Efield* E, double* E_val);
double collision_time(double z);

double v_drift(double x_val, double y_val, double z_val,Efield* E, int type)
{
	int index = first_index(x_val, y_val, z_val, E);
	switch(type){
	    case 0:
            return mobility(z_val) * E[index].Ex * 1e-4;
			break;
		case 1:
		    return mobility(z_val) * E[index].Ey * 1e-4;
			break;
		case 2:
		    return mobility(z_val) * E[index].Ez * 1e-4;
			break;
		default:
			printf("Wrong type\n");
		    break;
	}
	return 0;
}
void ReadE(Efield* E)
{
	std::ifstream ifs ("efield_Si_output.txt");
	if(!ifs) std::cout << "Error\n";

	Efield tmp;
	int i = 0;
	while(!ifs.eof())
	{
		ifs >> tmp.n >> tmp.x >> tmp.y >> tmp.z >> tmp.Ex >> tmp.Ey >> tmp.Ez;	
		E[i].n = tmp.n;
		E[i].x = tmp.x;
		E[i].y = tmp.y;
		E[i].z = tmp.z;
		E[i].Ex = tmp.Ex;
		E[i].Ey = tmp.Ey;
		E[i].Ez = tmp.Ez;
        i++;
	}
}
double mobility(double z)
{
	static double const m_max = 470.5;
	static double const m_min = 44.9;
	static double const N_r = 2.23e17;
	static double const alpha = 0.719;

	return m_min + (m_max - m_min) / (1 + pow(doping(z)/N_r , alpha));
}
double doping(double z)
{
	double a = 1e19, b = 17, c = 0.880639;
	if(13 <= z && z <= 17)
		return a * exp(-pow(z-b,2)/(2*c*c)); 
	else if(17 <= z && z <= 19)
		return 1e19;
	else return 1e12;
}	
int first_index(double x, double y, double z, Efield* E)
{
	int index = 0;
	double min = 99999999;
	for(int i = 0; i < 105541; ++i){
		if(sqrt(pow(E[i].x - x, 2) + pow(E[i].y - y, 2) + pow(E[i].z - z, 2)) < min){
		    min = sqrt(pow(E[i].x - x, 2) + pow(E[i].y - y, 2) + pow(E[i].z - z, 2));
			index = i;
		 }	
	}
	return index;
}
int second_index(double x, double y, double z, Efield *E)
{
    int index0 = first_index(x,y,z,E);
	int index = 0;
	double min = 99999999;
	for(int i = 0; i < 105540; ++i){
		if(pow(E[i].x - x, 2) + pow(E[i].y - y, 2) + pow(E[i].z - z, 2) < min){
		    min = pow(E[i].x - x, 2) + pow(E[i].y - y, 2) + pow(E[i].z - z, 2);
			if(i != index0)
			    index = i;
		 }	
	}
	return index;
}
void interpolate(double x, double y, double z, Efield* E, double* vd_xyz)
{
	double E_val[3];
    int in0 = first_index(x,y,z,E);
	int in1 = second_index(x,y,z,E);
	
	E_val[0] = E[in0].Ex * distance(E[in1].x, E[in1].y, E[in1].z, x, y, z) + E[in1].Ex * distance(x, y, z, E[in0].x, E[in0].y, E[in0].z) / distance(E[in1].x, E[in1].y, E[in1].z, E[in0].x, E[in0].y, E[in0].z);
	E_val[1] = E[in0].Ey * distance(E[in1].x, E[in1].y, E[in1].z, x, y, z) + E[in1].Ey * distance(x, y, z, E[in0].x, E[in0].y, E[in0].z) / distance(E[in1].x, E[in1].y, E[in1].z, E[in0].x, E[in0].y, E[in0].z);
	E_val[2] = E[in0].Ez * distance(E[in1].x, E[in1].y, E[in1].z, x, y, z) + E[in1].Ez * distance(x, y, z, E[in0].x, E[in0].y, E[in0].z) / distance(E[in1].x, E[in1].y, E[in1].z, E[in0].x, E[in0].y, E[in0].z);
	vd_xyz[0] = mobility(z) * E_val[0] * 1e-4;
	vd_xyz[1] = mobility(z) * E_val[1] * 1e-4;
	vd_xyz[2] = mobility(z) * E_val[2] * 1e-4;
}
double distance(double x1, double y1, double z1, double x0, double y0, double z0)
{
    return sqrt(pow(x1-x0,2) + pow(y1-y0,2) + pow(z1-z0,2));
}
double collision_time(double z)
{
	return 1e-4 * mobility(z) * m / q;
} 
