#include <iostream>
using namespace std;

void reverseWords(string &s);

int main()
{
  string s;

  while(1)
    {
      getline(cin, s);

  reverseWords(s);

  cout << s << endl;
    }
}

void reverseWords(string &s)
{
  string result("");
  int left = s.length()-1;
  int charcount = 0;
  int exist = 2;

  for (; left >= 0; --left)
    {
      if (s.at(left) == ' ')
	{
	  if (charcount != 0)
	    {
	      if (exist == 1)
		result += string(" ");

	      result += s.substr(left+1, charcount);

	      exist = 0;
	    }

	  charcount = 0;
	}
      else
	{
	  ++charcount;
	  
	  if (exist != 2)
	    exist = 1;
	}
    }

  if (charcount != 0)
    {
      if (exist == 1)
	result += string(" ");
	      
      result += s.substr(0, charcount);
    }

  s = result;

 }
