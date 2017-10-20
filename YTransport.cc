#include "YTransport.h"

ClassImp(YTransport)

YTransport::YTransport()
{
}

double mobility(double x, double y, double z)
{
	static double const m_max = 1414;
	static double const m_min = 68.5;
	static double const N_r = 9.20e16;
	static double const alpha = 0.711;

	return m_min + (m_max - m_min) / (1 + pow(doping(x, y, z)/N_r , alpha));
}
double v_th(double m)
{
	return sqrt(3*k*T/m); 
}
double YTransport::v_thermal(double Temperature)
{
	return sqrt(3*k*Temperature/9.11e-31);
}
void YTransport::initialize(int n)
{
	ReadData(Efield);
	srand(unsigned(time(NULL)));
	electron tmp;
	for(int i = 0; i < n; ++i)
	{
		tmp.x = 0;
		tmp.y = 0;
		tmp.z = 15;
		elist.push_back(tmp);	
	}
}
void YTransport::transport()
{
	for(int i = 0; i < elist.size(); ++i)
	{
		while(!elist[i].status()){
			event(i);
		}
	}
}
void YTransport::event(int i)
{
	elist[i].step(Efield);
}
void YTransport::print()
{
	for(int i = 0; i < elist.size(); ++i)
	{
		printf("electron[%d] time : %e\n", i, elist[i].t);
		printf("electron status : %d\n", elist[i].status());
	}
}

