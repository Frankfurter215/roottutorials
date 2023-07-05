void myfirsthist()
  {
    TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 100);//histogram, 1d, Float (name, title, #bins, start and end values)
    
    hist->Fill(10); //fills with one value at 10
    hist->Fill(90);
    
    hist->GetXaxis()->SetTitle("X Axis");
    hist->GetYaxis()->SetTitle("Y Axis");
   
    
    TCanvas *c1 = new TCanvas(); //window the hist is drawn
    hist->Draw();
  }
