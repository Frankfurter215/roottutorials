void myfirstgraph()
  {
    double x[5] = {1, 2, 3, 4, 5};
    double y[5] = {1, 4, 9, 16, 25};
    
    TGraph *gr = new TGraph(5, x, y); //entries, x, y
    
    gr->SetMarkerStyle(8);
    gr->SetMarkerSize(1);
    
    TCanvas *c1 = new TCanvas();
    gr->Draw("ALP"); //A= all things draw including axis, L= style, line, P= show points
    //C is smooth line
  }
