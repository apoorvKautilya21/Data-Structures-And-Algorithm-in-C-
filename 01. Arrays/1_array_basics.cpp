#include<iostream>
using namespace std;

// Just For initialization purpose

int main() {

	int a[10] = {1,2,3};

	for(int i = 0; i < 10; i++) {
		cout << a[i] << " ,";
	}

	cout << endl;

	int b[10];
	for(int i = 0; i < 5; i++) {
		cin >> b[i];
	}

	for(int i = 0; i < 5; i++) {
		cout << b[i] << " ,";
	}

	return 0;
}