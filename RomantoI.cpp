#include <iostream>
using namespace std;

int romanToInt(string s);

int main()
{
  string s;

  while(1)
    {
      cin >> s;

      cout << romanToInt(s) <<endl;
    }
}

int romanToInt(string s)
{
  int total = 0;
  char last = 0;

  for (string::iterator iter = s.begin(); iter != s.end(); ++iter)
    {
      switch(*iter)
	{
	case 'M':
	  if (last == 'C')
	      total += 800;
	  else
	    total += 1000;

	  break;

	case 'D':
	  if (last == 'C')
	    total += 300;
	  else
	    total += 500;
	  
	  break;

	case 'C':
	  if (last == 'X')
	    total += 80;
	  else
	    total += 100;

	  break;

	case 'L':
	  if (last == 'X')
	    total += 30;
	  else
	    total += 50;

	  break;

	case 'X':
	  if (last == 'I')
	    total += 8;
	  else
	    total += 10;

	  break;

	case 'V':
	  if (last == 'I')
	    total += 3;
	  else 
	    total += 5;

	  break;

	case'I':
	  total += 1;

	  break;
	}
      last = *iter;
    }
  return total;
}
