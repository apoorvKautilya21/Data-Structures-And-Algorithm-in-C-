#include <iostream> 
using namespace std;


int main() {

	int a[] = {1, 2, 4, 3, 1};
	cout << a;		// Will print the address of 1st element 

	char b[] = {'a', 'b', 'c', 'd', 'e', '\0', 'f', 'g', 'h'};
	cout << endl << b << " " << sizeof(b) / sizeof(char);		// abcde will print and num_ele will be 9

	char c[] = "Hello";
	cout << endl << c;

	char d[10] = "Hello";
	cout << endl << d << endl;

	char f[10];
	cin >> f;
	cout << f;

	return 0;
}