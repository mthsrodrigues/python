{
  TH1F* histo = new TH1F("test","",10,0,10);
  histo->Fill(3.14);
  histo->Fill(3.7);
  histo->Fill(6.2);

  TFile* fOUT = TFile::Open("test.root","recreate");
  histo->Write();
  fOUT->Close();

  gApplication->Terminate();
  //exit(0);
}
