#include<iostream>
#include<set>
using namespace std;


typedef multiset<int>::iterator It;

int main() {
	// Underlying data structures is BST

	int a[] = {10, 20, 10, 10, 30, 40, 20, 30, 50, 30, 32};
	int n = sizeof(a) / sizeof(int);
	multiset< int > m(a, a + n);

	// Erase
	m.erase(20);

	// Insert 80
	m.insert(80);


	// Iterate
	for(int x:m) {
		cout << x << " ";
	}
	cout << endl;

	// Count of each element
	cout << m.count(10) << endl;

	// find
	auto it = m.find(30);
	cout << *(it) << endl;

	it = m.find(45);
	cout << *(it) << endl;	// will be n-1 since element is not present

	// Equal range
	pair<It, It> range = m.equal_range(30);

	for(auto it = range.first; it != range.second; it++) {
		cout << *(it) << " - ";
	}
	cout << endl;

	for(auto it = m.lower_bound(30); it != m.upper_bound(80); it++) {
		cout << *(it) << " - ";
	}
	cout << endl;

	return 0;
}