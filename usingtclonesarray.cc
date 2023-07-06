//Write...................oooooooooOOOOOOOOOooooooooo....................oooOOOooo...........
void write()
{
  TClonesArray *arr = new TClonesArray("TVector3");
  TClonesArray &ar = *arr; 
  
  TFile *file = new TFile("file.root", "RECREATE");
  
  TTree *tree = new TTree("tcl", "tcl");
  tree->Branch("array", &arr);
  
  TRandom2 *rand = new TRandom2(1);
  
  for(int i = 0; i < 100; i++)
  {
    arr->Clear(); //only doing this 100 times clears a lot of memory and speeds it up
    
    for(int j = 0; j < 1000; j++)
    {
      double x = rand->Rndm();
      double y = rand->Rndm();
      double z = rand->Rndm();
      
      new (ar[j]) TVector3(x, y, z);
    }
    
    tree->Fill();
  }
  
  file->Write();
  file->Close();
}

//READ ....................................................................................
void read()
{
  TFile *file = new TFile("file.root");
  
  TTree *tree = (TTree*)file->Get("tcl");
  
  TClonesArray *arr = new TClonesArray("TVector3");
  
  tree->SetBranchAddress("array", &arr);
  
  int entries = tree->GetEntries();
  
  for(int i = 0; i < entries; i++)
  {
    tree->GetEntry(i);
    
    int lines = arr->GetEntries();
    
    for(int j = 0; j < lines; j++)
    {
      TVector3 *vec = (TVector3*)arr->At(j);
      cout << vec->X() << endl;
    }
  }
}

//MAIN...............oooooooOOOOOOOOOOooooooooo...............oooooOOOOOOOOOOOoooooo.............
void usingtclonesarray()
{
  write();
  read();
}

