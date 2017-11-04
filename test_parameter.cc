TGraph *gr = new TGraph();
TF1 *vth = new TF1("vth","[1] * x * x * TMath::Exp(-[0]*x*x/2)",0,1e6);
TH1D* hdl = new TH1D("hdl","hdl",10000,1e-8,1e-6);

#define sin TMath::Sin
#define cos TMath::Cos
#define sqrt TMath::Sqrt
#define power TMath::Power

double q = 1.602e-19;
double m = 9.11e-31;
double T = 273;
double k = TMath::K();
double pi = TMath::Pi();

double mobility(double);
double collision_time(double);
double draw_setting(TGraph* );
double random_sim(int, double);

void test_parameter()
{
    int step = 10000;
	double doping = 1e12;
    vth->SetParameter(0,m/(k*T));
	vth->SetParameter(1,4*pi*sqrt(TMath::Power(m/(2*pi*k*T),3)));
}
double mobility(double doping)
{
	static double const m_max = 470.5;
	static double const m_min = 44.9;
	static double const N_r = 2.23e17;
	static double const alpha = 0.719;

	return m_min + (m_max - m_min) / (1 + TMath::Power(doping/N_r , alpha));
}
double collision_time(double doping)
{
	return 1e-4 * mobility(doping) * m / q;
} 
double v_th()
{
    return vth->GetRandom();
}
double draw_setting(TGraph* gr)
{
   gr->GetXaxis()->SetTitle("Doping Concentration(cm^{-3})");
   gr->GetXaxis()->SetLabelFont(42);
   gr->GetXaxis()->SetLabelSize(0.035);
   gr->GetXaxis()->SetTitleSize(0.035);
   gr->GetXaxis()->SetTitleOffset(1.18);
   gr->GetXaxis()->SetTitleFont(42);
   gr->GetYaxis()->SetTitle("Collision time(s)");
   gr->GetYaxis()->SetLabelFont(42);
   gr->GetYaxis()->SetLabelSize(0.035);
   gr->GetYaxis()->SetTitleSize(0.035);
   gr->GetYaxis()->SetTitleFont(42);
}
double random_sim(int step, double doping)
{
    double phi, theta;	
    double dx, dy, dz, v_avg;
	dx=dy=dz=0;
	for(int i=0; i<step; ++i)
	{
	    phi = 2 * pi * gRandom->Rndm();
		theta = 2 * pi * gRandom->Rndm();
	    v_avg = v_th();
	    //v_avg = sqrt(3*k*T/m);
        dx += v_avg * collision_time(doping) * sin(theta) * cos(phi);
        dy += v_avg * collision_time(doping) * sin(theta) * sin(phi);
        dz += v_avg * collision_time(doping) * cos(theta);
	}
	return sqrt(dx*dx + dy*dy + dz*dz);
}
