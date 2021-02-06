#include<iostream>
#include<stack>
using namespace std;

template<typename T>
void transfer(stack<T> &s1, stack<T> &s2) {
	while(!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
}

template<typename T>
class Queue {

	stack<T> s1, s2;

public:
	void push(T data) {
		s1.push(data);
	}

	bool isEmpty() {
		return s1.empty();
	}

	void pop() {
		if(isEmpty()) {
			return;
		}
		transfer(s1, s2);
		s2.pop();
		transfer(s2, s1);
	}

	T front() {
		if(isEmpty()) {
			return -1;
		}
		transfer(s1, s2);
		int ans = s2.top();
		transfer(s2, s1);
		return ans;
	}



};



int main() {

	Queue<int> q;
	for(int i = 0; i <= 5; i++) {
		q.push(i);
	}

	q.pop();

	while(!q.isEmpty()) {
		cout << q.front() << " ";
		q.pop();
	}

}