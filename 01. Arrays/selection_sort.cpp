#include<iostream>
using namespace std;

void selection_sort(int *a, int n) {

	for(int i = 0 ; i < n - 1 ; i++) {

		int min_ind = i;

		for(int j = i ; j < n ; j++) {

			if(a[min_ind] > a[j]) {
				min_ind = j;
			}
		}
		swap(a[i], a[min_ind]);
	}
}

int main() {

	int n, key;
	int a[1000];

	cin >> n; 

	for(int i = 0 ; i < n ; i++) {
		cin >> a[i]; 
	}

	cout << endl;
	selection_sort(a, n);
	for(int i = 0 ; i < n ; i++) {
		cout << a[i] << "  ";
	}

}