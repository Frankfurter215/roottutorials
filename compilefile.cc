#include "TStopwatch.h"
#include "TRandom2.h"
#include <iostream>

using namespace std;

void compilefile()
{
  TStopwatch t;
  
  TRandom2 *r = new TRandom2();
  
  double x = 0;
  
  for(int i =0; i < 1e9; i++)
  {
    x += r->Rndm();
  }
  
  cout << x << endl;
  
  t.Print();
  //compile this by doing root compilefile.cc+ when you run it
}
