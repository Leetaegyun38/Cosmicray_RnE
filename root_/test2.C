#include "Riostream.h"
void test2() {

   TString dir = gSystem->UnixPathName(__FILE__);
   dir.ReplaceAll("test2.C","");
   dir.ReplaceAll("/./","/");

   ifstream in;
   in.open(Form("%stest2.dat",dir.Data()));

   Float_t particle,detector,edep;
   Int_t nlines = 0;
   auto f = TFile::Open("test2.root","RECREATE");
   TH1F h1("h1","x distribution",100,-4,4);
   TNtuple ntuple("ntuple","test2","particle:detector:edep");

   while (1) {
      in >> particle >> detector >> edep;
      if (!in.good()) break;
      if (nlines < 3000) printf("particle=%8f, detector=%8f, edep=%8f\n",particle,detector,edep);
      h1.Fill(particle);
      ntuple.Fill(particle,detector,edep);
      nlines++;
   }

   printf(" found %d points\n",nlines);

   in.close();

   f->Write();
}
