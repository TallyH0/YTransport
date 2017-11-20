#include <iostream>
#include <fstream>
TH3D* hEfield = new TH3D("hEfield","",3000,-10,10,3000,-10,10,50,-1,20);
TGraph* gr = new TGraph();
TGraph* grh = new TGraph();
struct Efield
{
	int n;
	double x, y, z, Ex, Ey, Ez;
};
void Interpolation()
{
	std::ifstream ifs ("efield_Si_output.txt");
	if(!ifs) std::cout << "Error\n";

	Efield tmp;
	int i = 0;
	while(!ifs.eof())
	{
		ifs >> tmp.n >> tmp.x >> tmp.y >> tmp.z >> tmp.Ex >> tmp.Ey >> tmp.Ez;	
		hEfield->Fill(tmp.x, tmp.y, tmp.z, tmp.Ez);
        i++;
	}
	ifs.close();
	double a,b;
	std::ifstream ifs2 ("x0y0_Ez.txt");
	for(int i=0; i<39;++i)
	{
	    ifs2>>a>>b;
	    gr->SetPoint(i,a,b);
		grh->SetPoint(i,a,hEfield->Interpolate(0,0,a));
		
	}
	ifs2.close();    
}
