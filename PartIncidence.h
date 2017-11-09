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

using namespace std;

#define pi TMath::Pi()
#define sqrt TMath::Sqrt
#define cos TMath::Cos
#define abs TMath::Abs
#define SIZE_X 20
#define SIZE_Y 20
#define SIZE_Z 17
#define GEN_PER_UM 80

class PartIncidence
{
public:
    PartIncidence();
	virtual ~PartIncidence() {}
	ClassDef(PartIncidence,0);
	void generation();
    void initialize();
    vector<vector<double>> pos_carrier;

private:
    short dir = 0;
    double direction[3];
	double position_in[3];
	double position_out[3];
};

#endif
