void definingfunctions()
{
  TCanvas *c1 = new TCanvas("c1", "c1", 400, 400); //changing size of the canvas changes size of graph and fonts
  c1->SetLeftMargin(0.15);
  
  //TF1 *func = new TF1("func", "[0] + [1]*x", 0 , 5); //line
  TF1 *func = new TF1("func", "exp(-[1]*x)*[0]*sin(x)", 0 , 10*TMath::Pi());
  
  func->SetTitle("Cool Sine Thing");
  
  func->SetParameter(0, 1); //amp
  func->SetParameter(1, 0.1);//slope
  
  func->GetXaxis()->SetTitle("Test");
  func->GetYaxis()->SetTitle("Test");
  
  func->Draw();
  
  c1->Print("func.tex"); //saving the plot pdf is editable in inkscape, png is not, saving as .tex allows u to put it in papers really easily
}
