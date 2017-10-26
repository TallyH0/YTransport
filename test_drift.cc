TGraph2D *grx = new TGraph2D();
TGraph2D *gry = new TGraph2D();
TGraph2D *grz = new TGraph2D();
TGraph *gMu = new TGraph();

void test_drift()
{

    gROOT->LoadMacro("v_drift.cc");
	double z_val = 15;
    Efield field[105541];
	ReadE(field);

	for(double j = 0; j <= 17; ++j)
	{
	    gMu->SetPoint(j,j,mobility(j));
	}

/*
	int cnt = 1;
	for(int i = 0; i < 105540; ++i)
	{
		grx->SetPoint(cnt, field[i].x, field[i].y, field[i].Ex);
	    gry->SetPoint(cnt, field[i].x, field[i].y, field[i].Ey);
	    grz->SetPoint(cnt, field[i].x, field[i].y, field[i].Ez);
		cnt++;
	}
*/
}
