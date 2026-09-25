#include "Pythia8/Pythia.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"

#include <iostream>
#include <vector>

using namespace Pythia8;

int main() {

    Pythia pythia;

    if (!pythia.readFile("higgs.cmnd")) {
        std::cerr << "Error reading higgs.cmnd\n";
        return 1;
    }

    if (!pythia.init()) {
        std::cerr << "PYTHIA initialization failed\n";
        return 1;
    }

    TFile output("higgs_mass.root", "RECREATE");

    TTree tree("events", "Higgs events");
    double mH = 0.0;
    tree.Branch("mH", &mH);

    TH1D hist(
        "higgs_mass",
        "Reconstructed Higgs mass;m_{bb} [GeV];Events",
        60, 80, 170
    );

    const int nEvents = pythia.mode("Main:numberOfEvents");

    for (int iEvent = 0; iEvent < nEvents; ++iEvent) {

        if (!pythia.next())
            continue;

        int iHiggs = -1;

        for (int i = 0; i < pythia.event.size(); ++i) {
            if (pythia.event[i].id() == 25) {
                iHiggs = i;
            }
        }

        if (iHiggs < 0)
            continue;

        std::vector<int> bDaughters;

        for (int i = 0; i < pythia.event.size(); ++i) {

            if (std::abs(pythia.event[i].id()) != 5)
                continue;

            if (pythia.event[i].mother1() == iHiggs ||
                pythia.event[i].mother2() == iHiggs) {
                bDaughters.push_back(i);
            }
        }

        if (bDaughters.size() != 2)
            continue;

        Vec4 pBB =
            pythia.event[bDaughters[0]].p() +
            pythia.event[bDaughters[1]].p();

        mH = pBB.mCalc();

        tree.Fill();
        hist.Fill(mH);
    }

    pythia.stat();

    output.cd();
    tree.Write();
    hist.Write();
    output.Close();

    std::cout << "Created higgs_mass.root\n";

    return 0;
}
