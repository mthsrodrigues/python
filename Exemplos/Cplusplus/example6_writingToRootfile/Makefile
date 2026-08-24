OBJS = $(addsuffix .o,$(basename $(wildcard src/*.cc)))

OPT = -O -Wall -fPIC

INC = -Iinterface -I$(ROOTSYS)/include

LIBS = -L. -lEventDumper

ROOTLIBS = -L$(ROOTSYS)/lib -lCore -lTree -lRIO

all:
	$(MAKE) libEventDumper.so
	$(CXX) example4.6.cpp $(INC) $(LIBS) $(ROOTLIBS) -o example4.6

libEventDumper.so: $(OBJS)
	$(CXX) -shared -O $(OBJS) -o libEventDumper.so

.cc.o:
	$(CXX) -c $(OPT) $(INC) $(ROOTLIBS) $< -o $@


test:
	echo $(OBJS)

clean:
	rm -f *~ $(OBJS)

cleanAll:
	$(MAKE) clean
	rm -f example4.6 *.so *.root
