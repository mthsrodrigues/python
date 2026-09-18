void example7_pads(){

  TFile* fIN = TFile::Open("test.root");
  TH1F* histo = (TH1F*)fIN->Get("test");
  cout << "histo integral " << histo->Integral() << endl;

  TCanvas* canvas = new TCanvas("canvas","",700,500);
  canvas->Divide(2,1);

  canvas->cd(1);
  histo->Draw();

  canvas->cd(2);
  TH1F* histo2 = (TH1F*)histo->Clone();
  histo2->SetStats(0);
  histo2->SetFillColor(2);
  histo2->SetLineColor(8);
  histo2->Draw();

  histo2->GetXaxis()->SetTitle("x axis");
  histo2->GetYaxis()->SetTitle("y axis");

  gPad->SetLogy();

  TLatex* tex = new TLatex(43.5,1.5,"Some text");
  tex->SetLineWidth(2);
  tex->Draw();

  canvas->Print("mytestcanvas.C");
  canvas->Print("mytestcanvas.png");
  canvas->Print("mytestcanvas.pdf");
}
