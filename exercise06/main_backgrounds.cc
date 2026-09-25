#include "Pythia8/Pythia.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace Pythia8;

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << "Usage: ./main_backgrounds config.cmnd output.root\n";
        return 1;
    }

    std::string config = argv[1];
    std::string outputName = argv[2];

    Pythia pythia;

    if (!pythia.readFile(config)) {
        std::cerr << "Error reading " << config << "\n";
        return 1;
    }

    if (!pythia.init()) {
        std::cerr << "PYTHIA initialization failed\n";
        return 1;
    }

    TFile output(outputName.c_str(), "RECREATE");

    TTree tree("events", "Background events");
    double mH = 0.0;
    tree.Branch("mH", &mH);

    TH1D hist(
        "mass",
        "b#bar{b} invariant mass;m_{bb} [GeV];Events",
        60, 0, 300
    );

    int nEvents = pythia.mode("Main:numberOfEvents");

    for (int iEvent = 0; iEvent < nEvents; ++iEvent) {

        if (!pythia.next())
            continue;

        std::vector<int> b;
        std::vector<int> bbar;

        for (int i = 0; i < pythia.event.size(); ++i) {


            if (pythia.event[i].id() == 5)
                b.push_back(i);

            if (pythia.event[i].id() == -5)
                bbar.push_back(i);
        }

        if (b.empty() || bbar.empty())
            continue;

        int ib = b[0];
        int ibbar = bbar[0];

        double bestPtB = pythia.event[ib].pT();
        double bestPtBbar = pythia.event[ibbar].pT();

        for (int i : b) {
            if (pythia.event[i].pT() > bestPtB) {
                ib = i;
                bestPtB = pythia.event[i].pT();
            }
        }

        for (int i : bbar) {
            if (pythia.event[i].pT() > bestPtBbar) {
                ibbar = i;
                bestPtBbar = pythia.event[i].pT();
            }
        }

        Vec4 pBB = pythia.event[ib].p() + pythia.event[ibbar].p();

        mH = pBB.mCalc();

        tree.Fill();
        hist.Fill(mH);
    }

    pythia.stat();

    output.cd();
    tree.Write();
    hist.Write();
    output.Close();

    std::cout << "Created " << outputName << "\n";

    return 0;
}
