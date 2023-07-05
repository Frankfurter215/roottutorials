void unifdistrndm()
{
  TRandom2 *rand = new TRandom2(0); //recommended by cern. 0 gives a random seed every time, not setting one will set the seed to 1.
  
  TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 100); //smaller bins will help to limit spread

  for(int i = 0; i <100000; i++)
  {
    double r = rand->Rndm()*100; //max number you can get is 100 bc rndm gives a # btw 0,1
    //cout << r << endl;
    hist->Fill(r);
  }
  
  TCanvas *c1 = new TCanvas();
  hist->GetYaxis()->SetRangeUser(0, 200); //this will help to limit the amount of spread in the y direction
  hist->Draw();
}
