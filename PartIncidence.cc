#include "PartIncidence.h"

ClassImp(PartIncidence);
PartIncidence::PartIncidence()
{
}
void PartIncidence::initialize()
{
    direction[2] = cos(2 * pi * gRandom->Rndm()); 
    direction[1] = cos(2 * pi * gRandom->Rndm()); 
	if(gRandom->Rndm() > 0.5)
	direction[0] = cos(-(1 - sqrt(direction[2]*direction[2] - direction[1]*direction[1]))); 
	else
	direction[0] = cos(1 - sqrt(direction[2]*direction[2] - direction[1]*direction[1])); 
}
