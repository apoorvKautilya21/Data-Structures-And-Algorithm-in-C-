#include<iostream>
#include<algorithm>
using namespace std;

void PrintArr(int arr[], int n) {
	cout << endl;
	for(int i = 0; i < n ; i++){
		cout << arr[i] << " ";
	}
}

bool compare(int a, int b) {
	cout << "Compare " << a << " and " << b << endl;
	return a > b;
}

int main() {

	int n;
	int a[1000];

	cin >> n; 

	for(int i = 0 ; i < n ; i++) {
		cin >> a[i]; 
	}

	cout << endl;
	sort(a, a+n, compare);
	PrintArr(a, n);

	return 0;
}



