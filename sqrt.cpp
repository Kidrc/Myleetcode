#include <iostream>
using namespace std;

int sqrt(int a);

int main()
{
  int a;

  while(1)
    {
      cin >> a;

      cout << sqrt(a) << endl;
    }
}

int sqrt(int x)
{
  double m = 1;
  double mul = m*m;

  if (x == 0)
    {
      return 0;
    }
  for (; mul-x > 1 || mul < x-1; m = (mul+x)/2/m)
    {
      mul = m*m;
    }

  return m;
}
