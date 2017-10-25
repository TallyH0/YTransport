TGraph2D *grx = new TGraph2D();
TGraph2D *gry = new TGraph2D();
TGraph2D *grz = new TGraph2D();

void test_drift()
{
    gROOT->LoadMacro("v_drift.cc");

	TCanvas *c1 = new TCanvas("c1","",1800,600);
	c1->Divide(3,1);

	double z_val = 15;
	double vdx, vdy, vdz;
    Efield E_field[105540];
	ReadE(E_field);
}
