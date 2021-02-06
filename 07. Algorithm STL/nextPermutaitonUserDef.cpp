#include<iostream>
#include<algorithm>
using namespace std;

void display(int a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
}


int main() {

	int arr[] = {1,2,3,4};
	int n = sizeof(arr) / sizeof(int);

	int i = n - 2, j = 0, count=0;
	while(i >= 0) {
		sort(arr+i+1, arr+n);
		int ub = upper_bound(arr+i+1, arr+n, arr[i]) - arr;

		if(ub < n) {
			swap(arr[i], arr[ub]);
			sort(arr+i+1, arr+n);
			i = n-2;
			display(arr,n);
			count++;
		}

		else{
			i--;
		}

	}
	cout << count;





	return 0;
}



