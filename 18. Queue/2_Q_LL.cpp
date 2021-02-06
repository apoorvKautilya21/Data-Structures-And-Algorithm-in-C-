#include<iostream>
using namespace std;

template<typename T>
class node{
public:
	T data;
	node* next;

	node(T d) {
		data = d;
		next = NULL;
	}
};

template<typename T>
void insertAtEnd(node<T>*&head, node<T>*&rear, T data) {
	if(head == NULL) {
		head = new node<T>(data);
		rear = head;
		return;
	}

	rear -> next = new node<T>(data);
	rear = rear -> next;
}

template<typename T>
void deleteAtStart(node<T>*&head, node<T>*&rear) {
	if(head == NULL) {
		return;
	}
	node<T>*temp = head;
	head = head -> next;
	if(temp == rear) {
		rear = NULL;
	}
	delete temp;
}

template<typename T>
class Queue {

	node<T>* head;
	node<T>* rear;
public:
	Queue() {
		head = NULL;
		rear = NULL;
	}

	void push(T d) {
		insertAtEnd(head, rear, d);
	}

	void pop() {
		if(head == NULL) {
			return;
		}
		deleteAtStart(head, rear);
	}

	bool isEmpty() {
		return head == NULL;
	}

	T front() {
		return (head -> data);
	}
};




int main() {

	Queue<int> q;
	for(int i = 0; i <= 5; i++) {
		q.push(i);
		cout << i << endl;
	}
	q.pop();
	cout << "POP\n";

	while(!q.isEmpty()) {
		cout << q.front() << " ";
		q.pop();
	}
	
	return 0;
}