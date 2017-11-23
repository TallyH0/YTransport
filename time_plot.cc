#include <iostream>
#include <fstream>
TH1D* htime = new TH1D("htime","",200,-1e-8,1.1e-7);
void time_plot()
{
    ifstream ifs ("RESULT_diffusion_only.txt");
    double t;
    double n,x,y,z,l,c,s,vth,vd;

	while(!ifs.eof())
	{
	    ifs >> n >> ":" >> x >> y >> z >> t >> l >> c >> s >> vth>> vd;
		cout << n << ' ' << t << '\n';
		htime->Fill(t);
	}
    ifs.close();
}

