void example8_tree(){

  TFile * myfile = TFile::Open("myfile.root","RECREATE");
  myfile->cd();
  TTree* mytree = new TTree("mytree","title");
  Float_t myvariable;
  mytree->Branch("myvariable",&myvariable,"myvariable/F");

  for(int i = 0; i < 10;++i){
    myvariable = float(i);
    mytree->Fill();
  }

  myvariable = 15;
  mytree->Fill();
    
  mytree->Write();
  myfile->Close();
  
}
