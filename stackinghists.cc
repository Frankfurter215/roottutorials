void stackinghists()
{
  TCanvas *c1 = new TCanvas();
  
  THStack *hstack = new THStack("hstack", "Histrogram Stack;xtitle;ytitle");
  
  TH1F *hist = new TH1F("hist", "Histogram; xtitle; ytitle", 100, -10, 10); //v useful
  TH1F *hist2 = new TH1F("hist2", "Histogram2; xtitle; ytitle", 100, -10, 10);
  
  hstack->Add(hist);
  hstack->Add(hist2);
  
  hist->FillRandom("gaus", 1e5);
  hist2->FillRandom("gaus", 1e4);
  
  hist->Draw();
  hist2->Draw("same");
  
  TCanvas *c2 = new TCanvas();
  hstack->Draw("nostack");
}
