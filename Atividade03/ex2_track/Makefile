CXX = g++
CXXFLAGS = -Wall -Wextra -fPIC

all: libTrack.so libSimTrack.so testTrack

Track.o: Track.cpp Track.h
	$(CXX) $(CXXFLAGS) -c Track.cpp -o Track.o

libTrack.so: Track.o
	$(CXX) -shared -o libTrack.so Track.o

SimTrack.o: SimTrack.cpp SimTrack.h Track.h
	$(CXX) $(CXXFLAGS) -c SimTrack.cpp -o SimTrack.o

libSimTrack.so: SimTrack.o libTrack.so
	$(CXX) -shared -o libSimTrack.so SimTrack.o -L. -lTrack -Wl,-rpath,.

testTrack: testTrack.cpp libTrack.so libSimTrack.so
	$(CXX) testTrack.cpp -L. -lSimTrack -lTrack -Wl,-rpath,. -o testTrack

clean:
	rm -f *.o *.so testTrack
