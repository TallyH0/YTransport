#ifndef ELECTRON_H
#define ELECTRON_H

#include <vector>
#include "TRandom.h"
#include "TMath.h"
#include "TF1.h"
#include "E_field.h"
#include "Geometry.h"
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

struct E_field;


class electron {
public:
	electron();
	electron(double r1, double r2, double r3, double rad) { x=r1; y=r2; z=r3; PI_eq=rad;}
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
	double beta = 4.1e-16;
	double PI_eq = 5e13;
	double collision_time();
	double D_n();
	void rebound();
	bool In_anode();
	double v_th();
	bool trap();
};
#endif
