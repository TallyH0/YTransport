{
//=========Macro generated from canvas: c1/c1
//=========  (Sat Oct 21 14:18:38 2017) by ROOT version5.34/36
   TCanvas *c1 = new TCanvas("c1", "c1",1,67,1743,892);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1->ToggleEventStatus();
   c1->Range(-125,-0.0003037397,1125,0.002733657);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TF1 *f1 = new TF1("f1","TMath::Sqrt(TMath::Power([0]/(2*TMath::Pi()),3))*4*TMath::Pi()*x*x*TMath::Exp(-[0]*x*x/2)",0,1000);
   f1->SetFillColor(19);
   f1->SetFillStyle(0);
   f1->SetMarkerStyle(20);
   f1->SetMarkerSize(0.5);
   f1->SetLineColor(2);
   f1->SetLineWidth(2);
   f1->GetXaxis()->SetTitle("v_thermal(m/s)");
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
   f1->Draw("P");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
   c1->ToggleToolBar();
}
