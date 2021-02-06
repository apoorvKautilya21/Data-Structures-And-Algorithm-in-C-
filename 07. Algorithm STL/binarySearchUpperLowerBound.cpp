#include<iostream>
#include<algorithm>
using namespace std;


int main() {

	int arr[] = {10,20,30,40,40,40,50,60,70,80,90};
	int n = sizeof(arr) / sizeof(int);

	int key = 40;

	bool present = binary_search(arr, arr+n, key);
	if(present) {
		cout << "Present" << endl;
	}
	else{
		cout << "Not Present" << endl;
	}

	// Lower bound and upper bound of a number
	// Lower bound finds a number in a SORTED ARRAY	which is >= key
	// Upper bound finds a number in a SORTED ARRAY	which is > key

	int *lb = lower_bound(arr, arr+n, key);
	int *ub = upper_bound(arr, arr+n, key);

	cout << "Lower Bound is " << lb - arr << endl;

	cout << "Upper Bound is " << ub - arr << endl;

	cout << "Frequency of " << key << " is " << ub - lb << endl; 

	int key2 = 41;
	lb = lower_bound(arr, arr+n, key2);
	// here key is not present hence the lower bound will show a number which >= 41 which is 50 at ind 6
	cout << "Lower Bound is " << lb - arr << endl;
	ub = upper_bound(arr, arr+n, key2);
	cout << "Occurance frequency of 41 is " << ub - lb << endl;	// which is 0

	return 0;
}

