void histswithTProfile()
{
  TCanvas *c1 = new TCanvas();
  
  TProfile *hprof = new TProfile("hprof", "Profile", 100, 0, 10, "S");
  /*name, title, #xbins, xmin/max, no binning in ydirection, S sets error bars to the stddev
    hprof->Fill(1, 4);
    hprof->Fill(1, 6); //tprofile will calc a mean btw 4 and 6
    */
    
  TRandom2 *rand = new TRandom2();
  
  for(int i = 0; i < 1000; i++)
  {
    hprof->Fill(rand->Rndm()*10, rand->Rndm());
  }
  hprof->Draw();
}
