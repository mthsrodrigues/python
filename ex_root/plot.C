#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TStyle.h"
#include <iostream>

void plot() {
    TFile *file = new TFile("dados.root", "READ");
    TTree *tree = (TTree*) file->Get("tree");

    double x;
    tree->SetBranchAddress("x", &x);

    TH1F *h = new TH1F(
        "h",
        "Distribuicao gerada;Valor gerado;Numero de entradas",
        50, -5, 5
    );

    Long64_t nentries = tree->GetEntries();

    for (Long64_t i = 0; i < nentries; i++) {
        tree->GetEntry(i);
        h->Fill(x);
    }

    h->SetLineColor(kBlack);
    h->SetLineStyle(1);
    h->SetLineWidth(3);
    h->SetFillColor(kYellow);

    gStyle->SetCanvasColor(kWhite);

    TCanvas *c = new TCanvas("c", "Histograma", 800, 600);
    c->SetFillColor(kWhite);

    h->Fit("gaus");

    TF1 *fit = h->GetFunction("gaus");

    std::cout << "Media ajustada = "
              << fit->GetParameter(1)
              << std::endl;

    std::cout << "Sigma ajustado = "
              << fit->GetParameter(2)
              << std::endl;

    h->Draw();
    c->SaveAs("histograma.png");

    file->Close();
}