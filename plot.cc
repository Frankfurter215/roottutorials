void plot()
{
  TFile *file = new TFile("output.root", "READ"); //this one reads so read instead of recreate
  
  TH1F *hist = (TH1F*)file->Get("hist"); //from the original file tut14.cc
  
  hist->Draw();
  
  //file->Close();
}
