void findingroots()
{
  TF1 *f = new TF1("f", "[0]*cos([1]+x)", -5, 5);
  
  f->SetParameter(0, 1);
  f->SetParameter(1, 1);
  
  TCanvas *c1 = new TCanvas();
  f->Draw();
  
  ROOT::Math::RootFinder finder;
  finder.Solve(*f, -5, 0);
  
  double solution = finder.Root();
  
  finder.Solve(*f, 0, 5);
  
  double sol2 = finder.Root();
  
  cout << "sol1: " << solution << "   " << "sol2: " << sol2 << endl;
  
  TLine *l1 = new TLine(-5, 0, 5, 0);
  TLine *l2 = new TLine(solution, -1, solution, 1);
  TLine *l3 = new TLine(sol2, -1, sol2, 1);
  l1->Draw();
  l2->Draw();
  l3->Draw();
}
