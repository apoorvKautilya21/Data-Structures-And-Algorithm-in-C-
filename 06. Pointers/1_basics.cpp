#include<iostream>
using namespace std;

int main() {

	int x = 10;
	cout << &x << endl;

	float y = 10.4;
	cout << &y << endl;

	char ch = 'C';
	cout << &ch << endl;
	// explicit type casting from void* to char*
	cout << (void *) &ch << endl;

	// Pointers
	int *xptr = &x;
	cout << &x << endl;
	cout << xptr << endl;

	int *p = &x;
	char *pchar = &ch;
	cout << sizeof(p) << endl;
	cout << sizeof(pchar) << endl;
 	
}