TH1D *hKE = new TH1D("hKE","Kinetic Energy",1000,0,1e-20);
TH1D *hVx = new TH1D("hVx","v_{x}",100,-1000,1000);
TH1D *hVz = new TH1D("hVz","v_{z}",100,-1000,1000);

void test()
{
    gROOT->LoadMacro("v_thermal.cc");
	double v_xyz[3];
	double KE;
	for(int i = 0; i < 10000000 ; ++i){
	    v_thermal(v_xyz);
		KE = 0.5 * m * (v_xyz[0]*v_xyz[0] + v_xyz[1]*v_xyz[1] + v_xyz[2] * v_xyz[2]);
		hKE->Fill(KE);
		hVx->Fill(v_xyz[0]);
		hVz->Fill(v_xyz[2]);
		//printf("KE = %e, V_x = %lf, V_z = %lf\n", KE, v_xyz[0], v_xyz[2]);

	}

}
