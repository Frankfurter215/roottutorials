void drawingobjects()
{
  TCanvas *c1 = new TCanvas("c1", "c1", 300, 300);  //making the canvas a square
  
  TEllipse *el = new TEllipse(0.5, 0.5, 0.1, 0.1); //xvalue, yvalue, xrad, yrad
  
  el->SetFillColor(kBlack);
  
  gSystem->Unlink("tut28.gif");
  
  for(int i = 0; i < 50; i++)
  {
    el->SetX1(0.5+i*0.01);
    el->Draw();
    c1->Update();
    c1->Print("tut28.gif");
    //usleep(250000); // 1000000 waits 1 second
  }

}
