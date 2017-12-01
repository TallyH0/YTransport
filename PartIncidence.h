#ifndef PARTINCIDENCE_H
#define PARTINCIDENCE_H

#include "TVector.h"
#include "TRandom.h"
#include "TMath.h"
#include "TF1.h"
#include "TGraph.h"
#include "TPolyMarker3D.h"
#include "TPolyLine3D.h"
#include <cstdlib> 
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pi TMath::Pi()
#define sqrt TMath::Sqrt
#define cos TMath::Cos
#define sin TMath::Sin
#define abs TMath::Abs
#define SIZE_X 100
#define SIZE_Y 100
#define DEPTH 17
#define RAND() (double)rand()/RAND_MAX
#define GEN_PER 80

class PartIncidence
{
public:
    PartIncidence();
	virtual ~PartIncidence() {}
	ClassDef(PartIncidence,0);
	void generation();
    void initialize();
    void initialize(double, double, double);
    vector<vector<double>> pos_carrier;

private:
    double direction[3];
	double position_in[3];
	double position_out[3];
};

#endif
