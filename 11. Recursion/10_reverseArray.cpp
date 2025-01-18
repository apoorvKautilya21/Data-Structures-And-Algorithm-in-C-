#include<iostream>
using namespace std;

void reverseArr(int *a, int start, int end) {

	if(start >= end) {
		return;
	}

	swap(a[start], a[end]);
	reverseArr(a, start+1, end-1);
}

void display(int *a, int n) {
	for(int i = 0; i < n; i++) {
		cout << a[i] << ",";
	}
}

int main() {
	int a[] = {12,2,3,533,412,314};

	int n = sizeof(a) / sizeof(int);

	reverseArr(a, 0, n - 1);
	display(a, n);
	


	return 0;
}

