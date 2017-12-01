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

#define SIZE_X 100
#define SIZE_Y 100
#define DEPTH 17
#define MAX_TRACKING_TIME 1e-7
#define CONST_TAU 4.17522492152838888e-13

using namespace std;

struct E_field;
class TF1;

class electron {
public:
	ClassDef(electron,0)
	electron();
	electron(double r1, double r2, double r3, double rad) { x=r1; y=r2; z=r3; PI_eq=rad; tau = lifetime();}
	electron& operator=(const electron&) { }
	//void step(const vector<E_field>);
	void step(int, TH3F*, TH3F*, TH3F*,TH3F*, TH3F*, TH3F*, TH3F*, TH3F*, TH3F*);
	int status() { return status_val; }
	double x, y, z;
	double dx, dy, dz;
	double vd_xyz[3];
	const double m = 0.26 * 9.11e-31;
	const double q = 1.602e-19;
	double t = 0;
	double path = 0;
	int cnt = 1;
	double lifetime();
	double collision_time();
	unsigned int seed;
	int cluster_x, cluster_y;
	
	//DEBUG

	double path_dl;
	double Ez;
	double Vdz;

private:
	int status_val = 0;	
	double beta = 4.1e-16;
	double PI_eq;
	double tau = 0;
	double time_eff();
	double D_n();
	void rebound();
	bool In_anode();
	double v_th();
	bool trap();
	double mobility();
	//void v_drift(double*, const vector<E_field>);
	void v_drift(double*, TH3F*, TH3F*, TH3F*,TH3F*, TH3F*, TH3F*, TH3F*, TH3F*, TH3F*);
};
#endif
