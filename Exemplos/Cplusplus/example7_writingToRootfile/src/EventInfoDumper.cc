#include "EventInfoDumper.h"
#include <time.h>

EventInfoDumper::EventInfoDumper(std::string fname){
  fOUT = TFile::Open(fname.c_str(),"RECREATE");
  Events = new TTree("Events","");
  book(Events);
}
EventInfoDumper::~EventInfoDumper(){
  fOUT->cd();

// write date
  time_t rawtime;
  time (&rawtime);
  TString dateName = "Generated "+TString(ctime(&rawtime));
  TNamed* dateString = new TNamed("","");
  dateString->Write(dateName);

// write TTree
  Events->Write();

// close output file
    fOUT->Close();
}

void EventInfoDumper::book(TTree* tree){
  tree->Branch("event",&event);
  tree->Branch("run",&run);     
  tree->Branch("lumi",&lumi);
}

void EventInfoDumper::fill(unsigned r, unsigned l, unsigned long long ev){
 event = ev;
 run   = r;
 lumi  = l;

Events->Fill();
}

