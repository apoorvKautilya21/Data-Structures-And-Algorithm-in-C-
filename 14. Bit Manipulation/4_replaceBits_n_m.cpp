#include<iostream>
using namespace std;

int replaceBitsOfNByM(int n, int m, int i, int j) {

	int mask1 = (-1 << (j + 1));
	int mask2 = ~(-1 << i);
	int mask = mask1 | mask2;

	int ans = (n & mask);
	int m_additive = (m << i);

	return ans | m_additive;
}


int main() {

	int n = (1 << 10);	// 10000000000 or 1024
	int m = 21; 		// 10101

	int i = 2;
	int j = 6;

	//     6543210
	// 10000000000
	// 	   10101

	cout << replaceBitsOfNByM(n, m, i, j) << endl;

	cout << replaceBitsOfNByM(32, 3, 1, 2) << endl;

	return 0;
}