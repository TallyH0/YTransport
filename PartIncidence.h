#ifndef PARTINCIDENCE_H
#define PARTINCIDENCE_H

#include "TVector.h"
#include "TRandom.h"
#include "TMath.h"
#include <iostream>

using namespace std;

#define pi TMath::Pi()
#define sqrt TMath::Sqrt
#define cos TMath::Cos
#define SIZE_X 20
#define SIZE_Y 20
#define SIZE_Z 17

class PartIncidence
{
public:
    PartIncidence();
	virtual ~PartIncidence() {}
	ClassDef(PartIncidence,0);
    void initialize();
    double direction[3];
	double position_in[3];
	double position_out[3];
private:
};

#endif
