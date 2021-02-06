#include<iostream>
using namespace std;

bool isOdd(int n) {
	return (n & 1);
}

bool getithBit(int n, int i) {
	int mask = 1 << i;
	int bit = (n&mask)>0? 1:0;
	return bit;
}

int setBit(int n, int i) {
	int mask = 1 << i;
	int ans = n | mask;
	return ans;
}

int clearBit(int n, int i) {
	int mask = ~(1 << i);
	int ans = n & mask;
	return ans;
}

void updateBit(int &n, int i, int v) {
	// First we clear the bit
	int mask = ~(1<<i);
	int cleared_n = (n & mask);
	n = cleared_n | (v << i);
}

int clearLastIBits(int n, int i) {

	int mask = (-1 << (i + 1));
	return (n&mask);
} 

int clearJToIbits(int n, int i, int j) {
	int mask1 = (-1 << (j + 1));
	int mask2 = ~(-1 << (i));
	// OR
	// int mask2 = (1 << i) - 1;

	int mask = mask1 | mask2;


	return n&mask;
}

int main() {
/*
	cout << isOdd(5) << endl; 			// 1

	cout << getithBit(5, 2) << endl;	// 1

	cout << getithBit(5, 1) << endl;	// 0

	cout << setBit(5, 1) << endl;		// 7

	cout << clearBit(7, 1) << endl;		// 5

	int n = 5;
	updateBit(n, 1, 1);
	cout << n << endl;   				// 7

	updateBit(n, 1, 0);
	cout << n << endl;					// 5

	cout << (~0) << endl;				// -1
*/

	cout << clearLastIBits(15,2) << endl;		// 8
	cout << clearJToIbits(15, 1, 2) << endl;	// 9
	cout << clearJToIbits(31, 1, 3) << endl;	// 17
	cout << clearJToIbits(31, 1, 4) << endl;	// 1

	

	return 0;
}