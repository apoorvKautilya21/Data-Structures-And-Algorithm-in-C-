// Input:
// abc
// Output:
// abc, acb, bac, bca, cba, cab, 
#include<iostream>
#include<set>
#include<string>
using namespace std;

void permute(char in[], int i, set<string> &s) {
	//  Base Case
	if(in[i+1] == '\0') {
		// cout << in << ", ";
		string t(in);
		s.insert(t);
		return;
	}
	// Recursive case
	for(int j = i; in[j] != '\0'; j++) {
		swap(in[i], in[j]);
		permute(in, i + 1, s);
		swap(in[i], in[j]);
	}
}

int main() {

	char inp[10];
	cin >> inp;
	set<string> s;
	permute(inp, 0, s);
	for(auto str:s){
		cout << str << ", ";
	}
	return 0;
}