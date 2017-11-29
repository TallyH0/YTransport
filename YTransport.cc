#include "YTransport.h"

ClassImp(YTransport)
YTransport::YTransport()
{
}
void YTransport::makehistogram(const char* fname)
{
	ReadData(Efield);
	int x,y,z;
	double x_tr[3],y_tr[3],z_tr[3];
	double E1[3];
	double E2[3];
	double E3[3];
	time_t start, end;
	time(&start);
	for(x=1; x<=bin_x; ++x){
	    for(y=1; y<=bin_y; ++y){
		    for(z=1; z<=bin_z; ++z){
			    x_tr[0] = hfieldx1->GetXaxis()->GetBinCenter(x);
			    y_tr[0] = hfieldx1->GetYaxis()->GetBinCenter(y);
			    z_tr[0] = hfieldx1->GetZaxis()->GetBinCenter(z);
			    x_tr[1] = hfieldx2->GetXaxis()->GetBinCenter(x);
			    y_tr[1] = hfieldx2->GetYaxis()->GetBinCenter(y);
			    z_tr[1] = hfieldx2->GetZaxis()->GetBinCenter(z);
			    x_tr[2] = hfieldx3->GetXaxis()->GetBinCenter(x);
			    y_tr[2] = hfieldx3->GetYaxis()->GetBinCenter(y);
			    z_tr[2] = hfieldx3->GetZaxis()->GetBinCenter(z);
				interpolate(x_tr[0], y_tr[0], z_tr[0], Efield, E1);
				interpolate(x_tr[1], y_tr[1], z_tr[1], Efield, E2);
				interpolate(x_tr[2], y_tr[2], z_tr[2], Efield, E3);
			    hfieldx1->SetBinContent(x,y,z,E1[0]);
			    hfieldy1->SetBinContent(x,y,z,E1[1]);
			    hfieldz1->SetBinContent(x,y,z,E1[2]);
			    hfieldx2->SetBinContent(x,y,z,E2[0]);
			    hfieldy2->SetBinContent(x,y,z,E2[1]);
			    hfieldz2->SetBinContent(x,y,z,E2[2]);
			    hfieldx3->SetBinContent(x,y,z,E3[0]);
			    hfieldy3->SetBinContent(x,y,z,E3[1]);
			    hfieldz3->SetBinContent(x,y,z,E3[2]);
			}
			printf("bin# - x : %d, y : %d\n", x, y);
		}
	}
	time(&end);
	printf("hfield takes %lf seconds\n", difftime(end,start));
	Efield.clear();
	TFile* fout = new TFile(fname,"RECREATE");
	hfieldx1->Write();
	hfieldx2->Write();
	hfieldx3->Write();
	hfieldy1->Write();
	hfieldy2->Write();
	hfieldy3->Write();
	hfieldz1->Write();
	hfieldz2->Write();
	hfieldz3->Write();
	fout->Close();
}
void YTransport::initialize(char* fname, int n, double rad_flux)
{
	TFile* fin = new TFile(fname);
	hfieldx1 = (TH3F*)fin->Get("hfieldx1;1");
	hfieldx1->SetDirectory(0);
	hfieldx2 = (TH3F*)fin->Get("hfieldx2;1");
	hfieldx2->SetDirectory(0);
	hfieldx3 = (TH3F*)fin->Get("hfieldx3;1");
	hfieldx3->SetDirectory(0);
	hfieldy1 = (TH3F*)fin->Get("hfieldy1;1");
	hfieldy1->SetDirectory(0);
	hfieldy2 = (TH3F*)fin->Get("hfieldy2;1");
	hfieldy2->SetDirectory(0);
	hfieldy3 = (TH3F*)fin->Get("hfieldy3;1");
	hfieldy3->SetDirectory(0);
	hfieldz1 = (TH3F*)fin->Get("hfieldz1;1");
	hfieldz1->SetDirectory(0);
	hfieldz2 = (TH3F*)fin->Get("hfieldz2;1");
	hfieldz2->SetDirectory(0);
	hfieldz3 = (TH3F*)fin->Get("hfieldz3;1");
	hfieldz3->SetDirectory(0);
	fin->Close();
    delete fin;
	//beam->initialize();
	//beam->generation();
    
	electron tmp(0,0,9,rad_flux);
	//for(int i=0; i< beam->pos_carrier[0].size(); ++i)
	for(int i=0; i< n; ++i)
	{
	    //electron tmp(beam->pos_carrier[0][i], beam->pos_carrier[1][i], beam->pos_carrier[2][i], RAD_DAMAGE);
		elist.push_back(tmp);
#ifdef DEBUG
	    partgen.SetNextPoint(beam->pos_carrier[0][i], beam->pos_carrier[1][i], beam->pos_carrier[2][i]);
#endif
	}
}
void YTransport::initialize(int n)
{
#ifdef DEBUG
    cube.SetNextPoint(-SIZE_X, -SIZE_Y, 1);
    cube.SetNextPoint(SIZE_X, -SIZE_Y, 1);
    cube.SetNextPoint(SIZE_X, -SIZE_Y, SIZE_Z);
    cube.SetNextPoint(-SIZE_X, -SIZE_Y, SIZE_Z);
    cube.SetNextPoint(-SIZE_X, -SIZE_Y, 1);
    cube.SetNextPoint(-SIZE_X, SIZE_Y, 1);
    cube.SetNextPoint(SIZE_X, SIZE_Y, 1);
    cube.SetNextPoint(SIZE_X, -SIZE_Y, 1);
    cube.SetNextPoint(SIZE_X, -SIZE_Y, SIZE_Z);
    cube.SetNextPoint(-SIZE_X, -SIZE_Y, SIZE_Z);
    cube.SetNextPoint(-SIZE_X, SIZE_Y, SIZE_Z);
    cube.SetNextPoint(SIZE_X, SIZE_Y, SIZE_Z);
    cube.SetNextPoint(SIZE_X, -SIZE_Y, SIZE_Z);
    cube.SetNextPoint(SIZE_X, SIZE_Y, SIZE_Z);
    cube.SetNextPoint(SIZE_X, SIZE_Y, 1);
    cube.SetNextPoint(-SIZE_X, SIZE_Y, 1);
    cube.SetNextPoint(-SIZE_X, SIZE_Y, SIZE_Z);
#endif
			    
	//beam->initialize();
	//beam->generation();
    
	electron tmp(0,0,9,5e12);
	//for(int i=0; i< beam->pos_carrier[0].size(); ++i)
	for(int i=0; i< n; ++i)
	{
	    //electron tmp(beam->pos_carrier[0][i], beam->pos_carrier[1][i], beam->pos_carrier[2][i], RAD_DAMAGE);
		elist.push_back(tmp);
#ifdef DEBUG
	    partgen.SetNextPoint(beam->pos_carrier[0][i], beam->pos_carrier[1][i], beam->pos_carrier[2][i]);
#endif
	}
}
void YTransport::transport(int mode)
{
	time_t first, second;
	time(&first);
	int cnt=0;
	vector<double> dx;
	vector<double> dy;
	vector<double> dz;
	vector<double> dl;
	for(int i=0; i<elist.size(); ++i)
	{
	    cnt=0;
	    while(elist[i].status() == 0)
		{
		    event(mode, i);
			/*
			Z_plot[i].SetPoint(cnt,elist[i].t,elist[i].z);
            Ez_plot[i].SetPoint(cnt,elist[i].z,elist[i].Ez);
			Vz_plot[i].SetPoint(cnt,elist[i].z,elist[i].Vdz);
			++cnt;
			dx.push_back(elist[i].dx);
			dy.push_back(elist[i].dy);
			dz.push_back(elist[i].dz);
			dl.push_back(elist[i].path_dl);
			hVdz->Fill(elist[i].Vdz);
			if(elist[i].cnt == 100)
			    dz1->Fill(9-elist[i].z);
			else if(elist[i].cnt == 1000)
			    dz2->Fill(9-elist[i].z);
			else if(elist[i].cnt == 10000)
			    dz3->Fill(9-elist[i].z);
			else if(elist[i].cnt == 100000)
			    dz4->Fill(9-elist[i].z);
				*/
		}
		save("RESULT_diffusion_only.txt", i);
		cout << i + 1 << " electron done\n";
		
		/*
		carrier_dx.push_back(dx);
		carrier_dy.push_back(dy);
		carrier_dz.push_back(dz);
		carrier_dl.push_back(dl);
	    dx.clear();
		dy.clear();
		dz.clear();
		dl.clear();
		*/
		
	}
	time(&second);
	printf("Simulation takes %lf seconds\n", difftime(second, first));
}
void YTransport::event(int mode, int i)
{
	//elist[i].step(Efield);
	elist[i].step(mode,hfieldx1,hfieldx2,hfieldx3,hfieldy1,hfieldy2,hfieldy3,hfieldz1,hfieldz2,hfieldz3);
}
void YTransport::print()
{
    int cnt = 0;
	int cnt_trap = 0;
	htime->Reset();
	hstep->Reset();
	for(int i = 0; i < elist.size(); ++i)
	{
	    htime->Fill(elist[i].t); 
		if(elist[i].status() == 2)
		{
		    cnt++;
		    hstep->Fill(elist[i].cnt);
		}
		else if(elist[i].status() == -2)
		{
		    cnt_trap++;
			hstep_t->Fill(elist[i].cnt);
		}
	}
    printf("Total status(2) = %d\n", cnt);
	printf("Total status(-2) = %d\n", cnt_trap);
#ifdef DEBUG
    cube.Draw();
	partgen.Draw("same");
#endif
}
void YTransport::save(char* fname, int i)
{
    ofstream ofs;
	ofs.open(fname, ofstream::out | ofstream::app);
	
	    ofs << i << " : " << elist[i].x << "    " << elist[i].y << "    " << elist[i].z << "    " << elist[i].t << "    " << elist[i].path << "    " << elist[i].cnt << "    " << '\n';
	
	ofs.close();
}
void YTransport::load(string& fname)
{
    ifstream ifs {fname};
	if(!ifs) cout << "error\n";
	electron tmp;
	while(!ifs.eof())
	{
	   ifs >> tmp.x >> tmp.y >> tmp.z >> tmp.t >> tmp.path;
	   elist.push_back(tmp);
	}
	ifs.close();
}
void YTransport::debug(int n)
{
    
    hvthx->Reset();
    hvthy->Reset();
    hvthz->Reset();
    hvthl->Reset();
	for(int i=0; i<carrier_dx[n].size(); ++i)
	{
	   hvthx->Fill(carrier_dx[n][i]);
	   hvthy->Fill(carrier_dy[n][i]);
	   hvthz->Fill(carrier_dz[n][i]);
	   hvthl->Fill(carrier_dl[n][i]);
	}
    
}
