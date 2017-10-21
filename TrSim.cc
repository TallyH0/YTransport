int TrSim()
{
    gSystem->Load("YTransport.so");

	YTransport Sim;
	Sim.initialize(1);
	Sim.transport();
	Sim.print();

	return 0;
}
