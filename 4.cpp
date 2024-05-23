#include <iostream>
using namespace std;

void f (const double &i)
{
  const_cast<double&>(i) = 100;
}

int main()
{
  double x = 98.6;
  cout << x << endl;
  f(x);
  cout << x << endl;

  return 0;
}

