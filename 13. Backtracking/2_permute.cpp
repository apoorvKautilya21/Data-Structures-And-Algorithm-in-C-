// Input:
// abc
// Output:
// abc, acb, bac, bca, cba, cab,
// Explaination: all permutation of abc with diffrent positions of their alphabets
// Corner case: for input abb we would have repeated outputs
#include<iostream>
using namespace std;

void permute(char in[], int i) {
	//  Base Case
	if(in[i+1] == '\0') {
		cout << in << ", ";
		return;
	}
	// Recursive case
	for(int j = i; in[j] != '\0'; j++) {
		swap(in[i], in[j]);
		permute(in, i + 1);
		swap(in[i], in[j]);
	}
}

int main() {

	char inp[10];
	cin >> inp;

	permute(inp, 0);
	return 0;
}