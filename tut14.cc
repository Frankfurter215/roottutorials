void tut14()
{
  TFile *file = new TFile("output.root", "RECREATE"); //name, flag
  
  TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 100);
  
  hist->Fill(10);
  hist->Fill(90);
  
 // hist->Write(); //writes hist to file
  file->Write(); //writes everything above very generally
  
  file->Close();
}
