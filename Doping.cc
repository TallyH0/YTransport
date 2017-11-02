#include "Doping.h"


ClassImp(Doping)
Doping::Doping()
{
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
double ddoping(double x, double y, double z)
{
	double a = 1e19, b = 17, c = 0.880639;
	if(13 <= z && z <= 17)
		return a * (z-b) / (c*c) * exp(-pow(z-b,2)/(2*c*c)); 
	else if(17 <= z && z <= 19)
		return 0;
	else return 0;
}
