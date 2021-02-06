#include<iostream>
using namespace std;

bool binarySearch(int *arr, int key, int s, int e) {

	if(s > e) {
		return false;
	}

	int mid = (s + e) / 2;
	if(arr[mid] == key) {
		return true;
	}
	if(arr[mid] > key) {
		return binarySearch(arr, key, s, mid - 1);
	}
	else{
		return binarySearch(arr, key, mid+1, e);
	}

}


int main() {

	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(a)/sizeof(int);
	int key = 15;
	cout << binarySearch(a,key,0,n-1);


	return 0;
}