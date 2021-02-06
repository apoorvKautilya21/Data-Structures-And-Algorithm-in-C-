#include<iostream>
using namespace std;

int storeAllOccur(int *a, int n, int i, int *out, int j, int key) {
	//  Base case
	if(i == n) {
		return j;
	}
	// Recursive Case
	if(a[i] == key){
		out[j] = i;
		return storeAllOccur(a, n, i + 1, out, j + 1, key);
	}
	return storeAllOccur(a, n, i + 1, out, j, key);
}


void allOccur(int *a, int i, int n, int key) {

	if(i == n) {
		return;
	}

	if(a[i] == key) {
		cout << i << ",";
	}
	
	allOccur(a, i+1, n, key);
}


int lastOccur(int *a, int n, int key) {

	if(n == 0) {
		return -1;
	}

	int i = lastOccur(a + 1, n - 1, key);
	if(i == -1) {
		if(a[0] == key) {
			return 0;
		}
		else {
			return -1;
		}
	}
	return i + 1;
}


int firstOccur(int *a, int n, int key) {
	static int i = -1;
	i++;
	if(n == 0){
		return -1;
	}

	if(a[0] == key) {
		return i;
	}
	
	return firstOccur(a + 1, n - 1, key);
}

int firstOccurMod(int *a, int n, int key) {

	if(n == 0) {
		return -1;
	}

	if(a[0] == key) {
		return 0;
	}

	int i = firstOccur(a + 1, n - 1, key);
	if(i == -1) {
		return -1;
	}

	return i + 1;
}

int main() {

	int a[] = {1,2,3,4,7,8,1,2,7,7,4,313,3,64};
	int n = sizeof(a) / sizeof(int);
	int key = 7;

	cout << firstOccurMod(a, n, key) << endl;
	cout << lastOccur(a, n, key) << endl;
	allOccur(a, 0, n, key);


	int out[100];
	int j = storeAllOccur(a, n, 0, out, 0, key);
	cout << endl;
	for(int i = 0; i < j; i++) {
		cout << out[i] << ",";
	}

	return 0;
}