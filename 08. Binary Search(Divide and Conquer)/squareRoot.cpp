#include<iostream>
using namespace std;


float square_root(int n) {

	int s = 0;
	int e = n;
	float ans = -1;

	// For int part of answer
	while(s <= e) {
		int mid = (s + e) / 2;

		if(mid * mid == n) {
			return mid;
		}

		else if(mid * mid > n) {
			e = mid - 1;
		}

		else {
			ans = mid;
			s = mid + 1;
		}
	}

	// for float part of answer
	float inc = 0.1;
	for(int i = 0; i < 4; i++) {

		while(ans * ans <= n) {
			ans += inc;
		}
		ans -= inc;
		inc /= 10;
	}

	return ans;

}

int main(){

	int n;
	cin >> n;

	cout << square_root(n) << endl;

	return 0;
}