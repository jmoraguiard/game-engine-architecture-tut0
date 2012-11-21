#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class CPolygon {
	protected:
		int *width, *height;
	public:
		CPolygon () {
			width = new int;
			height = new int;
		}
		~CPolygon () {
			delete width;
			delete height;
		}
		void set_values (int a, int b) {
			*width = a;
			*height = b;
		}
		virtual int area () = 0; // PURE VIRTUAL
		void print_area () {
			cout << this->area() << endl;
		}
};

class CRectangle: public CPolygon {
	public:
		int area () {
			return (*width)*(*height);
		}
};

class CTriangle: public CPolygon {
	public:
		int area () {
			return ((*width)*(*height))/2;
		}
};

int main () {
	string mystr;

	CPolygon *ppoly1 = new CRectangle;
	CPolygon *ppoly2 = new CTriangle;

	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	ppoly1->print_area();
	ppoly2->print_area();
	delete ppoly1;
	delete ppoly2;

	for(int i = 0; i < 10000000; i++) {
		ppoly1 = new CRectangle;
		ppoly2 = new CTriangle;

		ppoly1->set_values(3, 2);
		ppoly2->set_values(3, 2);
		ppoly1->print_area();
		ppoly2->print_area();
		delete ppoly1;
		delete ppoly2;
	}

	getline(cin, mystr);

	return 0;
}