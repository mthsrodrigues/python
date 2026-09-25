CXX = g++
CXXFLAGS = -O2 -Wall -std=c++17 $(shell $(PYTHIA8)/bin/pythia8-config --cxxflags) $(shell root-config --cflags)
LIBS = $(shell $(PYTHIA8)/bin/pythia8-config --libs) $(shell root-config --libs)

all: main_higgs main_backgrounds

main_higgs: main_higgs.cc
	$(CXX) $(CXXFLAGS) $< -o $@ $(LIBS)

main_backgrounds: main_backgrounds.cc
	$(CXX) $(CXXFLAGS) $< -o $@ $(LIBS)

clean:
	rm -f main_higgs main_backgrounds *.o

.PHONY: all clean
