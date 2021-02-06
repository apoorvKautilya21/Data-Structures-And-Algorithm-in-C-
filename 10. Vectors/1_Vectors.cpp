#include<iostream>
#include<vector>
using namespace std;

int main() {
	//Different ways to initialize a vector
	vector<int> a;
	vector<int> b (5, 10);	// It will have 5 int values of value 10
	vector<int> c (b.begin(), b.end());   // Copy the values of b vector from [begin to end)
	vector<int> d {1,2,5,10,14};

	// Iterate over a vector
	for(int i = 0; i < c.size(); i++) {
		cout << c[i] << ",";
	}
	cout << endl; 

	for(auto itr = b.begin(); itr!=b.end(); itr++) {
		cout << *itr << ",";
	}
	cout << endl; 

	for(vector<int>::iterator itr = d.begin(); itr!=d.end(); itr++) {
		cout << *itr << ",";
	}

	cout << endl;


	// Iterate with for each loop
	for(int x:d) {
		cout << x << ",";
	}
	cout << endl;


	// Input the numbers and storing it into the 
	vector<int> v;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int no;
		cin >> no;
		v.push_back(no);
	}
	for(int x:v) {
		cout << x << ",";
	}
	cout << endl;

	// Understanding at the memory level what are the differences in the two
	cout  << v.size() << endl;
	cout << v.capacity() << endl; // size of underlying array
	cout << v.max_size() << endl; // maximum size to which the vector can expand	

	cout << d.size() << endl;
	cout << d.capacity() << endl; // size of underlying array
	cout << d.max_size() << endl; // maximum size to which the vector can expand

	return 0;
}