#include<iostream>
#include<string>
#include<list>
using namespace std;

int main() {

	list<int> l;

	list<int> l1{1,2,3,4,5};
	list<string> l2{"apple", "mango", "guava", "orange"};
	l2.push_back("pineapple");
	l2.push_front("watermelon");
	for(auto s:l2) {
		cout << s << "-->";
	}
	cout << endl;

	// Sort
	l2.sort();
	for(auto s:l2) {
		cout << s << "-->";
	}
	cout << endl;

	// Reverse
	l2.reverse();
	for(auto s:l2) {
		cout << s << "-->";
	}
	cout << endl;

	// Removal
	// from front
	cout << "Front Element " << l2.front() << endl;
	l2.pop_front();
	cout << "Back Element " << l2.back() << endl;
	l2.pop_back();
	for(auto s:l2) {
		cout << s << "-->";
	}
	cout << endl;

	for(auto it = l2.begin(); it != l2.end(); it++) {
		cout << *it << " -> "; 
	}

	return 0;
}