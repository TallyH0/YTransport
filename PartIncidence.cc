#include "PartIncidence.h"

TF1 *normdist = new TF1("normdist","1/sqrt(2*pi*81) * TMath::Exp(-TMath::Power(x-0.5,2)/(2*81))",0,1);
ClassImp(PartIncidence);
PartIncidence::PartIncidence()
{
}
void PartIncidence::initialize()
{
    srand(unsigned(time(NULL)));
    direction[2] = -(double)rand()/RAND_MAX; 
	if((double)rand()/RAND_MAX > 0.5)
    direction[1] = sqrt(1 - direction[2]*direction[2]) * (double)rand()/RAND_MAX; 
	else
    direction[1] = -sqrt(1 - direction[2]*direction[2]) * (double)rand()/RAND_MAX; 
	if((double)rand()/RAND_MAX > 0.5)
	direction[0] = sqrt(1 - direction[2]*direction[2] - direction[1]*direction[1]); 
	else
	direction[0] = -sqrt(1 - direction[2]*direction[2] - direction[1]*direction[1]); 

	position_in[0] = SIZE_X * (double)rand()/RAND_MAX - SIZE_X/2;
	position_in[1] = SIZE_Y * (double)rand()/RAND_MAX - SIZE_Y/2;
	position_in[2] = 17;
    
	double d[3];
	if(direction[0] > 0) d[0] = (SIZE_X/2 - position_in[0]) / direction[0];
	else d[0] = (-SIZE_X/2 - position_in[0]) / direction[0];
	if(direction[1] > 0) d[1] = (SIZE_Y/2 - position_in[1]) / direction[1];
	else d[1] = (-SIZE_Y/2 - position_in[1]) / direction[1];
	d[2] = abs(16/direction[2]);

    
	for(int k = 0; k < 2; ++k)
	{
		if(d[dir] > d[k+1]) dir = k+1;
	}
	double delta = d[dir];
	for(int j=0; j<3; ++j)
	{
	    position_out[j] = position_in[j] + delta * direction[j];
	}
	printf("IN : %lf %lf %lf\nOUT : %lf %lf %lf\n", position_in[0], position_in[1], position_in[2], position_out[0], position_out[1], position_out[2]);
}
void PartIncidence::generation()
{
	vector<double> x;
	vector<double> y;
	vector<double> z;
	double rnd;
	printf("Generation starts\n");
	if(dir!=2)
	    while(abs(position_in[dir]) < abs(position_out[dir]))
	    {
	        for(int j = 0; j < GEN_PER_UM; ++j)
		    {
			    //rnd = normdist->GetRandom();
			    rnd = gRandom->Rndm();
	            x.push_back(position_in[0] + rnd * direction[0]);
	            y.push_back(position_in[1] + rnd * direction[1]);
	            z.push_back(position_in[2] + rnd * direction[2]);
	        }
		    for(int k =0; k < 3; ++k)
		    {
		        position_in[k] += direction[k];
		    }
	    }
	else
	    while(abs(position_in[dir]) > abs(position_out[dir]))
	    {
	        for(int j = 0; j < GEN_PER_UM; ++j)
		    {
			    //rnd = normdist->GetRandom();
			    rnd = gRandom->Rndm();
	            x.push_back(position_in[0] + rnd * direction[0]);
	            y.push_back(position_in[1] + rnd * direction[1]);
	            z.push_back(position_in[2] + rnd * direction[2]);
	        }
		    for(int k =0; k < 3; ++k)
		    {
		        position_in[k] += direction[k];
		    }
	    }
	pos_carrier.push_back(x);
	pos_carrier.push_back(y);
	pos_carrier.push_back(z);
	printf("# of carrier : %d\n", pos_carrier[0].size());
}
