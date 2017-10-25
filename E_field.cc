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
int find_index(const vector<E_field> E, double x, double y, double z)
{
	double x1, y1, z1;
	x1 = x - PAD_SIZE * ((int)(x+10) / PAD_SIZE);
	y1 = y - PAD_SIZE * ((int)(y+10) / PAD_SIZE);
	z1 = z; 
	int index = 0;
	double min = 99999999;
	for(int i = 0; i < E.size(); ++i){
		if(pow(E[i].x - x1, 2) + pow(E[i].y - y1, 2) + pow(E[i].z - z1, 2) < min){
			min = pow(E[i].x - x1, 2) + pow(E[i].y - y1, 2) + pow(E[i].z - z1, 2); 
			index = i;
		 }	
	}
	return index;
}

