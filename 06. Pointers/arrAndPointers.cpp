#include<iostream>
using namespace std;

int main() {

	int arr[] = {1, 2, 3, 4, 5};
	cout << arr[2] << endl;		// it means *(arr + 2)
	int *ptr = arr;

	cout << ptr[2] << endl;		// *(ptr + 2) = *(arr + 2)

	int b[][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	cout << b[1][1] << endl;	
	// *(*(b + 1) + 1)   *(b+1) gives the 2nd row which has the address of the
	// 1-D array with size equal to number of columns.
	
	return 0;
}