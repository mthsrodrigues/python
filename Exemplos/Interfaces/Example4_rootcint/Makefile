CXX = g++
CXXFLAGS = -O2 -Wall -fPIC
ROOTCFLAGS = $(shell root-config --cflags)
ROOTLIBS = $(shell root-config --glibs)
INCLUDES = -I$(ROOTSYS)/include

OBJS = MyParticle.o MyEvent.o eventdict.o

all: libMyEvent.so

eventdict.cc: MyParticle.h MyEvent.h LinkDef.h
	rootcint -f $@ -c $(INCLUDES) $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) $(INCLUDES) -c $<

libMyEvent.so: $(OBJS)
	$(CXX) -shared -o $@ $^ $(ROOTLIBS)

clean:
	rm -f *.o *.so eventdict.*
