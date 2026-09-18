#define N 3
void example3_graph(){

  TH2F *frame = new TH2F("frame","",2,0,5,2,0,5);
  frame->SetStats(0);
  frame->GetXaxis()->SetTitle("x-title");
  frame->Draw();
  
  //  int N = 3;
  float x[3] = {1,2,3};
  float y[3] = {2,3,4};

  TGraph* myGraph = new TGraph(N,x,y);
  myGraph->Draw("same");

  float x2[3] = {2,3,4};
  float y2[3] = {2,3,3};

  TGraph* myGraph2 = new TGraph(N,x2,y2);
  myGraph2->SetLineColor(2);
  myGraph2->SetLineWidth(2);
  myGraph2->Draw("same");

  TArrow *arrow = new TArrow(3.59241, 1.39706, 3.01934, 2.85452, 0.05, ">");
   arrow->SetFillColor(1);
   arrow->SetFillStyle(1001);
   arrow->SetLineColor(2);
   arrow->SetLineStyle(2);
   arrow->SetLineWidth(2);
   arrow->Draw(">");
   TLatex *tex = new TLatex(3.61032, 1.04254, "TEXT");
   tex->SetLineWidth(2);
   tex->Draw();
   tex = new TLatex(1.79262, 2.88078, "Test2");
   tex->SetTextAngle(33.95906);
   tex->SetLineWidth(2);
   tex->Draw();
}
