#include<iostream>
using namespace std;

class Complex {
	int real;
	int img;

public:
	Complex() {
		real = 0;
		img = 0;
	}

	Complex(const int r, const int i) {
		real = r;
		img = i;
	}
	// Copy Constructor 
	// it is present by default
	// since we are only shallow copy here because no dynamically defined data types

	void setReal(const int r) {
		real = r;
	}

	void setImg(const int i) {
		img = i;
	}

	int getReal() const {
		return real;
	}

	int getImg() const {
		return img;
	}

	void print() const {
		if(img > 0) {
			cout << real << " + i" << img << endl;
		}
		else {
			cout << real << " - i" << -img << endl; 
		}
	}

	void add(const Complex &x) {
		real += x.real;
		img += x.img;
	}

	void operator+(const Complex &x) {
		real += x.real;
		img += x.img;
	}

	void operator!() {
		img *= -1;
	}

	int operator[] (string s) {
		if(s == "real") {
			return real;
		}
		else if(s == "img") {
			return img;
		}
		return 0;
	}
};

istream& operator>>(istream &is, Complex &c) {
	int r, i;
	// Method - I
	// cin >> r >> i;
	// Method - II
	is >> r >> i;
	c.setReal(r);
	c.setImg(i);
	return is;
}

ostream& operator<<(ostream &os, Complex &c) {
	c.print();
	return os;
}

int main() {

	Complex c1(4, 6), c2;
	c2.setReal(3);
	c2.setImg(-4);

	cout << endl << "c1 ";
	c1.print();
	cout << endl << "c2 ";
	c2.print();

	cout << "-----------------------\n";

	c1.add(c2);
	cout << endl << "c1 ";
	c1.print();
	cout << endl << "c2 ";
	c2.print();

	cout << "-----------------------\n";

	!c2;
	c1 + c2;
	cout << endl << "c1 ";
	c1.print();
	cout << endl << "c2 ";
	c2.print();

	cout << endl << c1["real"];

	cout << "-----------------------\n";

	Complex d1, d2;
	cin >> d1 >> d2;
	cout << d1 << d2;

	return 0;
}