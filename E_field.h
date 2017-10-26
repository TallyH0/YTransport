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
int find_index(const vector<E_field>, double x, double y, double z);

#endif
