#include "Doping.h"


ClassImp(Doping)
Doping::Doping()
{
}

void ReadData(vector<doping_value> &D, string iname)
{
	ifstream ifs {iname};
	if(!ifs) cout << "Can't opne Doping profile\n";

	doping_value tmp;
	while(!ifs.eof()){
		ifs>>tmp.x>>tmp.y>>tmp.z>>tmp.doping;
		D.push_back(tmp);
	}
		
}
double doping(double x, double y, double z)
{
	double a = 1e19, b = 17, c = 0.880639;
	if(13 <= z && z <= 17)
		return a * exp(-pow(z-b,2)/(2*c*c)); 
	else if(17 <= z && z <= 19)
		return 1e19;
	else return 1e12;
}	
double doping_diff(double x, double y, double z)
{
	double a = 1e19, b = 17, c = 0.880639;
	if(13 <= z && z <= 17)
		return a * pow(z - b, 3) / 2 * pow(c,4) * exp(-pow(z-b,2)/(2*c*c));
	else if(17 <= z && z <= 19)
		return 0;
	else return 0;
}
/*
double Doping::doping(const vector<doping_value> D, const electron e)
{
	int index = 0;
	double min = 100;
	for(int i = 0; i < D.size(); ++i){
		if(pow(D[i].x - e.x, 2) + pow(D[i].y - e.y, 2) + pow(D[i].z - e.z, 2) < min){
		min = pow(D[i].x - e.x, 2) + pow(D[i].y - e.y, 2) + pow(D[i].z - e.z, 2) < min;
		index = i;
	}	
	}	
	return D[index].doping;
}
*/
