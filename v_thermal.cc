
TH1F *h1 = new TH1F("h1","h1",100,0,1000);
//TF1 *f1 = new TF1("f1","TMath::Sqrt(TMath::Power([0]/(2*TMath::Pi()),3)) * 4 * TMath::Pi() * x * x * TMath::Exp(-[0]*x*x/2)",0,1e5);
TF1 *f2 = new TF1("f2","TMath::Sqrt(TMath::Power([0]/(2*TMath::Pi()),3)) * 4 * TMath::Pi() * x * x * x * x * TMath::Exp(-[0]*x*x/2)",0,1e5);
TF1 *f1 = new TF1("f1","x * x * TMath::Exp(-[0]*x*x/2)",0,1e6);
void v_thermal(double* v_xyz)
{
	double T = 273;
	double m = 9.11e-31;
	double para1 = m/(TMath::K()*T);
	f1->SetParameter(0,para1);
	f2->SetParameter(0,para1);
	printf("v = %lf, v_p = %lf\n", f1->GetMaximumX(0,1e7), TMath::Sqrt(2/para1));
    f1->SetFillColor(19);
    f1->SetFillStyle(0);
    f1->SetMarkerStyle(20);
    f1->SetMarkerSize(0.5);
    f1->SetLineColor(2);
    f1->SetLineWidth(2);
    f1->GetXaxis()->SetTitle("v_{thermal}(m/s)");
    f1->GetXaxis()->SetLabelFont(42);
    f1->GetXaxis()->SetLabelSize(0.035);
    f1->GetXaxis()->SetTitleSize(0.06);
    f1->GetXaxis()->SetTitleOffset(0.77);
    f1->GetXaxis()->SetTitleFont(42);
    f1->GetYaxis()->SetTitle("PDF");
    f1->GetYaxis()->SetLabelFont(42);
    f1->GetYaxis()->SetLabelSize(0.035);
    f1->GetYaxis()->SetTitleSize(0.06);
    f1->GetYaxis()->SetTitleOffset(0.8);
    f1->GetYaxis()->SetTitleFont(42);
    gStyle->SetOptStat(1);
    gStyle->SetOptTitle(0);
	double v = f1->GetRandom();

	double phi = 2 * TMath::Pi() * gRandom->Rndm();
	double cos = 2 * gRandom->Rndm() - 1;
	double sin = TMath::Sqrt(1 - cos);
	v_xyz[2] = v * cos;
	v_xyz[1] = v * sin * TMath::Sin(phi);
	v_xyz[0] = v * sin * TMath::Cos(phi);

}
