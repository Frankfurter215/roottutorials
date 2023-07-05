//TChain is a combo of Tfile and Ttree
//Writing the TTree.......oooOOOooo...........oooOOOooo...............oooOOOooo................
void write(TString filename)
{
  TFile *output = new TFile(filename, "RECREATE");
  
  TTree *tree = new TTree("tree", "tree");
  
  double x, y;
  
  tree->Branch("x", &x, "x/D");
  tree->Branch("y", &y, "y/D");
  
  TRandom2 *r = new TRandom2();
  
  for(int i = 0; i < 1e6; i++)
  {
    x = 1+r->Rndm()*9;
    y = x*2;
    tree->Fill();
  }
  output->Write();
  output->Close();
}
/*
//Cut function .................oooooOOOOOOOOOOoooooooo........................oooOOOooo......
void cut()
{
  TCut cut1 = "x < 5";
  TCut cut2 = "x > 6";
  
  TFile *input = new TFile("tut20.root", "read");
  
  TTree *tree = (TTree*)input->Get("tree");
  
  tree->Draw("y", cut1||cut2);//&& means and || means or
}
*/

//TChain function...........ooooooooooOOOOOOOOOOOOOoooooooooo.............oooooOOOOooooo.....
void chain()
{
  TChain *ch1 = new TChain("tree");
  
  ch1->Add("tut21a.root");
  ch1->Add("tut21b.root"); //you could double the number of data by writing the same file in twice
  
  double x;
  
  ch1->SetBranchAddress("x", &x);
  
  int entries = ch1->GetEntries();
  
  TH1F *hist = new TH1F("hist", "Histogram", 100, 1, 10);
  
  for(int i = 0; i < entries; i++)
  {
    ch1->GetEntry(i);
    hist->Fill(x);
  }
  
  TCanvas *c1 = new TCanvas();
  hist->Draw();
}

//main function ..........oooOOOooo.................oooOOOooo..................oooOOOooo....
void tchainforsplittrees()
{
  write("tut21a.root"); //creates the file with data
  write("tut21b.root");
//  cut(); //reads the tree and draws a thing based on conditions
  chain(); //combines and plots the total data from the two files
}
