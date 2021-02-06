#include<iostream>
using namespace std;

void generateBracketCombnations(char *out, int i, int io, int ic, int n) {
	// Base Case
	if(i == 2 * n) {
		out[i] = '\0';
		cout << out << endl;
		return;
	}
	// Recursive case
	// Open bracket
	if(io < n) {
		out[i] = '(';
		generateBracketCombnations(out, i + 1, io + 1, ic, n);
	}
	// Closed bracket
	if(io > ic and ic < n) {
		out[i] = ')';
		generateBracketCombnations(out, i + 1, io, ic + 1, n);
	}
}



int main () {

	int n;
	cin >> n;
	char out[100];

	generateBracketCombnations(out, 0, 0, 0, n);
	return 0;
}