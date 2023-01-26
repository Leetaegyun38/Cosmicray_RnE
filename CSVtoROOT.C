#include "Riostream.h"

void CSVtoROOT(){

    TString dir = gSystem -> UnixPathName(gInterpreter -> GetCurrentMacroName());
    dir.ReplaceAll("CSVtoROOT.C","");
    dir.ReplaceAll("/./","/");
    ifstream in;
    in.open(Form("%sclouddata.txt",dir.Data()));

    Int_t time,year,month,day,hour,totc,fog,lowc,midc,highc,dtotc,dlowc,ABS_dtotc,ABS_dlowc;
    Int_t nlines = 0;

    TFile *f = new TFile("clouddata.root", "RECREATE");
    TH1F *h1 = new TH1F("h1", "time distribution", 100, -4, 4);
    TNtuple *ntuple = new TNtuple("ntuple", "cloud_data", "time:year:month:day:hour:totc:fog:lowc:midc:highc:dtotc:dlowc:ABS_dtotc:ABS_dlowc");

    while (1) 
     {
          in >>time>>year>>month>>day>>hour>>totc>>fog>>lowc>>midc>>highc>>dtotc>>dlowc>>ABS_dtotc>>ABS_dlowc;
          if (!in.good())
		 break;
          else
		printf("time=%d,year=%d,month=%d,day=%d,hour=%d,totc=%d,fog=%d,lowc=%d,midc=%d,highc=%d,dtotc=%d,dlowc=%d,ABS_dtotc=%d,ABS_dlowc=%d",time,year,month,day,hour,totc,fog,lowc,midc,highc,dtotc,dlowc,ABS_dtotc,ABS_dlowc);

          h1 -> Fill(time);
          ntuple -> Fill(time,year,month,day,hour,totc,fog,lowc,midc,highc,dtotc,dlowc,ABS_dtotc,ABS_dlowc);
          nlines++;
     }
     printf("found %d data\n", nlines);
     in.close();
     f -> Write();
}
