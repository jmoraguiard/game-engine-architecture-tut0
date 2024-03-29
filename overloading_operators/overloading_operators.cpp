// vectors: overloading operators example
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class CVector {
  public:
    int x,y;
    CVector () { x=0; y=0; };
    CVector (int,int);
    CVector operator + (CVector);
};

CVector::CVector (int a, int b) {
  x = a;
  y = b;
}

CVector CVector::operator+ (CVector param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return (temp);
}

int main () {
	string mystr;

  CVector a (3,1);
  CVector b (1,2);
  CVector c;
  c = a + b;
  cout << c.x << "," << c.y;

	getline(cin, mystr);

  return 0;
}