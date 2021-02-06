#include<iostream>
#include<string>

using namespace std;


int main() {
	string s = "Mango";
	
	// For loop
	for(int i = 0; i < s.length(); i++) {
		cout << s[i] << ",";
	}

	// Iterator
	cout << endl;
	for(auto itr = s.begin(); itr != s.end(); itr++) {
		cout << (*itr) << ",";		// itr is a pointer
	}

	// For Each loop
	cout << endl;
	for(char c:s) {
		cout << c << ",";
	}

	// Iterator - II (It can also be defined by following too)
	cout << endl;
	for(string :: iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << ",";
	}

	return 0;
}




