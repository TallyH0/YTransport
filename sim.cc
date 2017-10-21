/*
#include "YTransport.h"
#include <iostream>
#include <vector>
#include <fstream>
*/

//using namespace std;

TH1D *time = new TH1D("time","time",1000,1e-10,1e-9);
TH1D *hvth = new TH1D("hvth","V_{thermal}",100,250,350);

int sim()
{
	gSystem->Load("YTransport.so");
	
	YTransport Sim;
	Int_t n = 1000;
	Double_t X[1000];
	Double_t V_th[1000];

	for(int i = 0; i < n; ++i)
	{
		X[i] = i;
		V_th[i] = Sim.v_thermal(i) * 1e-3;
	}

	
	gr = new TGraph(n,X,V_th);
	hvth->SetMaximum(1.3e2);
	hvth->SetMinimum(1e2);
    hvth->GetXaxis()->SetLabelFont(42);
    hvth->GetXaxis()->SetLabelSize(0.035);
    hvth->GetXaxis()->SetTitleSize(0.035);
    hvth->GetXaxis()->SetTitleFont(42);
    hvth->GetYaxis()->SetLabelFont(42);
    hvth->GetYaxis()->SetLabelSize(0.035);
    hvth->GetYaxis()->SetTitleSize(0.035);
    hvth->GetYaxis()->SetTitleFont(42);
    hvth->GetXaxis()->SetTitle("Temperatrue (K)");
    hvth->GetXaxis()->CenterTitle(false);
    hvth->GetXaxis()->SetNdivisions(11005);
    hvth->GetXaxis()->SetLabelFont(42);
    hvth->GetXaxis()->SetLabelSize(0.035);
    hvth->GetXaxis()->SetTitleSize(0.06);
    hvth->GetXaxis()->SetTitleOffset(0.67);
    hvth->GetXaxis()->SetTitleFont(42);
    hvth->GetYaxis()->SetTitle("v_{thermal} (km/s)");
    hvth->GetYaxis()->CenterTitle(false);
    hvth->GetYaxis()->SetNdivisions(1005);
    hvth->GetYaxis()->SetLabelFont(42);
    hvth->GetYaxis()->SetLabelSize(0.035);
    hvth->GetYaxis()->SetTitleSize(0.06);
    hvth->GetYaxis()->SetTitleOffset(0.71);
    hvth->GetYaxis()->SetTitleFont(42);
    gr->SetMarkerStyle(20);
    gr->SetMarkerSize(0.5);
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	hvth->Draw();
	gr->Draw("P"); 

	return 0;
}
