#include<iostream>
using namespace std;

int binary_search(int a[], int n, int key) {

	int s = 0, h = n - 1, mid;
	while(s <= h) {
		mid = (s + h) / 2;

		if (a[mid] == key) {
			return mid;
		}
		else if (a[mid] > key)
			h = mid - 1;
		else
			s = mid + 1;
	}
	return -1;
}

int main() {

	int n, key;
	int a[1000];

	cin >> n; 

	for(int i = 0 ; i < n ; i++) {
		cin >> a[i]; 
	}

	cout << endl << "Enter the element to be found ";
	cin >> key;
	cout << endl;

	int pos = binary_search(a, n, key);

	if(pos == -1) {
		cout << endl << "Element not found";
	}

	else {
		cout << "Element is at position " << pos;
	}

	return 0;
}