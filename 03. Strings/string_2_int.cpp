// comvert "055" to 55(int)

#include<iostream>
#include<string>
using namespace std;

void str2int(string s) {

	int ans = 0;
	for(int i = 0; i < s.length(); i++) {
		ans = ans*10 + int(s[i] - '0');
	}

	cout << ans << endl;

}

int main() {

	string s[3];

	for(int i = 0; i < 3; i++) {
		getline(cin, s[i]);
	}

	for(int i = 0; i < 3; i++) {
		str2int(s[i]);
	}

	return 0;
}