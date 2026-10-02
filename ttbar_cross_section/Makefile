CXX = g++
CXXFLAGS = -O2 -Wall -std=c++17 -I$(PYTHIA8)/include
LDFLAGS = -L$(PYTHIA8)/lib -Wl,-rpath,$(PYTHIA8)/lib -lpythia8 -ldl

all: ttbar_pythia

ttbar_pythia: ttbar_pythia.cc
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f ttbar_pythia
