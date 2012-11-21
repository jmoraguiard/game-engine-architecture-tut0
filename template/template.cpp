#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
T GetMax (T a, T b) {
	T result;
	result = (a>b)? a : b;
	return result;
}

class CTestClass {
	private:
		int a, b;
	public:
		void set_values (int a, int b) {
			this->a = a;
			this->b = b;
		}
		bool operator > (CTestClass);
		void print_values() {
			cout << "a: "  << a << " b: " << b << endl;
		}
};

bool CTestClass::operator> (CTestClass param) {
	return (a+b > param.a+param.b)? true : false;
}

template <class T>
class mypair {
		T values [2];
	public:
		mypair (T first, T second) {
			values[0] = first;
			values[1] = second;
		}
		T getmax();
};

template <class T>
T mypair<T>::getmax () {
	return values[0]>values[1]? values[0] : values[1];
}

int main () {
	string mystr;

	int i=5, j=6, k;
	long l=10, m=5, n;
	CTestClass a, b, c;
	a.set_values(2, 3);
	b.set_values(2, 2);

	k = GetMax<int>(i, j);
	n = GetMax<long>(l, m);
	c = GetMax(a, b);

	cout << k << endl;
	cout << n << endl;
	c.print_values();

	getline(cin, mystr);

	mypair<int> intpairs (10, 100);
	cout << "Maximum in pair: " << intpairs.getmax() << endl;

	getline(cin, mystr);

	return 0;
}