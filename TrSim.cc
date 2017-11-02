#include "TF1.h"
#include "TPolyMarker3D.h"
#include "TList.h"
int TrSim()
{
    gSystem->Load("YTransport.so");

	YTransport Sim;
	Sim.initialize(100);
	Sim.transport();
	Sim.print();
	Sim.save("RESULT.txt");

	return 0;
}
