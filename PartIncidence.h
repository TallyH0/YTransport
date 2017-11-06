#ifndef PARTINCIDENCE_H
#define PARTINCIDENCE_H

#include "TVector.h"
#include "TRandom.h"
#include "TMath.h"

#define pi TMath::Pi()
#define sqrt TMath::Sqrt
#define cos TMath::Cos

class PartIncidence
{
public:
    PartIncidence();
	virtual ~PartIncidence() {}
	ClassDef(PartIncidence,0);
    void initialize();
    double direction[3];
	double position[3];
private:
};

#endif
