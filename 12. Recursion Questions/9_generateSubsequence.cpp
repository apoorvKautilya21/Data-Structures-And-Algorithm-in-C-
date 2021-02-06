#include<iostream>
#include<cstring>
using namespace std;

void generateSubseq(char *in, char *out, int i, int j) {
	// Base Case
	if(in[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	// Recursive case
	// include the current char 
	out[j] = in[i];
	generateSubseq(in, out, i + 1, j + 1);
	// exclude that character
	generateSubseq(in, out, i + 1, j);
}


int main() {

	char ch[100];
	cin >> ch;
	char out[100];
	generateSubseq(ch, out, 0, 0);

	return 0;
}
