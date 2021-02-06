#include<iostream>
#include<cstring>
using namespace std;

void filterChar(int n, char a[]) {
	int j = 0;
	while(n > 0){
		int last_bit = (n&1);
		if(last_bit) {
			cout << a[j];
		}
		j++;
		n = n>>1;
	}
	cout << endl;
}

void printSubsequence(char a[]) {
	int n = strlen(a);
	for(int i = 0; i < (1 << n); i++) {
		filterChar(i, a);
	}
}

int main() {

	char a[10];
	cin >> a;
	printSubsequence(a);
	return 0;
}