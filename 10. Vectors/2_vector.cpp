#include<iostream>
#include<vector>
using namespace std;

int main() {

	vector<int> d {1,2,3,4,5,6};

	d.push_back(16);
	d.pop_back();

	d.insert(d.begin()+2,50);
	d.insert(d.begin()+3,4,100);

	d.erase(d.begin()+2);
	d.erase(d.begin()+2, d.begin()+6);

	cout << d.size() << endl;
	cout << d.capacity() << endl;

	for(int x:d) {
		cout << x << ",";
	}
	cout << endl;

	d.clear();
	cout << d.size() << endl;

	if(d.empty()) {
		cout << "Vector is empty" << endl;
	}

	vector<int> v;

	int n;
	cin >> n;
	v.reserve(1000);

	for(int i=0; i<n; i++) {
		int no;
		cin >> no;
		v.push_back(no);
		cout << "Changing capacity " << v.capacity() << endl;
	}

	for(int x:v) {
		cout << x << ",";
	}
	cout << endl;

	return 0;
}