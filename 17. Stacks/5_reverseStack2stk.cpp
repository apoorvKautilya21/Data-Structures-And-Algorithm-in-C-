#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> s) {

	while(!s.empty()) {
		cout << s.top() << ",";
		s.pop();
	}
	cout << endl;
}

void transfer(stack<int>&s1, stack<int>&s2) {
	while(!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
}


int main() {

	stack<int> s;
	for(int i = 0; i <= 5; i++) {
		s.push(i);
	}

	print(s);
	print(s);

	stack<int> s1;
	stack<int> s2;
	
	transfer(s, s1);
	transfer(s1, s2);
	transfer(s2, s);
	print(s);

	return 0;
}