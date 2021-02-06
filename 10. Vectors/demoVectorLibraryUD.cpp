#include <iostream>
#include "vector.h"
using namespace std;

int main( ) {

	Vector<int> v;
	v.push_back(10);

	v.push_back(20);

	v.push_back(30);

	v.push_back(35);
	
	v.push_back(40);
	v.pop_back();

	v.push_back(50);
	cout << "Capacity " << v.capacity() << endl;
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << ",";
	}
	cout << "\n";


	Vector <char> c;
	c.push_back(71);

	c.push_back(72);

	c.push_back(73);

	c.push_back(74);
	
	c.push_back(75);
	c.pop_back();

	c.push_back(80);

	cout << "Capacity " << c.capacity() << endl;
	for(int i = 0; i < c.size(); i++) {
		cout << c[i] << ",";
	}





	return 0;
}