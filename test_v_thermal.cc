#include <iostream>

using namespace std;


TH1D *time = new TH1D("time","time",1000,1e-10,1e-9);
TH1D *hvth = new TH1D("hvth","V_{thermal}",10000,-1.2e5,1.2e5);

int test_v_thermal()
{
	
	gROOT->LoadMacro("v_thermal.cc");
	int n = 100000;
	double v_xyz[3];

    double phi = gRandom->Rndm();
	double theta = gRandom->Rndm();
	double x, y, z;
	for(int i = 0; i < n; ++i)
	{
        phi = 2 * TMath::Pi() * gRandom->Rndm();
	    theta = 2 * TMath:: Pi() * gRandom->Rndm();
	    z = TMath::Cos(theta) * v_thermal_c;
		y = TMath::Sin(theta) * TMath::Sin(phi) * v_thermal_c;
		x = TMath::Sin(theta) * TMath::Cos(phi) * v_thermal_c;
		hvth->Fill(x + y + z);
	}
	hvth->Draw();

	return 0;
}
