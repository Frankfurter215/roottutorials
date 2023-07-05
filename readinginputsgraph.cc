void readinginputsgraph()
  {
    TGraph *gr = new TGraph(); //empty cus we dont know how many inputs
    
    gr->SetMarkerStyle(8);
    gr->SetMarkerSize(1);
    gr->SetLineWidth(2);
    gr->SetLineColor(kRed);
    
    gr->SetTitle("Graph");
    gr->GetXaxis()->SetTitle("X Values");
    gr->GetYaxis()->SetTitle("Y Values");
    
    fstream file;
    file.open("data1.txt", ios::in);
    
    while(1)
    {
      double x, y;
      file >> x >> y;
      gr->SetPoint(gr->GetN(), x, y); //GetN takes the max number of data points included and sets this as the max
    
      if(file.eof()) break;
    }
    
    file.close();
    
    TCanvas *c1 = new TCanvas();
    gr->Draw("ALP"); //A= all things draw including axis, L= style, line, P= show points
    //C is smooth line
  }
