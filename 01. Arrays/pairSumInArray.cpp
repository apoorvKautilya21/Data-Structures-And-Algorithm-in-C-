#include<iostream>
using namespace std;

int main() {

	// Sorted array is given
	int a[] = {1, 3, 5, 7, 10, 11, 12, 13};
	int j = sizeof(a) / sizeof(int) - 1;
	int i = 0;
	int s = 16;

	while(i < j) {

		int currentSum = a[i] + a[j];

		if(currentSum > s) {
			j--;
		}

		else if(currentSum < s) {
			i++;
		}

		else {
			cout << a[i] << " and " << a[j] << endl;
			i++;
			j--;
		}

	}

	return 0;
}



