#include<iostream>
using namespace std;

int power(int a, int n) {

	if(n == 0) {
		return 1;
	}
	return a * power(a, n-1);
}

int fastpower(int a, int n) {

	if(n == 0) {
		return 1;
	}

	int small_ans = fastpower(a, n / 2);
	small_ans *= small_ans;

	// If n is odd
	if(n&1) {
		return a * small_ans;
	}
	else{
		return small_ans;
	}
}


int main() {

	int a, n;
	cin >> a >> n;

	cout << power(a,n) << "   " << fastpower(a, n);


	return 0;
}