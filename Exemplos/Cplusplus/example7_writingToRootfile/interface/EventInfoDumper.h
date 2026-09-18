#ifndef EventInfoDumper_h
#define EventInfoDumper_h

#include <string>
#include <vector>

#include "TFile.h"
#include "TTree.h"

class EventInfoDumper {
    public:
	EventInfoDumper(std::string fname="test.root");
	~EventInfoDumper();

	void book(TTree*);
	void fill(unsigned run, unsigned lumi, unsigned long long event);

    private:
        TFile* fOUT;
        TTree* Events;
	unsigned long long event;
	unsigned int run,lumi;
};
#endif
