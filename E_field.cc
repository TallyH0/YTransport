#include "E_field.h"
void ReadData(vector<E_field>& ElectricField)
{
	ifstream ifs ("efield_bb4v.txt");
	if(!ifs) std::cout << "Can't read file\n";
	E_field tmp;
	while(!ifs.eof()){
		ifs >> tmp.n >> tmp.x >> tmp.y >> tmp.z >> tmp.Ex >> tmp.Ey >> tmp.Ez;
		ElectricField.push_back(tmp);
	}
	
	vector<int> tmp_index;
	double x, y, z;
	for(int i=0; i<ElectricField.size(); ++i)
	{
	    x = ElectricField[i].x, y = ElectricField[i].y, z = ElectricField[i].z;
		for(int j=i+1; j<ElectricField.size(); ++j)
		{
		    if(x==ElectricField[j].x && y==ElectricField[j].y && z==ElectricField[j].z)
			{
			    tmp_index.push_back(j);
			}
		}
		for(int k=tmp_index.size()-1; k>=0; --k)
		{
		   ElectricField.erase(ElectricField.begin()+tmp_index[k]); 
		}
		tmp_index.clear();
	}
	for(int i=0; i<ElectricField.size(); ++i)
	{
	    ElectricField[i].n = i;
	}
}
void interpolate(double x, double y, double z, const vector<E_field> E, double* E_interpolated)
{
    E_interpolated[0] = 0;
    E_interpolated[1] = 0;
    E_interpolated[2] = 0;
    vector<inter> near8;	
	inter tmp;
	for(int i=0; i<E.size(); ++i)
	{
	   tmp.index = E[i].n;
	   tmp.dl = distance(x,y,z,E[i].x,E[i].y,E[i].z);
	   near8.push_back(tmp);
	}
	sort(near8.begin(), near8.end());
	int index = 0;
	for(int i=0; i<NEAR_N; ++i)
	{
	    index = near8[i].index;
	}
	double weight1[NEAR_N];
	double sum1=0;
	for(int i=0; i<NEAR_N; ++i)
	{
	    weight1[i] = pow(near8[i].dl,-2);
		sum1 += weight1[i];
	}
	for(int i=0; i<NEAR_N; ++i)
	{
	    weight1[i] /= sum1;
	}
	for(int i=0; i<NEAR_N; ++i)
	{
	   E_interpolated[0] += weight1[i] * E[near8[i].index].Ex; 
	   E_interpolated[1] += weight1[i] * E[near8[i].index].Ey; 
	   E_interpolated[2] += weight1[i] * E[near8[i].index].Ez; 
	}
	

}
double distance(double x1, double y1, double z1, double x0, double y0, double z0)
{
    return sqrt(pow(x1-x0,2) + pow(y1-y0,2) + pow(z1-z0,2));
}
