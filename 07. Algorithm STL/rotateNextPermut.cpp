#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int a[] = {1,2,3,4,5};
	int n = sizeof(a) / sizeof(int);

	rotate(a, a+2, a+n);
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	next_permutation(a, a+n);
	cout << endl;

	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}


	return 0;
}