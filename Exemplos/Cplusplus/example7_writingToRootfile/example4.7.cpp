#include "EventInfoDumper.h"

// Idea: make the EventInfoDumper class to fill the variables, tree and write into a file

int main(){
  //Initialization
  EventInfoDumper *eventInfo = new EventInfoDumper();

// Event loop
  size_t NEV = 10;

  unsigned run = 1;
  unsigned lumi = 10;
  unsigned long long event = 1;
  for(size_t i = 0; i < NEV; ++i){
    event = event + i;
    eventInfo->fill(run,lumi,event);
  }

  delete eventInfo;
}

