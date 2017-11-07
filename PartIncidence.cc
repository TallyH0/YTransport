#include "PartIncidence.h"

ClassImp(PartIncidence);
PartIncidence::PartIncidence()
{
    initialize();
}
void PartIncidence::initialize()
{
    direction[2] = gRandom->Rndm(); 
	if(gRandom->Rndm() > 0.5)
    direction[1] = sqrt(1 - direction[2]*direction[2]) * gRandom->Rndm(); 
	else
    direction[1] = -sqrt(1 - direction[2]*direction[2]) * gRandom->Rndm(); 
	if(gRandom->Rndm() > 0.5)
	direction[0] = sqrt(1 - direction[2]*direction[2] - direction[1]*direction[1]); 
	else
	direction[0] = -sqrt(1 - direction[2]*direction[2] - direction[1]*direction[1]); 

	position_in[0] = SIZE_X * gRandom->Rndm() - SIZE_X/2;
	position_in[1] = SIZE_Y * gRandom->Rndm() - SIZE_Y/2;
	position_in[2] = 17;
    
	double d[3];
	if(direction[0] > 0) d[0] = (SIZE_X/2 - position_in[0]) / direction[0];
	else d[0] = (-SIZE_X/2 - position_in[0]) / direction[0];
	if(direction[1] > 0) d[1] = (SIZE_Y/2 - position_in[1]) / direction[1];
	else d[1] = (-SIZE_Y/2 - position_in[1]) / direction[1];
	d[2] = 16/direction[2];
    
	int i=0;
	int tmp=0;
	for(k = 0; k < 2; ++k)
	{
		if(d[k] > d[k+1]) tmp = k+1;
		i = tmp;
	}
	printf("%lf %lf %lf\n", d[0], d[1], d[2]);
	for(int j=0; j<3; ++j)
	{
	    position_out[j] = position_in[j] + d[i] * direction[j];
		if(j==2)
	        position_out[2] = position_in[2] - d[i] * direction[2];
		printf("%lf\n", position_out[j]);
	}
}
