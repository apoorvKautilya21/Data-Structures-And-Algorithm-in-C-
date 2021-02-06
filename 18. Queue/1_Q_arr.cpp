#include<iostream>
using namespace std;


class Queue {

	int *arr;
	int f, r, cs, ms;

public:
	Queue(int ds = 5) {
		ms = ds;
		arr = new int[ms];
		cs = 0;
		r = ms - 1;
		f = 0;
	}

	bool isEmpty() {
		return cs == 0;
	}

	bool isFull() {
		return ms == cs;
	}

	void push(int data) {
		if(!isFull()) {
			r = (r + 1) % ms;
			arr[r] = data;
			cs++;
		}
	}

	void pop() {
		if(!isEmpty()) {
			f = (f + 1) % ms;
			cs--;
		}
	}

	int front() {
		return arr[f];
	}
};




int main() {

	Queue q(100);

	for(int i = 1; i <= 6; i++) {
		q.push(i);
	}
	q.pop();
	q.pop();

	q.push(7);

	while(!q.isEmpty()) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}