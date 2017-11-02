#ifndef YTRANSPORT_H
#define YTRANSPORT_H

#include "TRandom.h"
#include "TH1.h"
#include "TList.h"
#include "TPolyLine3D.h"
#include "TPolyMarker3D.h"

#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include "electron.h"
#include "E_field.h"
#include "Doping.h"
#include "Geometry.h"
#include "Damage.h"
#include "PartIncidence.h"
#include "Temperature.h"

using namespace std;

class E_field;
class electron;
class YGeometry;

const double k = 1.38064852e-23;
#ifdef DEBUG
const double T = 0;	
#else
const double T = 273.15;	
#endif

class YTransport {
public:
    YTransport();
    virtual ~YTransport() {}
    ClassDef(YTransport,0)

	YGeometry *Geometry;
	Damage damage;
	YPartIncidence Incidence;

	vector<E_field> Efield;
	vector<electron> elist;

	TPolyLine3D pos;
	TPolyLine3D dpos;
	TPolyMarker3D pm3d;
	
	void initialize(int);
	void transport();
	void event(int);
	void print();
	void save(string&);
	void load(string&);
};
#endif
