void example9_read(){
  TFile* fIN = TFile::Open("myfile.root");
  fIN->ls();
  TTree* readtree = (TTree*)fIN->Get("mytree");    

  Float_t myvariable;
  readtree->SetBranchAddress("myvariable",&myvariable);

  for(size_t i = 0; i < readtree->GetEntries(); ++i){
    readtree->GetEntry(i);
    cout << myvariable << endl;
  }
}
