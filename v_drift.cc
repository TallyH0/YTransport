
TH1F *h1 = new TH1F("h1","h1",1000,0,1000);
//TF1 *f1 = new TF1("f1","TMath::Sqrt(TMath::Power([0]/(2*TMath::Pi()),3)) * 4 * TMath::Pi() * x * x * TMath::Exp(-[0]*x*x/2)",0,1000);
TF1 *f1 = new TF1("f1","x * x * TMath::Exp(-[0]*x*x/2)",0,1000);
void v_drift()
{
	gSystem->Load("YTransport.so");
	double T = 273;
	double m = 9.11e-31;
	double para1 = TMath::Sqrt(m/(TMath::K()*T));
	f1->GetRandom();
	f1->SetParameter(0,para1);
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
    f1->SetParameter(0,1.554662e-05);
    f1->SetParError(0,0);
    f1->SetParLimits(0,0,0);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
	h1->Draw();	
	f1->Draw("P");
}
