#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class CPolygon {
	protected:
		int width, height;
	public:
		void set_values (int a, int b) {
			width = a; height = b;
		}
		virtual int area() {
			return 0;
		}
};

// ABSTRACT CLASS FOR CPolygon
class CAbstractPolygon {
	protected:
		int width, height;
	public:
		void set_values (int a, int b) {
			width = a; height = b;
		}
		virtual int area() = 0;
};

class CRectangle: public CPolygon {
	public:
		int area () {
			return width*height;
		}
};

class CTriangle: public CPolygon {
	public:
		int area() {
			return (width*height)/2;
		}
};

int main(){
	string mystr;
	
	CRectangle rect;
	CTriangle trgl;
	CPolygon poly;
	CPolygon *ppoly1;
	CPolygon *ppoly2;
	CPolygon *ppoly3;

	ppoly1 = &rect;
	ppoly2 = &trgl;
	ppoly3 = &poly;

	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	ppoly3->set_values(4, 5);

	cout << ppoly1->area() << endl;
	cout << ppoly2->area() << endl;
	cout << ppoly3->area() << endl;

	getline(cin, mystr);

	return 0;
}
