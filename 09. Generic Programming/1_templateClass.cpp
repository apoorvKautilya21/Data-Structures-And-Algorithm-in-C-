#include<iostream>
using namespace std;
		

// template
template<typename T>
int search(T a[], int n, T key) {

	for(int p = 0; p < n; p++) {
		if(a[p] == key) {
			return p;
		}
	}
	return n;
}


int main() {

	int a1[] = {1,2,3,4,5,6};
	int n1 = sizeof(a1) / sizeof(int);

	cout << search(a1, n1, 4) << endl;

	float a2[] = {1.1,1.2,1.3,1.4};
	int n2 = sizeof(a2) / sizeof(float);
	float key = 1.2;

	cout << search(a2,n2,key) << endl;
	return 0;
}