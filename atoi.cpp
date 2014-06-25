#include <iostream>
using namespace std;

int atoi(char *str);

int main()
{
  char a[100];

  while(1)
    {
      cin >> a;
      cout << atoi(a) << endl;
    }
}

int atoi(char *str)
{
  int neg = 0;
  int start = 0;
  int ovr = 0;
  long int total = 0;

  for (int i = 0; str[i] == ' '; ++i, start = i);

  if (str[start])
    {
      if (str[start] == '-' || str[start] == '+' || (str[start] >= '0' && str[start] <='9'))
	{
	  if (str[start] == '-')
	    {
	      neg = 1;
	      ++start;
	    }
	  else if (str[start] == '+')
	    {
	      ++start;
	    }

	  for (int i = start; str[i] >= '0' && str[i] <= '9' && !ovr; ++i)
	    {
	      total = total * 10 + str[i] - '0';

	      ovr = neg ? total > (long int)INT_MAX+1 : total > (long int)INT_MAX;
	    }
	  
	  if (ovr)
	    {
	      return neg ? INT_MIN : INT_MAX;
	    }
	  else
	    {
	      return neg ? (0-total) : total;
	    }
	}
      else
	{
	  return 0;
	}
    }
  else
    {
      return 0;
    }
}
