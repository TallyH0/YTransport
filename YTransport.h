#ifndef YTRANSPORT_H
#define YTRANSPORT_H

#include "TFile.h"
#include "TKey.h"
#include "TRandom.h"
#include "TH1.h"
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
#include "Damage.h"
#include "PartIncidence.h"
#include "Temperature.h"

#define RAD_DAMAGE 5e12
#define bin_x 50
#define bin_y 50
#define bin_z 15

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


	TH1F* dz100 = new TH1F("dz100","",100,-10,10);
	TH3F* hfieldx1 = new TH3F("hfieldx1","",bin_x,-10,10,bin_y,-10,10,bin_z,0,2.5);
	TH3F* hfieldy1 = new TH3F("hfieldy1","",bin_x,-10,10,bin_y,-10,10,bin_z,0,2.5);
	TH3F* hfieldz1 = new TH3F("hfieldz1","",bin_x,-10,10,bin_y,-10,10,bin_z,0,2.5);
	TH3F* hfieldx2 = new TH3F("hfieldx2","",bin_x,-10,10,bin_y,-10,10,bin_z,1.5,17.5);
	TH3F* hfieldy2 = new TH3F("hfieldy2","",bin_x,-10,10,bin_y,-10,10,bin_z,1.5,17.5);
	TH3F* hfieldz2 = new TH3F("hfieldz2","",bin_x,-10,10,bin_y,-10,10,bin_z,1.5,17.5);
	TH3F* hfieldx3 = new TH3F("hfieldx3","",bin_x,-10,10,bin_y,-10,10,bin_z,16.5,19);
	TH3F* hfieldy3 = new TH3F("hfieldy3","",bin_x,-10,10,bin_y,-10,10,bin_z,16.5,19);
	TH3F* hfieldz3 = new TH3F("hfieldz3","",bin_x,-10,10,bin_y,-10,10,bin_z,16.5,19);
	TH1D* htime = new TH1D("htime","collection time",100,1e-13,1e-7);
	
	TPolyLine3D cube;
	TPolyMarker3D partgen;
	TPolyMarker3D pm3d[100];
	TH1D* hvd = new TH1D("hvd","Drift dz",100,-0.01,0.05);
	TH1F* hvthx = new TH1F("hvthx","Thermal dx",100,-0.3,0.3);
	TH1F* hvthy = new TH1F("hvthy","Thermal dy",100,-0.3,0.3);
	TH1F* hvthz = new TH1F("hvthz","Thermal dz",100,-0.3,0.3);
	TH1F* hvthl = new TH1F("hvthl","Thermal dl",100,-0.01,0.25);
    TGraph Z_plot[1000];
	vector<vector<double>> vth_dx;
	vector<vector<double>> vth_dy;
	vector<vector<double>> vth_dz;
	vector<vector<double>> vth_dl;
	
	
	void initialize(int);
	void initialize(char* ,int);
	void transport();
	void event(int);
	void print();
	void save(char*, int);
	void load(string&);
	void debug(int n);
};
#endif
