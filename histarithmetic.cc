void histarithmetic()
{
  TH1F *hist1 = new TH1F("hist1", "Histogram", 100, -10, 10);
  TH1F *hist2 = new TH1F("hist2", "Histogram", 100, -10, 10);
  TH1F *hist3 = new TH1F();
  
  hist1->FillRandom("gaus");
  hist2->FillRandom("gaus");
  
 // hist1->Scale(1/hist1->GetEntries()); //scales by 1/#bins -> normalized
 
 // hist1->Add(hist2);
 
  *hist3 = (*hist1)/(*hist2);
  
  TCanvas *c1 = new TCanvas();
  hist3->Draw("hist"); //fixes the points after scaled
}
