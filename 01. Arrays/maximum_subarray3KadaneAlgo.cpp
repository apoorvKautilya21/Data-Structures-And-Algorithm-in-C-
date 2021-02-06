// Kadane Algorithm
#include<iostream>
#include<climits>
using namespace std;


int main() {

	int a[1000], n;

	cin >> n;
	cin >> a[0];

	for(int i = 1; i < n; i++) {
		cin >> a[i];
	}

	int cs = 0, ms = 0, left = 0, rm = 0, lm = 0;
	for(int i = 0; i < n; i++) {

		cs += a[i];

		if(cs < 0){
			cs = 0;
			left = i + 1;
		}

		if(cs > ms) {
			ms = cs;
			rm = i;
			lm = left;
		}				
	}

	cout << "Maximum sum is " << ms << endl;

	for (int i = lm; i <= rm; i++) 
		cout << a[i] << ",";

	return 0;
}