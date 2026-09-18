#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TStyle.h>
#include <iostream>

int main() {
    TFile file("data_cpp.root", "READ");

    if (file.IsZombie()) {
        std::cerr << "Could not open data_cpp.root" << std::endl;
        return 1;
    }

    TTree *tree = nullptr;
    file.GetObject("tree", tree);

    if (!tree) {
        std::cerr << "Tree not found" << std::endl;
        return 1;
    }

    double x;
    tree->SetBranchAddress("x", &x);

    gStyle->SetCanvasColor(kWhite);

    TCanvas canvas("canvas", "Gaussian distribution", 800, 600);
    canvas.SetFillColor(kWhite);

    TH1F hist(
        "hist",
        "Gaussian distribution;Generated value;Number of entries",
        50, -5, 5
    );

    hist.SetLineColor(kBlack);
    hist.SetLineWidth(3);
    hist.SetFillColor(kYellow);

    Long64_t entries = tree->GetEntries();

    for (Long64_t i = 0; i < entries; ++i) {
        tree->GetEntry(i);
        hist.Fill(x);
    }

    TF1 fit("fit", "gaus", -5, 5);
    hist.Fit(&fit);

    hist.Draw();
    canvas.SaveAs("fit_cpp.png");

    std::cout << "Mean = " << fit.GetParameter(1) << std::endl;
    std::cout << "Sigma = " << fit.GetParameter(2) << std::endl;

    file.Close();

    return 0;
}
