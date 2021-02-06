#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

int main() {

	unordered_map<string, int> mp;

	// 1. insert
	mp.insert(make_pair("Mango", 150));
	pair<string, int> p("Apple", 130);
	mp.insert(p);
	mp["Banana"] = 25;

	// Update
	string fruit = "Banana";
	mp[fruit] += 22;

	// Finding
	auto it = mp.find(fruit);
	if(it == mp.end()) {
		cout << "Not Found\n";
	}
	else {
		cout << "Price is " << mp[fruit] << endl;
	}

	// Erasing the key
	mp.erase(fruit);

	if(mp.count(fruit) == 0) {
		cout << "Not Found\n";
	}
	else {
		cout << "Price is " << mp[fruit] << endl;
	}

	mp["Lichi"] = 110;
	mp["Pineapple"] = 60;
	mp["Grapes"] = 250;

	cout << endl;
	for(auto it = mp.begin(); it != mp.end(); it++) {
		cout << it -> first << " : " << it -> second << endl; 
	}
	cout << endl;
	for(auto x : mp) {
		cout << x.first << " : " << x.second << endl;
	}
	
	return 0;
}