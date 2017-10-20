#ifndef YTRANSPORT_H
#define YTRANSPORT_H

#include "TRandom.h"

#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "electron.h"
#include "E_field.h"
#include "Doping.h"
#include "Geometry.h"
#include "Damage.h"
#include "PartIncidence.h"
#include "Temperature.h"

#define SIZE_X 160
#define SIZE_Y 160
#define DEPTH 17

using namespace std;

struct doping_value;
class E_field;
class electron;
class YGeometry;

const double k = 1.38064852e-23;
const double T = 273.15;	
double mobility(double, double, double);
double v_th(double);

class YTransport {


public:
   YTransport();
   virtual ~YTransport() {}
   ClassDef(YTransport,0)


	YGeometry *Geometry;
	YDamage Damage;
	YPartIncidence Incidence;

	vector<E_field> Efield;
	vector<electron> elist;
	
	void initialize(int);
	void transport();
	void event(int);
	void print();
	void summary();	
	double v_thermal(double);


};
#endif
