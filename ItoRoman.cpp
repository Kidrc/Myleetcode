#include <iostream>
using namespace std;

string intToRoman(int num);

int main()
{
  int num;

  while(1)
    {
      cin >> num;

      cout << intToRoman(num) <<endl;
    }
}

string intToRoman(int num)
{
  int digit = 0;

  string s("");

  digit = num/1000;

  for (int i = 0; i < digit; ++i)
    {
      s.append("M");
    }

  num = num % 1000;
  digit = num/100;

  if (digit == 9)
    {
      s.append("CM");
    }
  else if (digit == 4)
    {
      s.append("CD");
    }
  else if (digit <= 3)
    {
      for (int i = 0; i < digit; ++i)
	{
	  s.append("C");
	}
    }
  else
    {
      s.append("D");
      for (int i = 0; i < digit-5; ++i)
	{
	  s.append("C");
	}
    }

  num %= 100;
  digit = num/10;

  if (digit == 9)
    {
      s.append("XC");
    }
  else if (digit == 4)
    {
      s.append("XL");
    }
  else if (digit <= 3)
    {
      for (int i = 0; i < digit; ++i)
	{
	  s.append("X");
	}
    }
  else
    {
      s.append("L");
      for (int i = 0; i < digit-5; ++i)
	{
	  s.append("X");
	}
    }

  num %= 10;

  if (num == 9)
    {
      s.append("IX");
    }
  else if (num == 4)
    {
      s.append("IV");
    }
  else if (num <= 3)
    {
      for (int i = 0; i < num; ++i)
	{
	  s.append("I");
	}
    }
  else
    {
      s.append("V");
      for (int i = 0; i < num-5; ++i)
	{
	  s.append("I");
	}
    }

  return s;
}
