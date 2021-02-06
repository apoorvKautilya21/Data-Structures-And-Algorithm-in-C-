#include<iostream>
using namespace std;

int merge(int *a, int s, int e) {

	int mid =(s+e) / 2;
	int cxy = 0;
	int i = s, j = mid + 1, k = s;
	int temp[100];

	while(i <= mid and j <= e) {

		while(i <= mid and a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		if(i <= mid) {
			cxy += mid - i + 1;
			temp[k++] = a[j++];
		}
	}

	while(i <= mid) {
		temp[k++] = a[i++];
	}
	while(j <= e) {
		temp[k++] = a[j++];
	}

	for(int i = s; i <= e; i++) {
		a[i] = temp[i];
	}

	return cxy;
}


int inversionCount(int *a, int s, int e) {
	// Base case
	if(s >= e) {
		return 0;
	}

	int mid = (s+e) / 2;
	int x = inversionCount(a, s, mid);
	int y = inversionCount(a, mid + 1, e);
	int z = merge(a, s, e);
	

	return z + x + y;
}



int main() {

	int a[] = {1,5,2,6,3,0};
	int n = sizeof(a) / sizeof(int);

	cout << inversionCount(a, 0, n - 1);

	return 0;
}
