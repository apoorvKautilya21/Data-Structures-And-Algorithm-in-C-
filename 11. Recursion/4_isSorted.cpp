#include<iostream>
using namespace std;

bool isSorted(int *arr, int n) {

	if(n == 0 or n == 1) {
		return true;
	}

	if(arr[0] <= arr[1] and isSorted(arr + 1, n - 1)){
		return true;
	}
	return false;
}

bool isSorted2(int *arr, int n, int i) {
	// Base case
	if(i == n - 1) 
		return true;

	if(arr[i] <= arr[i+1] and isSorted2(arr, n, i+1)){
		return true;
	}
	return false;
}

bool isSortedNew(int *a, int n, bool inc, bool dec) {
	// Base Case
	if(n == 0 or n == 1) {
		return true;
	}
	// Recursive Case
	if(!dec and a[0] < a[1] and isSortedNew(a+1,n-1,true,false)) {
		return true;
	}

	if(!inc and a[0] > a[1] and isSortedNew(a+1,n-1,false,true)) {
		return true;
	}

	return false;
}


int main() {
	int a[] = {1,2,3,4,5,6};
	int n = sizeof(a) / sizeof(int);
	cout << isSorted(a,n) << " " << isSorted2(a,n,0) << endl;

	int b[] = {1,2,14,4,5};
	int nb = sizeof(b) / sizeof(int);

	cout << isSortedNew(b,nb,false,false);

	return 0;
}