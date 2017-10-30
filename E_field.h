#ifndef E_FIELD_H
#define E_FIELD_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#define PAD_SIZE 20

using namespace std;


struct E_field
{
	int n;
	double x, y, z, Ex, Ey, Ez;
};
void ReadData(vector<E_field> &);
void find_index(int*, const vector<E_field>, double x, double y, double z);
double distance(double, double, double, double, double, double);
void interpolate(double x, double y, double z, vector<E_field> E, double* vd_xyz);

#endif
