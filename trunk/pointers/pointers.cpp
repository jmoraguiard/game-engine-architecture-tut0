#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int addition (int a, int b);

int subtraction (int a, int b);

int operation (int x, int y, int (*functocall)(int,int));

int main()
{
	string mystr;

	int firstvalue, secondvalue;
  int * mypointer;

  int * p1, * p2;

  int numbers[5];
  int * p;

  int m, n;
  int (*minus)(int,int) = subtraction;

	// EXAMPLE OF POINTERS TO FUNCTIONS
  m = operation (7, 5, addition);
  n = operation (20, m, minus);
  cout <<n;

  cout << endl;

  // EXAMPLE OF ACCESSING ARRAYS WITH POINTER NOTATION
  p = numbers;  *p = 10;
  p++;  *p = 20;
  p = &numbers[2];  *p = 30;
  p = numbers + 3;  *p = 40;
  p = numbers;  *(p+4) = 50;

  for (int n=0; n<5; n++)
    cout << numbers[n] << ", ";

  cout << endl;

  // EXAMPLE OF POINTER AND REFERENCE
  mypointer = &firstvalue;
  *mypointer = 10;
  mypointer = &secondvalue;
  *mypointer = 20;
  cout << "firstvalue is " << firstvalue << endl;
  cout << "secondvalue is " << secondvalue << endl;

  // EXAMPLE OF ASSIGNING VALUES TO VARIABLES USING POINTERS
  firstvalue = 5;
  secondvalue = 15;

  p1 = &firstvalue;  // p1 = address of firstvalue
  p2 = &secondvalue; // p2 = address of secondvalue
  *p1 = 10;          // value pointed by p1 = 10
  *p2 = *p1;         // value pointed by p2 = value pointed by p1
  p1 = p2;           // p1 = p2 (value of pointer is copied)
  *p1 = 20;          // value pointed by p1 = 20

  cout << "firstvalue is " << firstvalue << endl;
  cout << "secondvalue is " << secondvalue << endl;

	getline (cin, mystr);

	return (0);

}

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}