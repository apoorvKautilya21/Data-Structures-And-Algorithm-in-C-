#include<iostream> 
using namespace std;

void PrintArr(int arr[], int n) {
	cout << endl;
	for(int i = 0; i < n ; i++){
		cout << arr[i] << " ";
	}
}

void bubbleSort(int a[], int n) { 

	for(int itr = 1; itr <= n-1 ; itr++) {

		int flag = 0;
		for(int j = 0; j < n - itr; j++) {

			if(a[j] > a[j+1]) {
				swap(a[j], a[j+1]);
				PrintArr(a, n);
				flag = 1;
			}
		}

		if(flag == 0){
			return;
		}
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
	bubbleSort(a, n);

	PrintArr(a,n);

	return 0;
}