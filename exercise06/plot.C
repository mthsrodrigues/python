void plot() {

    gROOT->SetBatch(kTRUE);
    gStyle->SetOptStat(0);

    TFile *fH = TFile::Open("higgs_mass.root");
    TFile *fQ = TFile::Open("qcd_bb.root");
    TFile *fZ = TFile::Open("zbb.root");
    TFile *fT = TFile::Open("ttbar.root");

    TTree *tH = (TTree*)fH->Get("events");
    TTree *tQ = (TTree*)fQ->Get("events");
    TTree *tZ = (TTree*)fZ->Get("events");
    TTree *tT = (TTree*)fT->Get("events");

    TH1D *hH = new TH1D("hH","",60,0,300);
    TH1D *hQ = new TH1D("hQ","",60,0,300);
    TH1D *hZ = new TH1D("hZ","",60,0,300);
    TH1D *hT = new TH1D("hT","",60,0,300);

    tH->Draw("mH>>hH","","goff");
    tQ->Draw("mH>>hQ","","goff");
    tZ->Draw("mH>>hZ","","goff");
    tT->Draw("mH>>hT","","goff");

    if (hH->Integral() > 0) hH->Scale(1.0/hH->Integral());
    if (hQ->Integral() > 0) hQ->Scale(1.0/hQ->Integral());
    if (hZ->Integral() > 0) hZ->Scale(1.0/hZ->Integral());
    if (hT->Integral() > 0) hT->Scale(1.0/hT->Integral());

    hH->SetLineColor(kRed);
    hQ->SetLineColor(kBlue);
    hZ->SetLineColor(kGreen+2);
    hT->SetLineColor(kMagenta);

    hH->SetLineWidth(3);
    hQ->SetLineWidth(2);
    hZ->SetLineWidth(2);
    hT->SetLineWidth(2);

    TCanvas *c = new TCanvas("c","Signal and backgrounds",900,650);

    hH->SetTitle("Higgs signal and backgrounds;m_{bb} [GeV];Normalized events");
    hH->SetMaximum(1.25 * TMath::Max(
        TMath::Max(hH->GetMaximum(),hQ->GetMaximum()),
        TMath::Max(hZ->GetMaximum(),hT->GetMaximum())
    ));

    hH->Draw("hist");
    hQ->Draw("hist same");
    hZ->Draw("hist same");
    hT->Draw("hist same");

    TLegend *leg = new TLegend(0.65,0.65,0.88,0.88);
    leg->AddEntry(hH,"Higgs #rightarrow b#bar{b}","l");
    leg->AddEntry(hQ,"QCD b#bar{b}","l");
    leg->AddEntry(hZ,"Z #rightarrow b#bar{b}","l");
    leg->AddEntry(hT,"t#bar{t}","l");
    leg->Draw();

    c->SaveAs("higgs_backgrounds.png");
}
