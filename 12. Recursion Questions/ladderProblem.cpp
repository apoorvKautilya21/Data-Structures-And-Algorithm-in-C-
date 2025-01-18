#include<iostream>
using namespace std;

int noOfWays(int n, int m) {

	if(n <= 1) {
		return n; 
	}

	int f_n = 0;
	for(int i = 1; i <= m and i <= n; i++) {
		int num = noOfWays(n - i, m);
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