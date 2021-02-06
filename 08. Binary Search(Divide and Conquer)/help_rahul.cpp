// https://hack.codingblocks.com/app/practice/6/1044/problem
#include<iostream>
using namespace std;

int searchNumRotateArr(int a[], int n, int key) {

	int s = 0, e = n - 1;

	while(s <= e) {
		int mid = (s + e) / 2;

		if(a[mid] == key) {
			return mid;
		}

		else if(a[mid] >= a[0]) {
			if(key <= a[mid] and key >= a[s]) {
				e = mid - 1;
			}

			else {
				s = mid + 1;
			}
		}

		else if(a[mid] <= a[n-1]) {
			if(key >= a[mid] and key <= a[e]) {
				s = mid + 1;
			}

			else {
				e = mid - 1;
			}
		}

	}

	return -1;
}



int main() {

	int a[] = {4,5,1,2,3};
	int key = 2;
	int n = sizeof(a) / sizeof(int);

	cout << searchNumRotateArr(a, n, key) << endl;

	return 0;
}