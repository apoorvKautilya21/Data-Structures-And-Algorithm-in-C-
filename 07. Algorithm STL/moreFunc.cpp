#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int a = 32;
	int b = 89;
	swap(a,b);
	cout << a << " and " << b << endl;

	cout << max(a, b) << endl;

	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(arr) / sizeof(int);
	
	reverse(arr, arr+4);

	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}


	return 0;
}