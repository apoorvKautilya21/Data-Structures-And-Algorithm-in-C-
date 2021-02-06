#include<iostream>
#include<algorithm>
using namespace std;


int main() {

	int arr[] = {1,2,3,4};
	int n = sizeof(arr) / sizeof(int);
	int ub = upper_bound(arr, arr+n, 10) - arr;
	cout << ub;






	return 0;
}