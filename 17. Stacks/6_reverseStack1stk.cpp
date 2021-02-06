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

void transfer(stack<int>&s1, stack<int>&s2, int n) {
	for(int i = 0; i < n; i++) {
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

	int n = s.size();

	for(int i = 0; i < n; i++) {
		// Store the topmost element
		int temp = s.top();
		// and then pop it out too
		s.pop();
		// transfer n - i - 1 elements from s to s1
		transfer(s,s1,n-i-1);
		// push the temp to original stack
		s.push(temp);
		// transfer n - i - 1 elements from s1 to s
		transfer(s1,s,n-i-1);
	}
	print(s);




	return 0;
}