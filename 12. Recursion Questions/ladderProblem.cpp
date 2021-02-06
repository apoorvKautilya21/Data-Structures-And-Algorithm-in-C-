#include<iostream>
using namespace std;

int noOfWays(int n, int m) {

	if(n < 0) {
		return 0; 
	}
	if(n == 0) {
		return 1;
	}
	int f_n = 0;
	for(int i = 1; i <= m; i++) {
		int num = noOfWays(n - i, m);
		if(num == 0) {
			break;
		}
		f_n += num;
	}

	return f_n;
}


int main() {

	int n, m;
	cin >> n >> m;

	cout << noOfWays(n,m);

	return 0;
}