// game-engine-architecture-tut0.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main ()
{
  string mystr;

  float price=0;
  int quantity=0;

	int n;

	int * p;

  int i;

  // EXAMPLE OF CREATING MEMORY AND DELETING IT (FREEING POINTER ;))
  cout << "How many numbers would you like to type? ";
  cin >> i;
  p= new (nothrow) int[i];
  if (p == NULL)
    cout << "Error: memory could not be allocated";
  else
  {
    for (n=0; n<i; n++)
    {
      cout << "Enter number: ";
      cin >> p[n];
    }
    cout << "You have entered: ";
    for (n=0; n<i; n++)
      cout << p[n] << ", ";
    delete[] p;
  }

  cout << endl;
  getline (cin, mystr);

  // DYNAMIC MEMORY EXAMPLE NOTHROW
  int * bobby;
  bobby = new (nothrow) int [5];

  if (bobby == 0) {
  // error assigning memory. Take measures.
  }; 

  getline (cin, mystr);

  return (0);
}

