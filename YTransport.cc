#include "YTransport.h"

ClassImp(YTransport)

YTransport::YTransport()
{
}

double normrnd(double mean, double stdDev) {
    double u, v, s;
    do {
        u = ((double)rand()/(double)RAND_MAX) * 2.0 - 1.0;
        v = ((double)rand()/(double)RAND_MAX) * 2.0 - 1.0;
        s = u * u + v * v;
    } while (s >= 1 || s == 0);
    double mul = sqrt(-2.0 * log(s) / s);
    return mean + stdDev * u * mul;
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
	double mean = sqrt(3*k*T/m); 
	double stdDev = 50;
	return normrnd(mean, stdDev);
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

