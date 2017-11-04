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
	    electron tmp(0, 0, 9, 5e12);
		elist.push_back(tmp);	
	}
}
void YTransport::transport()
{
	time_t first, second;
	time(&first);
	int cnt = 1;
	for(int i = 0; i < elist.size(); ++i)
	{
		while(!elist[i].status()){
			event(i);
#ifdef DEBUG
	gr.SetPoint(cnt,elist[i].t,elist[i].z);
	cnt++;
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
