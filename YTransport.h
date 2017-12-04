#ifndef YTRANSPORT_H
#define YTRANSPORT_H

#include "TFile.h"
#include "TKey.h"
#include "TRandom.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TList.h"
#include "TGraph.h"
#include "TCanvas.h"
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
#include "PartIncidence.h"

#define BIN_X 100
#define BIN_Y 100
#define BIN_Z 45

using namespace std;

class E_field;
class electron;
class YGeometry;

const double k = 1.38064852e-23;
const double T = 300;	
//const double T = 0;

class YTransport {
public:
    YTransport();
    virtual ~YTransport()
	{
    delete beam;
	delete hfieldx1;
	delete hfieldy1;
	delete hfieldz1;
	delete hfieldx2;
	delete hfieldy2;
	delete hfieldz2;
	delete hfieldx3;
	delete hfieldy3;
	delete hfieldz3;
	}
    ClassDef(YTransport,0)

	PartIncidence* beam = new PartIncidence();

	vector<E_field> Efield;
	vector<electron> elist;


	TH1F* dz1 = new TH1F("dz1","After 10^{2} step",100,-10,10);
	TH1F* dz2 = new TH1F("dz2","After 10^{3} step",100,-10,10);
	TH1F* dz3 = new TH1F("dz3","After 2 X 10^{4} step",100,-10,10);
	TH1F* dz4 = new TH1F("dz4","After 3 X 10^{5} step",100,-10,10);
	
	TH3F* hfieldx1 = new TH3F("hfieldx1","",BIN_X,-10.5,10.5,BIN_Y,-10.5,10.5,BIN_Z,0,2.5);
	TH3F* hfieldy1 = new TH3F("hfieldy1","",BIN_X,-10.5,10.5,BIN_Y,-10.5,10.5,BIN_Z,0,2.5);
	TH3F* hfieldz1 = new TH3F("hfieldz1","",BIN_X,-10.5,10.5,BIN_Y,-10.5,10.5,BIN_Z,0,2.5);
	TH3F* hfieldx2 = new TH3F("hfieldx2","",BIN_X,-10.5,10.5,BIN_Y,-10.5,10.5,BIN_Z,1.5,17.5);
	TH3F* hfieldy2 = new TH3F("hfieldy2","",BIN_X,-10.5,10.5,BIN_Y,-10.5,10.5,BIN_Z,1.5,17.5);
	TH3F* hfieldz2 = new TH3F("hfieldz2","",BIN_X,-10.5,10.5,BIN_Y,-10.5,10.5,BIN_Z,1.5,17.5);
	TH3F* hfieldx3 = new TH3F("hfieldx3","",BIN_X,-10.5,10.5,BIN_Y,-10.5,10.5,BIN_Z,16.5,19);
	TH3F* hfieldy3 = new TH3F("hfieldy3","",BIN_X,-10.5,10.5,BIN_Y,-10.5,10.5,BIN_Z,16.5,19);
	TH3F* hfieldz3 = new TH3F("hfieldz3","",BIN_X,-10.5,10.5,BIN_Y,-10.5,10.5,BIN_Z,16.5,19);
	TH1D* htime = new TH1D("htime","collection time",100,0,2e-7);
	TH1D* hstep = new TH1D("hstep","step distribution",100,0,2e-8);
	TH1D* hstep_t = new TH1D("hstep_t","trap step distribution",100,0,2e-8);
	TH2D* hcluster = new TH2D("hcluster","cluster distribution",5,-2.5,2.5,5,-2,2.5);
	
	TH1D* hvd = new TH1D("hvd","Drift dz",100,-0.01,0.05);
	TH1F* hvthx = new TH1F("hvthx","Thermal dx",100,-0.3,0.3);
	TH1F* hvthy = new TH1F("hvthy","Thermal dy",100,-0.3,0.3);
	TH1F* hvthz = new TH1F("hvthz","Thermal dz",100,-0.3,0.3);
	TH1F* hvthl = new TH1F("hvthl","Thermal dl",100,-0.01,0.25);
	TH1F* hVdz = new TH1F("hVdz","Drift Velocity distribution",100,1e2,1e5);
	vector<vector<double>> carrier_dx;
	vector<vector<double>> carrier_dy;
	vector<vector<double>> carrier_dz;
	vector<vector<double>> carrier_dl;
	
	
	void init_fixed(char*, int, double);
	void init_beam(char*,double, double, double, double);
	void makefield(const char* fname);
	void loadfield(const char* fname);
	void transport(int);
	void event(int, int);
	void print();
	void save(char*, int);
	void load(string&);
	void hist_save(char* fname, TObject*);
	void debug(int n);
};
#endif
