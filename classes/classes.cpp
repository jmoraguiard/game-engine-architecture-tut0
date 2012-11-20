#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class CRectangle {
    int *width, *height;
  public:
		CRectangle ();
		CRectangle (int,int);
		CRectangle (const CRectangle &rc);
		CRectangle (const CRectangle *rc);
		~CRectangle ();
    void set_values (int,int);
    int area () {return ((*width)*(*height));}
};

CRectangle::CRectangle () {
	width = new int;
  height = new int;
  *width = 0;
  *height = 0;
}

CRectangle::CRectangle (int a, int b) {
	width = new int;
  height = new int;
  *width = a;
  *height = b;
}

CRectangle::CRectangle (const CRectangle &rc) {
	width = new int;
  height = new int;
	*width = *(rc.width);
	*height = *(rc.height);
}

CRectangle::CRectangle (const CRectangle *rc) {
	width = new int;
  height = new int;
	*width = *(rc->width);
	*height = *(rc->height);
}

CRectangle::~CRectangle () {
  delete width;
  delete height;
}

void CRectangle::set_values (int a, int b) {
  *width = a;
  *height = b;
}

int main ()
{
  string mystr;

	CRectangle rect;
  rect.set_values (3,4);
  cout << "rect area: " << rect.area() << endl;

	// DIFFERENT TYPES OF CONSTRUCTORS
	CRectangle recta (rect), rectb;
	rect.set_values (5,6);
  rectb.set_values (5,6);
	cout << "rect area: " << rect.area() << endl;
  cout << "recta area: " << recta.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;

	// DELETE RECTANGLE AND CREATE
	CRectangle *rectc;
	rectc = new CRectangle();
	cout << "rectc area: " << rectc->area() << endl;
	delete rectc;
  rectc = new CRectangle(3, 4);
	cout << "rectc area: " << rectc->area() << endl;

	// COPY INSTANCES
	CRectangle *rectd, *recte;
	rectd = new CRectangle(4, 4);
	recte = new CRectangle(rectd);
	rectd->set_values(3, 3);
	cout << "rectd area: " << rectd->area() << endl;
	cout << "recte area: " << recte->area() << endl;

	// DELETE RECTANGLE AND CREATE
	CRectangle a, *b, *c;
  CRectangle * d = new CRectangle[2];
  b= new CRectangle;
  c= &a;
  a.set_values (1,2);
  b->set_values (3,4);
  d->set_values (5,6);
  d[1].set_values (7,8);
  cout << "a area: " << a.area() << endl;
  cout << "*b area: " << b->area() << endl;
  cout << "*c area: " << c->area() << endl;
  cout << "d[0] area: " << d[0].area() << endl;
  cout << "d[1] area: " << d[1].area() << endl;
  delete[] d;
  delete b;

  getline(cin, mystr);

  return (0);
}

