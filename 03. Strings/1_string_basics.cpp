#include<iostream>
#include<string>
using namespace std;

int main() {

	string s0;      // Empty string
	string s1("Hello");

	string s2 = "hello World";
	string s3 = s2;

	string s4(s3);

	char a[] = {'a', 'b', 'c', '\0'};
	string s5(a);

	cout << s0 << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

	if(s0.empty()) {
		cout << "Empty sting" << endl;
	}

	s0.append("I love c++");
	cout << s0 << endl;	
	s0 += " and python";
	cout << s0 << endl;

	// Remove
	cout << s0.length() << endl;
	s0.clear();
	cout << s0.length() << endl;

	// Compare
	s0 = "Apple";
	s1 = "Mango";
	cout << s0.compare(s1) << endl;  // x (some number) (s0 - s1)
	cout << s1.compare(s0) << endl;  // -x (-ve of that number)   (s1 - s0)
	cout << s0.compare(s0) << endl;  // 0  (zero)

	if(s1 > s0) {
		cout << "Mango is lexigraphically greater than apple\n";
	}

	// Find a substring 
	string s = "I want to have an apple juice";
	int idx = s.find("apple");
	cout << idx;
	cout << endl << s;
	// remove a string
	string word = "apple";
	int len = word.length();
	s.erase(idx, len+1);			// +1 for removing the space
	cout << endl << s;

	return 0;
}




