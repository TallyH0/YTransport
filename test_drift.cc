#include <iostream>
#include <cmath>

TGraph2D *grx = new TGraph2D();
TGraph2D *gry = new TGraph2D();
TGraph2D *grz = new TGraph2D();
TGraph *gMu = new TGraph();
TGraph* movez = new TGraph();

TH1D* dx = new TH1D("dx","",100,0,1);
TH1D* dy = new TH1D("dy","",100,0,1);
TH1D* dz = new TH1D("dz","",100,0,1);

using namespace std;

void nearpoint();

void test_drift()
{

	int step = 1000;
    gROOT->LoadMacro("v_drift.cc");
    Efield field[105541];
	ReadE(field);
	double x = 0;
	double y = 0;
	double z = 9;
	double t = 0;
	double v_xyz[3];

	for(int i = 0; i < step; ++i)
	{
	    interpolate(x, y, z, field, v_xyz);
		double tau = collision_time(z) * 1e5;
	    z -= v_xyz[2] * tau * 1e6;
		movez->SetPoint(i,t,z);
	    x -= v_xyz[0] * tau * 1e6;
	    y -= v_xyz[1] * tau * 1e6;
		t += tau;
		if( z< 1) break;
	}
}
void nearpoint()
{
    double i, j, k; 
	for(int p = 0; p < step; ++p)
	{
	    i = 20 * gRandom->Rndm() - 10;
	    j = 20 * gRandom->Rndm() - 10;
		k = 17 * gRandom->Rndm();
	    int n = first_index(i, j, k, field);
		if(fabs(i - field[n].x) > 0.4375)
		    printf("*X*\nINDEX : %d\nINPUT(%lf, %lf, %lf)\nOUTPUT(%lf, %lf, %lf)\n\n",n,i,j,k,field[n].x,field[n].y,field[n].z);
		if(fabs(j - field[n].y) > 0.4375)
		    printf("*Y*\nINDEX : %d\nINPUT(%lf, %lf, %lf)\nOUTPUT(%lf, %lf, %lf)\n\n",n,i,j,k,field[n].x,field[n].y,field[n].z);
		if(fabs(k - field[n].z) > 0.5)
		    printf("*Z*\nINDEX : %d\nINPUT(%lf, %lf, %lf)\nOUTPUT(%lf, %lf, %lf)\n\n",n,i,j,k,field[n].x,field[n].y,field[n].z);
		dx->Fill(fabs(i-field[n].x));
		dy->Fill(fabs(j-field[n].y));
		dz->Fill(fabs(k-field[n].z));
    }
}
