/*EXAMPLE OF USING THEM WITH INTS
void usinginputparams(int a, int b)
{
  cout << a*b << endl;
}
//if you compile with root 'usinginputparameters(<number>) it will output that number*/

void usinginputparams(TString filename)
{
  TFile *file = new TFile((filename));
}
