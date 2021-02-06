#include<iostream>
using namespace std;

void PrintArr(int arr[], int n) {
	cout << endl;
	for(int i = 0; i < n ; i++){
		cout << arr[i] << " ";
	}
}

void insertion_sort(int a[], int n) {

	for(int i = 1; i < n; i++) {
		
		int temp = a[i];
		int j = i;
		while(j > 0 and a[j-1] > temp) {

			a[j] = a[j-1];
			// PrintArr(a,n);
			j--;
		}
		a[j] = temp;
	}

}


int main() {

	int n;
	int a[1000];

	cin >> n; 

	for(int i = 0 ; i < n ; i++) {
		cin >> a[i]; 
	}

	cout << endl;
	insertion_sort(a, n);
	PrintArr(a, n);

	return 0;
}

