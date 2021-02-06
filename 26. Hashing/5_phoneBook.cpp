#include<iostream>
#include<unordered_map>
#include<cstring>
#include<vector>
using namespace std;


int main() {

	unordered_map<string, vector<string> > phoneBook;

	phoneBook["Rahul"].push_back("9011");
	phoneBook["Rahul"].push_back("9012");
	phoneBook["Rahul"].push_back("9013");
	phoneBook["Rahul"].push_back("9014");
	phoneBook["Kajal"].push_back("8012");
	phoneBook["Kajal"].push_back("8013");
	phoneBook["Kajal"].push_back("8016");

	for(auto x:phoneBook) {
		cout << x.first << " : ";
		for(string s:x.second) {
			cout << s << ",";
		}
		cout << endl;
	}

	// Finding the element
	string name;
	cin >> name;

	if(phoneBook.count(name) == 0) {
		cout << "Absent\n";
	}
	else {
		for(string s:phoneBook[name]) {
			cout << s << ",";
		}
		cout << endl;
	}



	return 0;
}