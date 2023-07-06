void drawing3dobjects()
{
  TCanvas *c1 = new TCanvas();
  
  TGLViewer *view = (TGLViewer*)gPad->GetViewer3D();
  
  TGeoManager *man = new TGeoManager();
  
  TGeoVolume *top = man->MakeBox("TOP", NULL, 10, 10, 10);
  
  TGeoVolume *box1 = man->MakeBox("BOX1", NULL, 1, 1, 0.2);
  
  box1->SetLineColor(kBlue);
  
  TGeoHMatrix *trans_rot = new TGeoHMatrix("TRANSROT");
  trans_rot->RotateX(45.);
  trans_rot->SetDz(2.);
  
  TGeoVolume *tube = man->MakeTube("TUBE", NULL, 0.5, 1.0, 1.0); //inner rad, outter rad, length
  
  man->SetTopVolume(top);
  
  top->AddNode(box1, 0);
  top->AddNode(box1, 1, trans_rot);
  top->AddNode(tube, 2);
  
  man->CloseGeometry();
  
  top->Draw();
  
  TPolyLine3D *l = new TPolyLine3D();
  l->SetLineColor(kRed);
  l->SetLineWidth(6);
  l->SetPoint(0, 0, 0, 0); //#, x, y, z
  l->SetPoint(1, 1, 1, 1);
  l->SetPoint(2, 0, 0, 2);
  l->Draw("same"); //need to do same, and draw it after top volume or it wont draw right
}
