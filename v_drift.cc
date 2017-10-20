
TH1F *h1 = new TH1F("h1","h1",100,0,100);
TF1 *f1 = new TF1("f1","TMath::Sqrt(TMath::Power([0]/(2*TMath::Pi()),3)) * 4 * TMath::Pi() * x * x * TMath::Exp(-[0]*x*x/2)",0,1000);
void v_drift()
{
	gSystem->Load("YTransport.so");
	double T = 273;
	double m = 9.11e-31;
	double para1 = TMath::Sqrt(m/(TMath::K()*T));
	f1->GetRandom();
	f1->SetParameter(0,para1);

	for(int i = 0; i < 10000; i++)
	{
		h1->Fill(f1->GetRandom());
	}
	h1->Draw();	
	f1->Draw();
}
