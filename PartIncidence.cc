#include "PartIncidence.h"

ClassImp(PartIncidence);
PartIncidence::PartIncidence()
{
}
void PartIncidence::initialize(double x, double y, double angle_z)
{
    srand(unsigned(time(NULL)));
	double phi = RAND();
    direction[2] = -cos(angle_z/180*pi); 
	if(RAND() > 0.5)
    direction[1] = sqrt(1 - direction[2]*direction[2]) * cos(phi); 
	else
    direction[1] = -sqrt(1 - direction[2]*direction[2]) * cos(phi); 
	if(RAND() > 0.5)
	direction[0] = sqrt(1 - direction[2]*direction[2] - direction[1]*direction[1]); 
	else
	direction[0] = -sqrt(1 - direction[2]*direction[2] - direction[1]*direction[1]); 

	printf("dir vector (%lf, %lf, %lf)\n", direction[0], direction[1], direction[2]);

	position_in[0] = x;
	position_in[1] = y;
	position_in[2] = 17;
    
	double d[3];
	if(direction[0] > 0) d[0] = (SIZE_X/2 - position_in[0]) / direction[0];
	else d[0] = (-SIZE_X/2 - position_in[0]) / direction[0];
	if(direction[1] > 0) d[1] = (SIZE_Y/2 - position_in[1]) / direction[1];
	else d[1] = (-SIZE_Y/2 - position_in[1]) / direction[1];
	d[2] = abs(16/direction[2]);
    sort(d,d+3);

	for(int j=0; j<3; ++j)
	{
	    position_out[j] = position_in[j] + d[0] * direction[j];
	}
	printf("IN : %lf %lf %lf\nOUT : %lf %lf %lf\n", position_in[0], position_in[1], position_in[2], position_out[0], position_out[1], position_out[2]);
}
void PartIncidence::initialize()
{
    srand(unsigned(time(NULL)));
	double phi = RAND();
    direction[2] = -cos(15/180*pi) * RAND(); 
	if(RAND() > 0.5)
    direction[1] = sqrt(1 - direction[2]*direction[2]) * cos(phi); 
	else
    direction[1] = -sqrt(1 - direction[2]*direction[2]) * cos(phi); 
	if(RAND() > 0.5)
	direction[0] = sqrt(1 - direction[2]*direction[2] - direction[1]*direction[1]); 
	else
	direction[0] = -sqrt(1 - direction[2]*direction[2] - direction[1]*direction[1]); 

	position_in[0] = SIZE_X * RAND() - SIZE_X/2;
	position_in[1] = SIZE_Y * RAND() - SIZE_Y/2;
	position_in[2] = 17;
    
	double d[3];
	if(direction[0] > 0) d[0] = (SIZE_X/2 - position_in[0]) / direction[0];
	else d[0] = (-SIZE_X/2 - position_in[0]) / direction[0];
	if(direction[1] > 0) d[1] = (SIZE_Y/2 - position_in[1]) / direction[1];
	else d[1] = (-SIZE_Y/2 - position_in[1]) / direction[1];
	d[2] = abs(16/direction[2]);
    sort(d,d+3);

	for(int j=0; j<3; ++j)
	{
	    position_out[j] = position_in[j] + d[0] * direction[j];
	}
	printf("IN : %lf %lf %lf\nOUT : %lf %lf %lf\n", position_in[0], position_in[1], position_in[2], position_out[0], position_out[1], position_out[2]);
}
void PartIncidence::generation()
{
	printf("Generation starts\n");

	vector<double> x;
	vector<double> y;
	vector<double> z;
	double length = sqrt(TMath::Power(position_in[0]-position_out[0], 2) + TMath::Power(position_in[1]-position_out[1], 2) + TMath::Power(position_in[2]-position_out[2], 2));
	double rnd;

    TF1* pdist = new TF1("pdist","TMath::Poisson(x,[0])",0,2000);
	pdist->SetParameter(0, (int)(GEN_PER * length));
    int tot_gen = (int) pdist->GetRandom();
	delete pdist;

	for(int i = 0; i < tot_gen; ++i)
	{
	    rnd = gRandom->Rndm();
	    x.push_back(position_in[0] + rnd * (position_out[0] - position_in[0]));
	    y.push_back(position_in[1] + rnd * (position_out[1] - position_in[1]));
	    z.push_back(position_in[2] + rnd * (position_out[2] - position_in[2]));
	}
	pos_carrier.push_back(x);
	pos_carrier.push_back(y);
	pos_carrier.push_back(z);
	printf("# of carrier : %d\n", pos_carrier[0].size());
}
