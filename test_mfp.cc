TF1 *f1 = new TF1("f1","-1 * TMath::Log(1-x)",0,1);
TH1D *h1 = new TH1D("h1","h1",100,-0.001,0.02);
TH1D *hR = new TH1D("hR","hR",100,-0.5,1.5);
TGraph *gr = new TGraph();
void test_mfp()
{
    double x0 = 20;
	double x1 = 0;
	double mfp = 20;
	double del_x;
	
	double t, t0;
	int cnt = 0;
	while(x1<20)
	{
	   t = distribution(gRandom->Rndm());
	   t0 = (x0 - x1) * mfp;
	   del_x = (x0-x1) * t / t0;
	   gr->SetPoint(cnt, x1, del_x);
	   cnt++;
	   if(t < t0) x1 += del_x;
	   else break;
	}
	gr->Draw();
}
double distribution(double x)
{
    return -1 * TMath::Log(1-x);
}

