// https://hack.codingblocks.com/app/practice/6/1042/problem

#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
// #include<bits/stdc++.h>
using namespace std;

string extractStringAtKey(string str, int key) {

	char *s = strtok((char*) str.c_str(), " ");
	while(key > 1) {
		s = strtok(NULL, " ");
		key --;
	}
	return (string) s;
}

int convertToInt(string s) {
	int ans = 0;
	int p = 1;

	for(int i = s.length() - 1; i >= 0; i--) {
		ans += (s[i] - '0') * p;
		p *= 10;
	}
	return ans;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
	return convertToInt(s1.second) < convertToInt(s2.second);
}

bool lexoCompare(pair<string, string> s1, pair<string, string> s2) {
	return s1.second < s2.second;
}

int main() {
	
	int n;
	cin >> n;
	cin.get();

	string s[100];
	for(int i = 0; i < n; i++) {
		getline(cin, s[i]);
	}

	int key;
	string reversal, ordering;
	cin >> key;
	cin >> reversal;
	cin >> ordering;

	pair<string, string> strPair[100];	
	for(int i = 0; i < n; i++) {
		strPair[i].first = s[i];
		strPair[i].second = extractStringAtKey(s[i], key);
	}

	if(ordering == "numeric") {
		sort(strPair, strPair + n, numericCompare);
	}

	else {
		sort(strPair, strPair + n, lexoCompare);
	}

	if(reversal == "True") {
		for(int i = 0; i < n / 2; i++) {
			swap(strPair[i], strPair[n - i - 1]);
		}
	}

	for(int i = 0; i < n; i++) {
		cout << strPair[i].first << endl;
	}

	return 0;
}