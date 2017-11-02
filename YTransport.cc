#include "YTransport.h"

ClassImp(YTransport)
YTransport::YTransport()
{
}
void YTransport::initialize(int n)
{
	ReadData(Efield);
	for(int i = 0; i < n; ++i)
	{
	    electron tmp(0, 0, 15, 5e12);
		elist.push_back(tmp);	
	}
#ifdef DEBUG
    pos.SetLineColor(2);
	pm3d.SetMarkerColor(3);
	pm3d.SetMarkerSize(1);
	pm3d.SetMarkerStyle(3);
	for(int i = -SIZE_X; i <= SIZE_X; ++i)
	{
	    pm3d.SetNextPoint(i,SIZE_Y,17);
	    pm3d.SetNextPoint(i,-SIZE_Y,17);
	    pm3d.SetNextPoint(SIZE_X,i,17);
	    pm3d.SetNextPoint(-SIZE_X,i,17);
	}
	for(int i = 0; i <= 17; ++i)
	{
	    pm3d.SetNextPoint(-SIZE_X,-SIZE_Y,i);
	    pm3d.SetNextPoint(SIZE_X,-SIZE_Y,i);
	    pm3d.SetNextPoint(-SIZE_X,SIZE_Y,i);
	    pm3d.SetNextPoint(SIZE_X,SIZE_Y,i);
	}
#endif
}
void YTransport::transport()
{
	time_t first, second;
	time(&first);
	for(int i = 0; i < elist.size(); ++i)
	{
		while(!elist[i].status()){
			event(i);
#ifdef DEBUG
    pos.SetNextPoint(elist[i].x, elist[i].y, elist[i].z);
#endif
		}
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
		if(elist[i].status() == 2) cnt++;
		else if(elist[i].status() == -1) cnt_trap++;
	}
#ifdef DEBUG
    pos.Draw();
	pm3d.Draw("same");
    printf("Total status(2) = %d\n", cnt);
	printf("Total status(-1) = %d\n", cnt_trap);
#endif
}
void YTransport::save(string& fname)
{
    ofstream ofs (fname.c_str());
	
	for(int i = 0; i < elist.size(); ++i)
	{
	    ofs << elist[i].x << '\t' << elist[i].y << '\t' << elist[i].z << '\t' << elist[i].t << '\t' << elist[i].path << endl;
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
