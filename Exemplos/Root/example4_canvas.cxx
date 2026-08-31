void example4_canvas(){

  TCanvas* canvas = new TCanvas("CanvasName","",1000,1000);
  canvas->cd();
  
  
  TH2F* frame = new TH2F("FrameName","",2,0,10,2,0,10);
  frame->SetStats(0);
  frame->GetXaxis()->SetTitle("x");
  frame->GetYaxis()->SetTitle("y");
  frame->Draw();

  Int_t N = 4;
  double x[N];
  x[0] = 1;
  x[1] = 2;
  x[2] = 3;
  x[3] = 8;
  
  double y[N];
  y[0] = 1;
  y[1] = 2;
  y[2] = 3;
  y[3] = 9;
  
  TGraph *g = new TGraph(N,x,y);
  g->SetMarkerStyle(20);  
  g->Draw("CP");

  Int_t N2 = 4;
  double x2[N];
  x2[0] = 1;
  x2[1] = 2;
  x2[2] = 3;
  x2[3] = 8;

  double y2[N];
  y2[0] = 2;
  y2[1] = 3;
  y2[2] = 3.5;
  y2[3] = 8;
  
  TGraph *gg = new TGraph(N2,x2,y2);
  gg->SetMarkerStyle(21);
  gg->SetMarkerColor(2);
  gg->Draw("CP");
  
  TLatex* tex = new TLatex(2.177419,5.3,"Some text");
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(2.65132,6.458333,"Some other text");
  tex->SetLineWidth(2);
  tex->Draw();

  canvas->Print("ex4.png");
    
}
