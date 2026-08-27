CXX = g++
CXXFLAGS = -Wall -Wextra -fPIC

all: libSimpleMET.so testMET

SimpleMET.o: SimpleMET.cpp SimpleMET.h
	$(CXX) $(CXXFLAGS) -c SimpleMET.cpp -o SimpleMET.o

libSimpleMET.so: SimpleMET.o
	$(CXX) -shared -o libSimpleMET.so SimpleMET.o

testMET: testMET.cpp libSimpleMET.so
	$(CXX) testMET.cpp -L. -lSimpleMET -Wl,-rpath,. -o testMET

clean:
	rm -f *.o *.so testMET
