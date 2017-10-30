#include "YTransport.h"

ClassImp(YTransport)

YTransport::YTransport()
{
}

double mobility(double x, double y, double z)
{
	static double const m_max = 470.5;
	static double const m_min = 44.9;
	static double const N_r = 2.23e17;
	static double const alpha = 0.719;

	return m_min + (m_max - m_min) / (1 + pow(doping(x, y, z)/N_r , alpha));
}
void YTransport::initialize(int n)
{
	ReadData(Efield);
	srand(unsigned(time(NULL)));
	for(int i = 0; i < n; ++i)
	{
	    electron tmp(0, 0, 15, 5e12);
		elist.push_back(tmp);	
	}
}
void YTransport::transport()
{
	time_t first, second;
	time(&first);
	for(int i = 0; i < elist.size(); ++i)
	{
		while(!elist[i].status()){
			event(i);
		}
	}
	time(&second);
	printf("Simulation takes %lf seconds\n", difftime(second, first));
}
void YTransport::event(int i)
{
	elist[i].step(Efield);
}
void YTransport::print()
{
    int cnt = 0;
	int cnt_trap = 0;
	for(int i = 0; i < elist.size(); ++i)
	{
		if(elist[i].status() == 2) cnt++;
		else if(elist[i].status() == -1) cnt_trap++;
	//	printf("electron[%d] time : %e\n", i, elist[i].t);
	//	printf("electron status : %d\n", elist[i].status());
	}
	printf("Total status(2) = %d\n", cnt);
	printf("Total status(-1) = %d\n", cnt_trap);
}

