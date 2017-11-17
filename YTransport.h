#ifndef YTRANSPORT_H
#define YTRANSPORT_H

#include "TRandom.h"
#include "TH1.h"
#include "TList.h"
#include "TGraph.h"
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

#define RAD_DAMAGE 5e12

using namespace std;

class E_field;
class electron;
class YGeometry;

const double k = 1.38064852e-23;
//const double T = 300;	
const double T = 0;

class YTransport {
public:
    YTransport();
    virtual ~YTransport() {delete beam;}
    ClassDef(YTransport,0)

	PartIncidence* beam = new PartIncidence();

	vector<E_field> Efield;
	vector<electron> elist;

	TPolyLine3D cube;
	TGraph Zdebug;
	TPolyMarker3D partgen;
	TPolyMarker3D pm3d[100];
	TH1D* htime = new TH1D("htime","collection time",1000,1e-12,1e-8);
	TH1D* hvd = new TH1D("hvd","Drift dz",100,-0.01,0.05);
	TH1D* hvth = new TH1D("hvth","Thermal dz",100,-0.3,0.3);
	
	void initialize();
	void transport();
	void event(int);
	void print();
	void save(string&);
	void load(string&);
	void debug();
};
#endif
