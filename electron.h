#ifndef ELECTRON_H
#define ELECTRON_H

#include <vector>
#include "TRandom.h"
#include "TMath.h"
#include "TF1.h"
#include "TList.h"
#include "TPolyMarker3D.h"
#include "E_field.h"
#include "Geometry.h"
#include <cstdlib>
#include <cmath>
#include <ctime>

#define SIZE_X 20
#define SIZE_Y 20
#define DEPTH 17

using namespace std;

struct E_field;
class TF1;

class electron {
public:
	electron();
	electron(double r1, double r2, double r3, double rad) { x=r1; y=r2; z=r3; PI_eq=rad; tau = lifetime();}
	electron& operator=(const electron&) { }
	void step(const vector<E_field>);
	int status() { return status_val; }
	double x, y, z;
	double dx, dy, dz;
	double v_xyz[3];
	const double m = 0.26 * 9.11e-31;
	const double q = 1.602e-19;
	double t = 0;
	double path = 0;
	ClassDef(electron,0)
	int cnt = 1;
	double lifetime();
	
	//DEBUG
    double vd_z;
	double vth_z;

private:
	int status_val = 0;	
	double beta = 4.1e-16;
	double PI_eq = 5e13;
	double tau = 0;
	double collision_time();
	double time_eff();
	double D_n();
	void rebound();
	bool In_anode();
	double v_th();
	bool trap();
	double mobility();
	void v_drift(double*, const vector<E_field>);
	double v_diff();
};
#endif
