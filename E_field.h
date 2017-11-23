#ifndef E_FIELD_H
#define E_FIELD_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

#define PAD_SIZE 20

using namespace std;

struct E_field
{
	int n;
	double x, y, z, Ex, Ey, Ez;
};
struct inter{
    int index;
	double dl;
    bool operator <(const inter& b)
    {
        return this->dl < b.dl;
    }
};
void ReadData(vector<E_field> &);
double distance(double, double, double, double, double, double);
void interpolate(double x, double y, double z, const vector<E_field> E, double* E_interpolated);
#endif
