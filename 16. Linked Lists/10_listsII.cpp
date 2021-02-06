#include<iostream>
#include<string>
#include<list>
using namespace std;

int main() {

	list<string> l{"apple", "mango", "guava", "orange"};
	l.push_back("pineapple");
	l.push_front("watermelon");
	l.sort();
	l.reverse();
	for(auto s:l) {
		cout << s << " -> ";
	}
	cout << endl;

	string f = "mango";
	l.remove(f);
	for(auto s:l) {
		cout << s << " -> ";
	}
	cout << endl;

	// To erase from a particular value
	auto it = l.begin();
	it++;
	it++;
	l.erase(it);
	for(auto s:l) {
		cout << s << " -> ";
	}
	cout << endl;

	// To insert at a particular value
	it = l.begin();
	it++;
	l.insert(it, "fruitjuice");
	for(auto s:l) {
		cout << s << " -> ";
	}
	cout << endl;

	return 0;
}