#include<iostream>
#include<cstring>
using namespace std;

int main() {

	char a[][10] = {"abc", "bcd", "ffbdds"};

	cout << a[0] << endl;
	cout << a[1] << endl;

	char b[100][100];
	int n;		// Number of strings
	cin >> n;
	cin.get();

	for(int i = 0; i < n; i++) {
		cin.getline(b[i], 100);
	}

	for(int i = 0; i < n; i++) {
		cout << b[i] << endl;
	}

	return 0;
}