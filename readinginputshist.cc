void readinginputshist()
  {
    TH1F *hist = new TH1F("hist", "Histogram", 9, 1, 10);// the lowest value I wrote is 1, and the highest is 9, but the max value needs to be n+1
    
    fstream file; //open file
    file.open("data.txt", ios::in);
    
    double value;
    
    while(1)
    {
      file >> value; //reads the value in data.txt
      hist->Fill(value);
      if(file.eof()) break; //once it reaches the end of the file (eof) it breaks the while loop
    }
    
    file.close(); //close file
    
    hist->GetXaxis()->SetTitle("Grade");
    hist->GetYaxis()->SetTitle("Entries");
   
    
    TCanvas *c1 = new TCanvas(); //window the hist is drawn
    hist->Draw();
  }
