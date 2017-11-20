#include <iostream>
#include <fstream>
using namespace std;

TGraph* gr = new TGraph();
void EzPlot()
{
    ifstream ifs ("x0y0_Ez.txt");
	double z, Ez;
	int cnt=0;
	while(!ifs.eof())
	{
	   ifs >> z >> Ez; 
	   gr->SetPoint(cnt, z, Ez);
	   ++cnt;
	}
}
