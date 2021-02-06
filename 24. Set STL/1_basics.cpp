#include<iostream>
#include<set>
using namespace std;


int main() {
	// here in sets values are stored in speific order rather than random order
	// Repeated numbers are stored only once
	// Once a value is inserted then yuo can't update them rather you can first erase them and then insert the new one
	
	// But in unordered sets order is not maintained and rest same as sets

	int a[] = {10, 9, 8, 11, 20, 21, 9, 10};
	int n = sizeof(a) / sizeof(int);

	set<int> s;
	for(int i = 0; i < n; i++) {
		s.insert(a[i]);
	}

	for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << (*it) << ",";
	}
	cout << endl;

	s.erase(10);
	auto it = s.find(21);
	s.erase(it);

	for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << (*it) << ",";
	}
	cout << endl;

	return 0;
}