void beautyplots()
  {
    TH1F *hist = new TH1F("hist", "", 100, 0, 11);// the lowest value I wrote is 1, and the highest is 9, but the max value needs to be n+1
    
    TRandom2 *rand = new TRandom2(3); //3 is the seed
    
    fstream file; //open file
    file.open("data.txt", ios::out);
    
    for(int i =0; i < 1000; i++)
    {
      double r = rand->Gaus(5, 1);
      file << r << endl;
    }
    
    file.close();
    
    file.open("data.txt", ios::in);
    
    double value;
    
    while(1)
    {
      file >> value; //reads the value in data.txt
      hist->Fill(value);
      if(file.eof()) break; //once it reaches the end of the file (eof) it breaks the while loop
    }
    
    file.close(); //close file
    
    hist->SetFillColor(kRed-9); // +/- increases or decreases intensity
    
    hist->GetXaxis()->SetTitle("Distribution");
    hist->GetYaxis()->SetTitle("Entries");
   
    hist->GetXaxis()->SetTitleSize(0.05);
    hist->GetYaxis()->SetTitleSize(0.05);
    hist->GetXaxis()->SetLabelSize(0.05);
    hist->GetYaxis()->SetLabelSize(0.05);
    
    TF1 *fit = new TF1("fit", "gaus", 0, 11);// name, type of fit, range
    fit->SetLineWidth(3);
    fit->SetLineColor(kBlack);
    fit->SetLineStyle(4);
    
    fit->SetParameter(0, 40);
    fit->SetParameter(1, 5);
    fit->SetParameter(2, 1);
    
    TCanvas *c1 = new TCanvas(); //window the hist is drawn
    c1->SetTickx();
    c1->SetTicky(); //adds ticks on x and y axis
    c1->SetGridx();
    c1->SetGridy();
    hist->SetStats(0); //removes stat box
    hist->Draw();
    hist->Fit("fit", "R"); //fits whatever type of fit I have defined, "R" adopts the range of the fit
 //   hist->Fit("gaus"); //draws fit of gaus
 
    TLegend *leg = new TLegend(0.65, 0.65, 0.85, 0.85); //x-y min, max
    leg->SetBorderSize(0); //removes border
    leg->AddEntry(hist, "Measure Data", "l"); //histogram, name of entry, what should be drawn "l" =line
    leg->AddEntry(fit, "Fit Function", "l");
    leg->Draw();
    
    TLine *l = new TLine(0, 20, 11, 20);//draw it at the end so that its drawn on top not behind
    l->SetLineWidth(2);
    l->SetLineColor(kOrange);
    l->Draw();
    
    double x0 = 6.3; //obtaining information from histogram
    int bin = hist->FindBin(x0);
    double y0 = hist->GetBinContent(bin);
    
    TArrow *arr = new TArrow(8, 30, x0, y0);//x/y start/finish
    arr->SetLineWidth(3);
    arr->SetArrowSize(0.02);
    arr->SetLineColor(kBlue);
    arr->Draw();
    
    TLatex *t = new TLatex(8, 30, "Important Point");
    t->Draw();
    
    double mean = fit->GetParameter(1);
    double sigma = fit->GetParameter(2);
    
    cout << mean/sigma << endl;
  }
