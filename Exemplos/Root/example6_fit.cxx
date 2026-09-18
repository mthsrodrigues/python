Double_t fitFunction(Double_t* x,Double_t* par){
  // ax^2 + bx + c
  return par[0]*x[0]*x[0] + par[1]*x[0] + par[2];
}

void example6_fit(){

  double x[3] = {1,2,3};
  double y[3] = {0.9,2.1,2.69};

  TCanvas* canvas = new TCanvas("fit","",500,500);
  canvas->cd();

  TH2F* frame = new TH2F("frame","",2,0,4,2,0,4);
  frame->SetStats(0);
  frame->Draw();

  TGraph* graph = new TGraph(3,x,y);
  graph->SetMarkerColor(2);
  graph->SetMarkerStyle(22);
  graph->SetMarkerSize(2.2);
  //  graph->SetMarkerStyle(21);
  //  graph->SetMarkerColor(4);
  //  graph->SetMarkerSize(1);
  graph->Draw("P");
  
  double fitRangeMin = 0;
  double fitRangeMax = 4;
  int nPar = 3;
  TF1* myFit = new TF1("myFit",fitFunction,fitRangeMin,fitRangeMax,nPar);

  graph->Fit("myFit");

  TLatex *   tex = new TLatex(0.5,3.5,TString("Fit parameter [0] = ")+myFit->GetParameter(0));
  tex->SetLineWidth(2);
  tex->Draw();

  char line[100];
  sprintf (line, "Fit parameter [1] = %.2f", myFit->GetParameter(1));
  tex = new TLatex(0.5,3.0,line);
  tex->SetLineWidth(2);
  tex->Draw();

  cout << "\nAccess to fit parameters "
       << myFit->GetParameter(0) << " "
       << myFit->GetParameter(1) << " "
       << myFit->GetParameter(2) << endl;  
  
}
