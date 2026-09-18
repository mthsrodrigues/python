#include "EventInfoDumper.h"

EventInfoDumper::EventInfoDumper(){}
EventInfoDumper::~EventInfoDumper(){}

void EventInfoDumper::book(TTree* tree){
  tree->Branch("event",&event);
  tree->Branch("run",&run);     
  tree->Branch("lumi",&lumi);
}

bool EventInfoDumper::fill(unsigned r, unsigned l, unsigned long long ev){
 event = ev;
 run   = r;
 lumi  = l;

 return true;
}

