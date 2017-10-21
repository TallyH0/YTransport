//R__LOAD_LIBRARY(./YYTransport.so)

TH1F *h1 = new TH1F("h1","test",100,0,1);
void run() {
  printf("  Test exercise step1\n");
  gSystem->Load("./YTransport.so");
  YTransport *ytrans = new YTransport();
  for(int i=0; i<10000; i++) {
    h1->Fill(ytrans->GenRndm());
  }
}

