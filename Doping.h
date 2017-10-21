#ifndef DOPING_H
#define DOPING_H

#include <iostream>
#include <fstream>
#include <cmath>
#include "TRandom.h"

using namespace std;


struct doping_value
{
	double x, y, z, doping;
};

void ReadData(vector<doping_value> &, string iname);
//double doping(const vector<doping_value>, const electron);
double doping(double, double, double);
double doping_diff(double, double, double);

class Doping{
	public:
		Doping();
		ClassDef(Doping,0)
};
#endif
