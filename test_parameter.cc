TGraph *gr = new TGraph();
TGraph *gr2 = new TGraph();
TF1 *vth = new TF1("vth","[1] * x * x * TMath::Exp(-[0]*x*x/2)",0,1e6);
TH1D* hdl = new TH1D("hdl","hdl",10000,1e-8,1e-5);
TH1D* hx = new TH1D("hx","hx",1000,-1e-7,1e-7);
TH1D* hy = new TH1D("hy","hy",1000,-1e-7,1e-7);
TH1D* hz = new TH1D("hz","hz",1000,-1e-7,1e-7);

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
double mobilityH(double);
double collision_time(double);
void draw_setting(TGraph* );
double v_th();
void random_sim(int,double, TH1D*, TH1D*, TH1D*);

void test_parameter()
{
    int step = 1e5;
	int cnt = 0;
	double doping = 1e12;
    vth->SetParameter(0,m/(k*T));
	vth->SetParameter(1,4*pi*sqrt(TMath::Power(m/(2*pi*k*T),3)));
    for(double i = 1e12; i < 1e20; i += (1e20-1e12)/step)
	{
	    gr->SetPoint(cnt,i,collision_time(i));
		cnt++;
	}
    draw_setting(gr);	
    draw_setting(gr2);	
	gr2->SetLineColor(kGreen);
	gr->SetLineColor(kRed);
}
double mobility(double doping)
{
    static double const Mu0 = 232;
    static double const Mu1 = 1180;
	static double const N_r = 8e16;
	static double const alpha = 0.9;

	return Mu0 + Mu1 / (1 + TMath::Power(doping/N_r , alpha));
}
double mobilityH(double doping)
{
    static double const Mu0 = 48;
    static double const Mu1 = 447;
	static double const N_r = 6.3e16;
	static double const alpha = 0.76;

	return Mu0 + Mu1 / (1 + TMath::Power(doping/N_r , alpha));
}
double collision_time(double doping)
{
	return 1e-4 * 2 * mobility(doping) * m / q;
} 
double v_th()
{
    return vth->GetRandom();
}
void draw_setting(TGraph* gr)
{
   gr->GetXaxis()->SetTitle("time (s)");
   gr->GetXaxis()->SetLabelFont(42);
   gr->GetXaxis()->SetLabelSize(0.035);
   gr->GetXaxis()->SetTitleSize(0.035);
   gr->GetXaxis()->SetTitleOffset(1.18);
   gr->GetXaxis()->SetTitleFont(42);
   gr->GetYaxis()->SetTitle("Mobility (cm^{2}/Vs)");
   gr->GetYaxis()->SetLabelFont(42);
   gr->GetYaxis()->SetLabelSize(0.035);
   gr->GetYaxis()->SetTitleSize(0.035);
   gr->GetYaxis()->SetTitleFont(42);
}
double random_sim(int step, double doping, TH1D* hx, TH1D* hy, TH1D* hz)
{
	for(int i = 0; i < step; ++i)
	{
	    double phi, theta;
		phi = 2 * pi * gRandom->Rndm();
		theta = 2 * pi * gRandom->Rndm();
		double t = collision_time(doping);
		double x = v_th() * sin(theta) * cos(phi) * t;
		double y = v_th() * sin(theta) * sin(phi) * t;
		double z = v_th() * cos(theta) * t;
		hx->Fill(x); hy->Fill(y); hz->Fill(z);
	}
}
