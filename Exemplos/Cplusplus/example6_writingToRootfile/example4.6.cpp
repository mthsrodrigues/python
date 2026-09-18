#include <time.h>
#include "TFile.h"
#include "EventInfoDumper.h"

// Idea: you fill the variables with the EventInfoDumper class

int main(){
  //Initialization
  TFile* fOUT = TFile::Open("test.root","RECREATE");

  TTree* Events = new TTree("Events","");
  EventInfoDumper *eventInfo = new EventInfoDumper();
  eventInfo->book(Events);

// Event loop
  size_t NEV = 10;

  unsigned run = 1;
  unsigned lumi = 10;
  unsigned long long event = 1;
  for(size_t i = 0; i < NEV; ++i){
    event = event + i;
    eventInfo->fill(run,lumi,event);

    Events->Fill();
  }

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

