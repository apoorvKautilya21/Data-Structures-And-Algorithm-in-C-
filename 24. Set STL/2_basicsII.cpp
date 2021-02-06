#include<iostream>
#include<climits>
#include<set>
using namespace std;

int main() {

	set< pair<int, int> > s;
	s.insert(make_pair(5, 1));
	s.insert(make_pair(5, 3));
	s.insert(make_pair(10, 5));
	s.insert(make_pair(10, 1));
	s.insert(make_pair(30, 12));
	s.insert(make_pair(40, 1));
	s.insert(make_pair(20, 1));
	s.insert(make_pair(20, 14));
	s.insert(make_pair(20, 5));

	s.erase(s.find(make_pair(5, 3)));

	for(auto it:s) {
		cout << it.first << " and " << it.second << endl;
	}
	cout << endl;

	auto it = s.lower_bound(make_pair(20, 7));
	cout << it -> first << " and " << it -> second << endl;

	it = s.upper_bound(make_pair(20, 7));
	cout << it -> first << " and " << it -> second << endl;

	// Suppose i want the upper bound of (20, ..) not as first element as 20 rather i want first element changed to a higher value 
	it = s.upper_bound(make_pair(20, INT_MAX));
	cout << it -> first << " and " << it -> second << endl;

	return 0;
}