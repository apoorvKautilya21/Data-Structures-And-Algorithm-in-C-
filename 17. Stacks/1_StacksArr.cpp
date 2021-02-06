#include<iostream>
using namespace std;

class stacks {
public:
	int arr[100];
	int top;
	const int MAXSIZE = 100;

	stacks() {
		top = -1;
	}
};

void push(stacks &s, int d) {

	if(s.top == s.MAXSIZE) {
		return;
	}
	s.top++;
	s.arr[s.top] = d;
}

int pop(stacks &s) {
	if(s.top == -1) {
		return -1;
	}
	s.top--;
	return s.arr[s.top + 1];
}

int top_element(stacks &s) {
	return s.arr[s.top];
}

void print(stacks s) {
	while(s.top != -1) {
		cout << pop(s) << ", ";
	}
	cout << endl;
}


int main() {

	stacks s;
	push(s, 4);
	push(s, 3);
	push(s, 2);
	push(s, 1);

	print(s);	// 1 ,2 , 3, 4,
	print(s);	// 1 ,2 , 3, 4,

	return 0;
}








