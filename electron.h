#ifndef ELECTRON_H
#define ELECTRON_H

#include <vector>
#include "TRandom.h"
#include "YTransport.h"
#include "E_field.h"
#include "Geometry.h"
#include <cstdlib>
#include <cmath>
#include <ctime>

#define PI 3.14

using namespace std;

struct E_field;

class electron {
public:
	electron();
	electron& operator=(const electron&) { }
	void step(const vector<E_field>);
	double mean_free_path();
	int status() { return status_val; }
	double x, y, z;
	const double m = 9.11e-31;
	const double q = 1.602e-19;
	double t = 0;
	double path = 0;
	ClassDef(electron,0)

private:
	int cnt = 0;
	int status_val = 0;	
	double x0, y0, z0;
	double collision_time();
	double D_n();
	void rebound();
	bool In_anode();
};
#endif
