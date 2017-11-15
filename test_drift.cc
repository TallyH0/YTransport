#include <iostream>
#include <cmath>

#define SIZE_X 20
#define SIZE_Y 20
#define DEPTH 17

TF1 * fdist = new TF1("fdist","x * x * TMath::Exp(0.26*-9.11e-31*x*x/(2*1.38064852e-23*300))",0,1e6);

TGraph2D *grx = new TGraph2D();
TGraph2D *gry = new TGraph2D();
TGraph2D *grz = new TGraph2D();
TGraph *gMu = new TGraph();
TGraph* movez = new TGraph();
TGraph* moveVth = new TGraph();
TGraph* moveVz = new TGraph();
TGraph* moveEz = new TGraph();
TGraph* VvsE = new TGraph();

TH1D* dx = new TH1D("dx","",100,0,0.22);
TH1D* dy = new TH1D("dy","",100,0,0.22);
TH1D* dz = new TH1D("dz","",100,0,0.3);

using namespace std;
struct Efield;

void nearpoint(int, Efield*);
void rebound(double, double, double);

void test_drift()
{

	int step = 2e3;
    gROOT->LoadMacro("v_drift.cc");
    Efield field[105541];
	ReadE(field);
	double x = 0;
	double y = 0;
	double z = 9;
	double t = 0;
	double v_xyz[3];
	double E = 0;
	double tau;
	double theta, phi;
	double thermal_x, thermal_y, thermal_z, dl;
	double rand_test = 0;
	
	for(int i = 0; i < step; ++i)
	{
	    tau = collision_time(z);
	    E = interpolate(x, y, z, field, v_xyz);
	    theta = 2 * TMath::Pi() * gRandom->Rndm();
	    phi = 2 * TMath::Pi() * gRandom->Rndm();

		dl = fdist->GetRandom() * tau * 1e6;
	    thermal_x =dl * cos(theta) * sin(phi);
	    thermal_y =dl * sin(theta) * sin(phi);
	    thermal_z =dl * cos(phi);
		rand_test += thermal_z;

	    z -= v_xyz[2] * tau * 1e6 + thermal_z;
		movez->SetPoint(i,t,z);
		moveVz->SetPoint(i,t,v_xyz[2]*1e6);
		moveVth->SetPoint(i,t,v_th());
		moveEz->SetPoint(i,t,E);
		
	    x -= v_xyz[0] * tau * 1e6 + thermal_x;
	    y -= v_xyz[1] * tau * 1e6 + thermal_y;
		t += tau;
		rebound(x, y, z);
		if( z< 1){
		    movez->RemovePoint(i);
		    moveVz->RemovePoint(i);
		    moveEz->RemovePoint(i);
		    moveVth->RemovePoint(i);
		    break;
		}
	}
	cout << i << endl;
	cout << rand_test << endl;

	double* Time = movez->GetX();
	double* Vz = moveVz->GetY();
	double* Z = movez->GetY();
	ofstream ofs ("Drift_debug.txt");
	for(int j = 1; j < i; ++j)
	{
	    ofs << Vz[j] * (Time[j] - Time[j-1]) << " = " << Z[j-1] - Z[j] << '\n';
	}
    ofs.close();	
	
	/*
	int cnt = 0;
	for(double i = 1e1; i < 1e5; i += (1e5-1e1)/step)
	{
	    VvsE->SetPoint(cnt, i, V_d(i));
		cnt++;
	}
	cout << cnt << endl;
	*/
}
void nearpoint(int step, Efield* field)
{
    double i, j, k; 
	int n;
	for(int p = 0; p < step; ++p)
	{
	    i = 20 * gRandom->Rndm() - 10;
	    j = 20 * gRandom->Rndm() - 10;
		k = 17 * gRandom->Rndm();
	    n = first_index(i, j, k, field);
		if(fabs(i - field[n].x) > 0.4375/2){
		    printf("*X*\nINDEX : %d\nINPUT(%lf, %lf, %lf)\nOUTPUT(%lf, %lf, %lf)\n",n,i,j,k,field[n].x,field[n].y,field[n].z);
			printf("%lf > %lf\n\n", 0.4375/2, fabs(i - field[n].x));
		}
		if(fabs(j - field[n].y) > 0.4375/2){
		    printf("*Y*\nINDEX : %d\nINPUT(%lf, %lf, %lf)\nOUTPUT(%lf, %lf, %lf)\n",n,i,j,k,field[n].x,field[n].y,field[n].z);
			printf("%lf > %lf\n\n", 0.4375/2, fabs(i - field[n].y));
		}
		if(fabs(k - field[n].z) > 0.25){
		    printf("*Z*\nINDEX : %d\nINPUT(%lf, %lf, %lf)\nOUTPUT(%lf, %lf, %lf)\n",n,i,j,k,field[n].x,field[n].y,field[n].z);
			printf("%lf > %lf\n\n", 0.25, i - fabs(field[n].z));
		}
		dx->Fill(fabs(i-field[n].x));
		dy->Fill(fabs(j-field[n].y));
		dz->Fill(fabs(k-field[n].z));
    }
}
double V_d(double E)
{
    double v_z = mobility(9) * E; 
    double v_sat = 2.4e7 / (1+ 0.8 * TMath::Exp(T/600));
	return v_z/(1+v_z/v_sat);
}
void rebound(double x, double y, double z)
{
	while(z < 0 || z > DEPTH){
	    if(z > DEPTH) z = 2 * DEPTH - z;
		else if(z < 0) z++;
	}
	while(x > SIZE_X/2 || x < -SIZE_X/2){
	if(x > SIZE_X/2) x = SIZE_X - x;
	else if(x < -SIZE_X/2) x = -SIZE_X - x;
	}
	while(y > SIZE_Y/2 || y < -SIZE_Y/2){
	if(y > SIZE_Y/2) y = SIZE_Y -y;
	else if(y < -SIZE_Y/2) y = -SIZE_Y - y;
	}
}
