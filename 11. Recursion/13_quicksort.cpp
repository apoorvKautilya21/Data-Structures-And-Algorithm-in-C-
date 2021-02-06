#include<iostream>
using namespace std;

int partition(int a[], int s, int e) {

	int pivot = a[e];
	int i = s - 1, j = s;
	for(; j <= e - 1; j ++) {
		if(a[j] <= pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}

	swap(a[i + 1], a[e]);

	return i + 1;
} 

void quicksort(int a[], int s, int e) {

	if(s >= e) {
		return;
	}
	// First we need to partition the array with respect to pivot
	int p = partition(a, s, e);

	quicksort(a, s, p - 1);
	quicksort(a, p + 1, e);
}

int main() {

	int a[] = {4, 1, 2, 5, 6, 3, -1};
	int n = sizeof(a) / sizeof(int) ;

	quicksort(a, 0, n - 1);
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}

	return 0;
}