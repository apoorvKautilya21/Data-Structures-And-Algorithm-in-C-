#include<iostream>
#include<cstring>
using namespace std;

int string2Int(char *c, int n) {

	if(n == 0) {
		return 0;
	}
	// Assumed that it will find 123
	int num = string2Int(c, n - 1);		
	// when i have 123 i will multiply it with 10 and (c[n - 1] - '0') that's last element
	num = num * 10 + (c[n - 1] - '0');	
	return num;
}

void generateAcodeStrings(char a[], char out[], int i, int j) {
	// Base Case
	if(a[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	// Recursive Case
	// taking one digit at a time
	out[j] = 'A' + a[i] - '0' - 1;
	generateAcodeStrings(a, out, i + 1, j + 1);
	// taking 2 digits at a time
	if(a[i+1] != '\0') {
		int num = (a[i + 1] - '0') + (a[i] - '0') * 10 - 1;
		if(num < 26) {
			out[j] = 'A' + num;
			generateAcodeStrings(a, out, i + 2, j + 1);
		}
	}	

}


int main() {

	char a[1000];
	cin >> a;
	char out[1000];

	generateAcodeStrings(a, out, 0, 0);



	return 0;
}