#include "TF1.h"
#include "TList.h"
#include "TPolyMarker3D.h"
#include <vector>

void TrTest()
{
    gSystem->Load("YTransport.so");
	YTransport* sim = new YTransport();
	sim->initialize();
	sim->print();
}
