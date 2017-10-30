//R__LOAD_LIBRARY(./YYTransport.so)
#include <cstdlib>
#include <ctime>

TH1D *h1 = new TH1D("h1","time_{NULL}",100,-0.001,1.001);
TH1D *h2 = new TH1D("h2","gRandom",100,-0.001,1.001);
TCanvas *c1 = new TCanvas();
void run() {
  srand(unsigned(time(NULL)));
  gSystem->Load("./YTransport.so");
  for(int i=0; i<1000000; i++) {
    h1->Fill((double)rand()/RAND_MAX);
	h2->Fill(gRandom->Rndm());
  }
  c1->Divide(1,2);
  c1->cd(1);
  h1->Draw();
  c1->cd(2);
  h2->Draw();
}

