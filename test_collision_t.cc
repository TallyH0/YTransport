TGraph * gr = new TGraph();
TGraph *gr2 = new TGraph();
void test_collision_t()
{
	int cnt = 0;
    for(int i = 0; i < 1e3; ++i)
	{
	   gr->SetPoint(i, i,1/ collision_time(i * 1e11)); 
	}
	for(double j = 1e12; j < 1e19; j+= (1e19 - 1e12)/1000)
	{
	    gr2->SetPoint(cnt, j, collision_time(j));
		cnt++;
	}
	gr2->Draw();
	double max = gr->GetYaxis()->GetXmax();
	double min = gr->GetYaxis()->GetXmin();
    double diff = (max-min) / min * 100;
	printf("difference = %lf%%\n", diff);
}
double collision_time(double doping)
{
	static const double m = 9.11e-31;
	static const double q = 1.602e-19;
	return 1e-4 * 2 * mobility(doping) * m / q;
} 
double mobility(double doping)
{
	static double const m_max = 470.5;
	static double const m_min = 44.9;
	static double const N_r = 2.23e17;
	static double const alpha = 0.719;

	return m_min + (m_max - m_min) / (1 + pow(doping/N_r , alpha));
}
