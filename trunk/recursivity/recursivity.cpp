#include <iostream>
#include <string>
#include <sstream>
using namespace std;

long factorial (long a)
{
  if (a > 1)
	return (a * factorial (a-1));
  else
	return (1);
}

int main ()
{ 
  string mystr;
  long number;

  // EXAMPLE OF RECURSIVTY
  cout << "Please type a number: ";
  getline (cin,mystr);
  stringstream(mystr) >> number;
  cout << number << "! = " << factorial (number) << endl;

  getline(cin, mystr);

  return (0);
}