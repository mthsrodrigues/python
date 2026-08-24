#ifndef EventInfoDumper_h
#define EventInfoDumper_h

#include <string>
#include <vector>

#include "TTree.h"

class EventInfoDumper {
    public:
	EventInfoDumper();
	~EventInfoDumper();

	void book(TTree*);
	bool fill(unsigned run, unsigned lumi, unsigned long long event);

    private:
	unsigned long long event;
	unsigned int run,lumi;
};
#endif
