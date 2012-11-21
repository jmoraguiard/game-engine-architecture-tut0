#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class CPolygon {
	protected:
		int width, height;
	public:
		void set_values (int a, int b) { 
			width=a; height=b;
		}
};

class COutput {
	public:
		void output (int i);
};

void COutput::output (int i) {
	cout << "Using multiple-inherited class method output: " << i << endl;
}

// BOTH CRectangle and CTriangle inherit from CPolygon and get width, height atributes and set_values method
class CRectangle: public CPolygon {
	public:
		int area () { 
			return width*height; 
		}
};

class CTriangle: public CPolygon, public COutput {
	public:
		int area () {
			return (width*height)/2;
		}
};

class mother {
	public:
		mother () {
			cout << "mother: no parameter" << endl;
		}
		mother (int a) {
			cout << "mother: parameter int: " << a << endl;
		}
};

// Super default constructor is called by default
class daughter: public mother {
	public:
		daughter (int a) {
			cout << "daughter: parameter int: " << a << endl;
		}
};

// But we can specify which constructor should be called
class son: public mother {
	public:
		son () {
			cout << "son: no parameter" << endl;
		}
		son (int a) : mother (a) {
			cout << "son: parameter int: " << a << endl;
		}
};

int main () {
	string mystr;
	
	CRectangle rect;
	CTriangle trgl;
	rect.set_values(3, 4);
	trgl.set_values(6, 4);
	cout << rect.area() << endl;
	trgl.output(trgl.area());

	getline(cin , mystr);

	daughter cyndia (10);
	son daniel;
	son michael (20);

	getline(cin , mystr);

	return 0;
}