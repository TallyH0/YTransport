#include "TF1.h"
#include "TList.h"
#include "TPolyMarker3D.h"
#include <vector>
int TrSim()
{
    gSystem->Load("YTransport.so");

	YTransport *sim = new YTransport();
	sim->initialize();
	sim->transport();
	sim->print();
	sim->save("RESULT.txt");

	return 0;
}
