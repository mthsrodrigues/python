#include <iostream>
#include "SimTrack.h"

void printTrack(const SimTrack& track) {
    std::cout << "Pt = " << track.Pt() << std::endl;
    std::cout << "Eta = " << track.Eta() << std::endl;
    std::cout << "ParticleId = " << track.ParticleId() << std::endl;
    std::cout << "ParentId = " << track.ParentId() << std::endl;
    std::cout << std::endl;
}

int main() {
    SimTrack track1(10.0, 3.0, 4.0, 5.0, 11, 23);
    SimTrack track2(20.0, 0.0, 0.0, 10.0, 211, 111);

    printTrack(track1);
    printTrack(track2);

    return 0;
}
