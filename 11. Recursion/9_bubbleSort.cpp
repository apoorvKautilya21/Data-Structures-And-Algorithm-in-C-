#include<iostream>
using namespace std;

void bubble_sort(int *a, int n) {

	if(n == 1) {
		return;
	}

	for(int j = 0; j < n; j++) {
		if(a[j] > a[j + 1]){
			swap(a[j], a[j + 1]);
		}
	}
	bubble_sort(a, n - 1);
}

void bubble_sort_recursion(int *a, int n, int j) {

	if(n == 1) {
		return;
	}

	if(j == n - 1){
		return bubble_sort_recursion(a, n - 1, 0);
	}

	if(a[j] > a[j + 1]){
		swap(a[j], a[j + 1]);
	}
	return bubble_sort_recursion(a, n, j + 1);
}



int main() {

	int a[] = {5,1,3,4,2};
	int n = 5;

	bubble_sort_recursion(a, n, 0);
	for(int i =0; i< n; i++) {
		cout << a[i] << ",";
	}
}