#include "Pythia8/Pythia.h"
#include <iostream>

using namespace Pythia8;
using namespace std;

int main() {

    Pythia pythia;

    pythia.readString("Beams:idA = 2212");
    pythia.readString("Beams:idB = 2212");
    pythia.readString("Beams:eCM = 13000.");

    pythia.readString("Top:qqbar2ttbar = on");

    if (!pythia.init()) {
        cerr << "Pythia initialization failed." << endl;
        return 1;
    }

    const int nEvents = 10000;
    int nAccepted = 0;

    for (int iEvent = 0; iEvent < nEvents; ++iEvent) {
        if (!pythia.next()) continue;
        ++nAccepted;
    }

    pythia.stat();

    double sigma_pb = pythia.info.sigmaGen() * 1e9;
    double error_pb = pythia.info.sigmaErr() * 1e9;

    cout << endl;
    cout << "========================================" << endl;
    cout << "pp -> ttbar (qqbar channel)" << endl;
    cout << "Generated events: " << nEvents << endl;
    cout << "Accepted events:  " << nAccepted << endl;
    cout << "sigma = " << sigma_pb << " +- " << error_pb << " pb" << endl;
    cout << "========================================" << endl;

    return 0;
}
