#include<iostream>
using namespace std;


int first_occurence(int a[], int n, int key) {
	int s = 0;
	int e = n - 1;
	int ans = -1;

	while(s <= e) {
		int mid = (s + e) / 2;

		if(a[mid] == key) {
			ans = mid;
			e = mid - 1;
		}

		else if(a[mid] > key) {
			e = mid - 1;
		}

		else {
			s = mid + 1;
		}
	}

	return ans;

}

int last_occurence(int a[], int n, int key) {
	int s = 0;
	int e = n - 1;
	int ans = -1;

	while(s <= e) {
		int mid = (s + e) / 2;

		if(a[mid] == key) {
			ans = mid;
			s = mid + 1;
		}

		else if(a[mid] > key) {
			e = mid - 1;
		}

		else {
			s = mid + 1;
		}
	}

	return ans;
}

int main() {

	int a[] = {1,2,3,5,6,8,8,8,8,8,9,10,19,19,20,40};
	int n = sizeof(a) / sizeof(int);

	cout << first_occurence(a, n, 8) << endl;
	cout << last_occurence(a, n, 8) << endl; 

	return 0;
}





