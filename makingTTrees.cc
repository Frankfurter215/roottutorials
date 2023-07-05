void makingTTrees()
{
  fstream file;
  file.open("data4.txt", ios::in);
  
  double x, y;
  
  TFile *output = new TFile("data4.root", "recreate");
  
  TTree *tree = new TTree("tree", "tree");
  
  tree->Branch("x", &x, "x/D"); //name, address for variable, D for double
  tree->Branch("y", &y, "y/D");
  
  while(1)
  {
    file >> x >> y;

    if(file.eof()) break;
   
    cout << x << "  " << y << endl;
    
    tree->Fill();
  }
  
  output->Write();
  
  output->Close();
  
  file.close();
}
