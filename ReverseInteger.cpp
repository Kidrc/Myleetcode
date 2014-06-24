#include <iostream>
using namespace std;

int reverse(int x);

int main()
{
  int x;

  while(true)
    {
      cin >> x;

      cout << reverse(x) << endl;
    }

}

int reverse(int x)
{
  int result = 0;

  while(x)
    {
      result *= 10;
      result += x%10;
      x/=10;
    }

  return result;
}
