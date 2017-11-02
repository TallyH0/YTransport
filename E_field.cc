#include "E_field.h"

void ReadData(vector<E_field>& ElectricField)
{
	ifstream ifs {"efield_Si_output.txt"};
	if(!ifs) std::cout << "Can't read file\n";
	E_field tmp;
	while(!ifs.eof()){
		ifs >> tmp.n >> tmp.x >> tmp.y >> tmp.z >> tmp.Ex >> tmp.Ey >> tmp.Ez;
		ElectricField.push_back(tmp);
	}
}
void find_index(int* index, const vector<E_field> E, double x, double y, double z)
{
	double x1, y1, z1;
	x1 = x - PAD_SIZE * ((int)(x+10) / PAD_SIZE);
	y1 = y - PAD_SIZE * ((int)(y+10) / PAD_SIZE);
	z1 = z; 
	index[0] = index[1]= 0;
	double min = 99999999;
	for(int i = 0; i < E.size(); ++i){
		if(distance(E[i].x, E[i].y, E[i].z, x, y, z) < min){
			min = distance(E[i].x, E[i].y, E[i].z, x, y, z);
			index[0] = i;
		 }	
	}
	min = 99999999;
	for(int i = 0; i < E.size(); ++i){
		if(distance(E[i].x, E[i].y, E[i].z, x, y, z) < min){
	    	min = distance(E[i].x, E[i].y, E[i].z, x, y, z);
			if(i != index[0])
	    	    index[1] = i;
		}
    }	
}
void interpolate(double x, double y, double z, vector<E_field> E, double* vd_xyz)
{
    int index[2];
	find_index(index, E, x, y, z);
	double E_val[3];
	
	if(distance(E[index[1]].x, E[index[1]].y, E[index[1]].z, E[index[0]].x, E[index[0]].y, E[index[0]].z) != 0){
	E_val[0] = E[index[0]].Ex * distance(E[index[1]].x, E[index[1]].y, E[index[1]].z, x, y, z) + E[index[1]].Ex * distance(x, y, z, E[index[0]].x, E[index[0]].y, E[index[0]].z) / distance(E[index[1]].x, E[index[1]].y, E[index[1]].z, E[index[0]].x, E[index[0]].y, E[index[0]].z);
	E_val[1] = E[index[0]].Ey * distance(E[index[1]].x, E[index[1]].y, E[index[1]].z, x, y, z) + E[index[1]].Ey * distance(x, y, z, E[index[0]].x, E[index[0]].y, E[index[0]].z) / distance(E[index[1]].x, E[index[1]].y, E[index[1]].z, E[index[0]].x, E[index[0]].y, E[index[0]].z);
	E_val[2] = E[index[0]].Ez * distance(E[index[1]].x, E[index[1]].y, E[index[1]].z, x, y, z) + E[index[1]].Ez * distance(x, y, z, E[index[0]].x, E[index[0]].y, E[index[0]].z) / distance(E[index[1]].x, E[index[1]].y, E[index[1]].z, E[index[0]].x, E[index[0]].y, E[index[0]].z);
	vd_xyz[0] = E_val[0];
	vd_xyz[1] = E_val[1];
	vd_xyz[2] = E_val[2];
    }
	else{
	vd_xyz[0] = E[index[0]].Ex;
	vd_xyz[1] = E[index[0]].Ey;
	vd_xyz[2] = E[index[0]].Ez;
	}
}
double distance(double x1, double y1, double z1, double x0, double y0, double z0)
{
    return sqrt(pow(x1-x0,2) + pow(y1-y0,2) + pow(z1-z0,2));
}
#ifdef DEBUG2
int main()
{
    vector<E_field> field;
	ReadData(field);
	double avg[3] = {0};

	for(int i = 0; i < field.size(); ++i)
	{
	    avg[0] += field[i].Ex;
	    avg[1] += field[i].Ey;
	    avg[2] += field[i].Ez;
	}
	avg[0] /= field.size();
	avg[1] /= field.size();
	avg[2] /= field.size();
	printf("%e %e %e\n", avg[0], avg[1], avg[2]);
}
#endif
