#include<iostream>
#include<time.h>
#include <cstdlib>
using namespace std;

int main() {

	// srand(time(NULL));
	// int num = rand();
	// cout << num;
	// cout << endl << (2 | 2 | 2 | 2 | 4);

	// int x, y;
	// // cin >> x >> y;
	// cout << ((1&3)&(4));

	int a = 4;
	int *b = &a;
	cout << b << endl;
	delete b;
	cout << b;




	return 0;
}