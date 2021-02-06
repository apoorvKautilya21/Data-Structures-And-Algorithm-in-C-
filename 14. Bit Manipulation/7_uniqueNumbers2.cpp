#include<iostream>
using namespace std;

// a[] = {1,2,3,6,5,3,2,1}
// Output : - {5,6}
// since all numbers occurs twice except 5 and 6

int main() {

	int n;
	cin >> n;

	int a[100000];
	int res = 0;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		res = res ^ a[i];
	}
	// Now res = a ^ b;
	// res != 0
	int temp = res;
	int pos = 0;
	while((temp&1) != 1) {
		pos++;
		temp = temp >> 1;
	}
	// 1st set bit is at position 'pos'
	int mask = (1<<pos);
	int x = 0;
	int y = 0;

	for(int i = 0; i < n; i++) {
		if((a[i]&mask) > 0) {
			x = x ^ a[i];
		}
	}	

	y = res ^ x;

	cout << min(x,y) << " " << max(x,y) << endl;

	return 0;
}