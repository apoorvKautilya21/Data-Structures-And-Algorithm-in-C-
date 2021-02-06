#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&s, int t) {
	if(s.empty()) {
		s.push(t);
		return;
	}

	int tp = s.top();
	s.pop();
	insertAtBottom(s, t);
	s.push(tp);
}

void reverse(stack<int>&s) {
	if(s.empty()) {
		return;
	}
	// here pop out the top most element and insert it at the end of the stack
	int top_ele = s.top();
	s.pop();
	// reverse the stack after poping out the topmost element
	reverse(s);
	// to push in the top_ele in the bottom of the stack
	insertAtBottom(s, top_ele);
}

void print(stack<int> s) {

	while(!s.empty()) {
		cout << s.top() << ",";
		s.pop();
	}
	cout << endl;
}

int main() {

	stack<int> s;
	for(int i = 0; i <= 5; i++) {
		s.push(i);
	}

	reverse(s);
	print(s);






	return 0;
}