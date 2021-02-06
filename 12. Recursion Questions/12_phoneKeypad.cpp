#include<iostream>
using namespace std;

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generate_names(char *in, char *out, int i, int j) {
	// Base case
	if(in[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	// Recursive case
	int digit = in[i] - '0';
	// this for loop won't execute for 1 & 0 keypad numbers so we write a seprate condition for that
	// which is the cornor case
	if(digit == 1 or digit == 0) {
		generate_names(in, out, i + 1, j);
	}
	for(int k = 0; keypad[digit][k] != '\0'; k++) {
		// Including in[i]
		out[j] = keypad[digit][k]; 
		generate_names(in, out, i + 1, j + 1);
	}

}



int main() {

	char input[100];
	cin >> input;

	char output[100];
	generate_names(input, output, 0, 0);



	return 0;
}