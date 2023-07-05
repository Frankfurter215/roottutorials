void mysecondhist()
{
  TCanvas *c1 = new TCanvas();
  
  gStyle->SetPalette(kRainBow); //adds more colors to the colz
  
  TH2F *hist = new TH2F("hist", "Histogram", 100, -1, 1, 100, -1, 1); //name, title, #xbins, xmin/max, repeat y
  
  hist->SetStats(0);
  
  TRandom *rand = new TRandom(10);
  
  for(int i = 0; i < 1e7; i++)
  {
    double x = rand->Gaus();
    double y = rand->Gaus();
    
    hist->Fill(x, y);
  }
  
  hist->GetXaxis()->SetTitle("x [cm]");
  hist->GetYaxis()->SetTitle("y [cm]");
  hist->GetZaxis()->SetTitle("entries");
  
  hist->SetContour(1000); //smooths the color
  
  hist->Draw("colz"); //colz adds color
}
