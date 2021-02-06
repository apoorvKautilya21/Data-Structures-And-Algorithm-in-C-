#include<iostream>
#include<queue>
using namespace std;

void transfer(queue<int> &q1, queue<int> &q2, int n) {

	for(int i = 1; i <= n; i++) {
		q2.push(q1.front());
		q1.pop();
	}
}

class Stack {

	int cs;
	queue<int> q1;
	queue<int> q2;

public:
	Stack() {
		cs = 0;
	}

	void push_back(int data) {
		if(q2.empty()) {
			q1.push(data);
		}
		else if(q1.empty()) {
			q2.push(data);
		}
		cs++;
	}

	bool isEmpty() {
		return cs == 0;
	}

	void pop_back() {
		if(isEmpty()) {
			return;
		}

		if(q2.empty()) {
			transfer(q1, q2, cs - 1);
			q1.pop();
		}
		else {
			transfer(q2, q1, cs - 1);
			q2.pop();
		}
		cs--;
	}

	int back() {
		int num;
		if(cs == 0) {
			return -1;
		}

		if(q2.empty()) {
			transfer(q1, q2, cs - 1);
			num = q1.front();
			q1.pop();
			q2.push(num);
		}
		else {
			transfer(q2, q1, cs - 1);
			num = q2.front();
			q2.pop();
			q1.push(num);
		}
		return num;
	}
};


class Stack2 {

	queue<int> q1, q2;
public:
	void push(int data) {
		q1.push(data);
	}

	void pop() {
		if(q1.empty()) {
			return;
		}

		while(q1.size() > 1) {
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();

		// swap q1, q2
		swap(q1, q2);
	}

	bool isEmpty() {
		return q1.empty();
	}

	int top() {
		if(q1.empty()) {
			return -1;
		}

		while(q1.size() > 1) {
			q2.push(q1.front());
			q1.pop();
		}
		int element = q1.front();
		q1.pop();
		q2.push(element);

		// swap q1, q2
		swap(q1, q2);
		return element;
	}
};




int main() {

	// Stack s;
	// s.push_back(1);
	// s.push_back(2);
	// s.push_back(3);

	// for(int i = 0; i <= 3; i++) {
	// 	cout << s.back() << " ";
	// 	s.pop_back();
	// }

	Stack2 s;

	for(int i = 0; i < 3; i++) {
		s.push(i + 10);
	}

	while(!s.isEmpty()) {
		cout << s.top() << " ";
		s.pop();
	}


	return 0;
}