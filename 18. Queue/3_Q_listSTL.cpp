#include<iostream>
#include<list>
using namespace std;

class Queue {

	int cs;
	list<int> l;

public:
	Queue() {
		cs = 0;
	}

	bool isEmpty() {
		return cs == 0;
	}

	void push(int data) {
		cs++;
		l.push_back(data);
	}

	void pop() {
		if(!isEmpty()) {
			cs--;
			l.pop_front();
		}
	}	

	int front() {
		if(!isEmpty()) {
			return l.front(); 
		}
		return -1;
	}
};
 

int main() {

	Queue q;
	
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




