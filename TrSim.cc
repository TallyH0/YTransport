#include "TF1.h"
int TrSim()
{
    gSystem->Load("YTransport.so");

	YTransport Sim;
	Sim.initialize(10000000);
	Sim.transport();
	Sim.print();

	return 0;
}
