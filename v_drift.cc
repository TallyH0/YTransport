#include <iostream>
#include <fstream>

struct Efield
{
	int n;
	double x, y, z, Ex, Ey, Ez;
};

double mobility(double);
double doping(double);
void ReadE(Efield* E);
int find_index(double, double, double, Efield* );

double v_drift(double x_val, double y_val, double z_val,Efield* E, int type)
{
	int index = find_index(x_val, y_val, z_val, E);
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
	static double const m_max = 1414;
	static double const m_min = 68.5;
	static double const N_r = 9.20e16;
	static double const alpha = 0.711;

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
int find_index(double x, double y, double z, Efield* E)
{
	int index = 0;
	double min = 99999999;
	for(int i = 0; i < 105540; ++i){
		if(pow(E[i].x - x, 2) + pow(E[i].y - y, 2) + pow(E[i].z - z, 2) < min){
			min = pow(E[i].x - x, 2) + pow(E[i].y - y, 2) + pow(E[i].z - z, 2); 
			index = i;
		 }	
	}
	return index;
}
