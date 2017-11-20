#include "YTransport.h"

ClassImp(YTransport)
YTransport::YTransport()
{
}
void YTransport::initialize()
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
	ReadData(Efield);
	//beam->initialize();
	//beam->generation();
    
	electron tmp(0,0,9,5e12);
	//for(int i=0; i< beam->pos_carrier[0].size(); ++i)
	for(int i=0; i< 1000; ++i)
	{
	    //electron tmp(beam->pos_carrier[0][i], beam->pos_carrier[1][i], beam->pos_carrier[2][i], RAD_DAMAGE);
		elist.push_back(tmp);
#ifdef DEBUG
	    partgen.SetNextPoint(beam->pos_carrier[0][i], beam->pos_carrier[1][i], beam->pos_carrier[2][i]);
#endif
	}
}
void YTransport::transport()
{
	time_t first, second;
	time(&first);
	int cnt=0;
	for(int i=0; i<elist.size(); ++i)
	{
	    cnt=0;
	    while(elist[i].status()==0)
		{
		    event(i);
			Z_plot[i].SetPoint(cnt,elist[i].t,elist[i].z);
			++cnt;
		}
		cout << i << "electron done\n";
		
	}
	time(&second);
	printf("Simulation takes %lf seconds\n", difftime(second, first));
}
void YTransport::event(int i)
{
	elist[i].step(Efield);
}
void YTransport::print()
{
    int cnt = 0;
	int cnt_trap = 0;
	for(int i = 0; i < elist.size(); ++i)
	{
	    printf("electron[%d] dz by v_th : %lf    dz by v_drift : %lf\n",i,elist[i].vd_z, elist[i].vth_z);
	    htime->Fill(elist[i].t); 
		if(elist[i].status() == 2) cnt++;
		else if(elist[i].status() == -1) cnt_trap++;
	}
    printf("Total status(2) = %d\n", cnt);
	printf("Total status(-1) = %d\n", cnt_trap);
	htime->Draw();
#ifdef DEBUG
    cube.Draw();
	partgen.Draw("same");
#endif
}
void YTransport::save(string& fname)
{
    ofstream ofs (fname.c_str());
	
	for(int i = 0; i < elist.size(); ++i)
	{
	    ofs << i << " : " << elist[i].x << "    " << elist[i].y << "    " << elist[i].z << "    " << elist[i].t << "    " << elist[i].path << "    " << elist[i].cnt << "    " << '\n'
		<< elist[i].status() << "    " << elist[i].vth_z << "    " << elist[i].vd_z << endl;
	}
	
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
void YTransport::debug()
{
    int ct = 0;
    while(elist[0].status() == 0)
	{
	    elist[0].step(Efield);
		Zdebug.SetPoint(ct,elist[0].t,elist[0].z);
		dz_vth_plot.SetPoint(ct,elist[0].t,elist[0].vth_z);
		hvd->Fill(elist[0].dz_vd);
		hvth->Fill(elist[0].dz_vth);
		ct++;
	}
}
