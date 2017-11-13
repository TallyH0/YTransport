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
	for(int i=0; i< 10000; ++i)
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
	int status_cnt;
	int pm3d_cnt = 0;
	while(status_cnt != elist.size())
	{
	    status_cnt = 1;
	    for(int i = 0; i < elist.size(); ++i)
		{
		    if(elist[i].status() == 0)
			{
		        event(i);
			}else{
			    status_cnt++;
			}
	       // pm3d[pm3d_cnt].SetNextPoint(elist[i].x, elist[i].y, elist[i].z);
		}
		    //pm3d_cnt++;
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
	    ofs << elist[i].x << '\t' << elist[i].y << '\t' << elist[i].z << '\t' << elist[i].t << '\t' << elist[i].path << '\t' << elist[i].cnt << endl;
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
