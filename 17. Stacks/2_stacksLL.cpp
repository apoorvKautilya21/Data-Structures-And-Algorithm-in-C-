#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;

	node(int d) {
		data = d;
		next = NULL;
	}

};

void push(node*&head, int d) {
	if(head == NULL) {
		head = new node(d);
		return;
	}

	node*p = new node(d);
	p->next = head;
	head = p;
}

void pop(node*&head) {
	if(head == NULL) {
		return;
	}
	node*temp = head;
	head = head -> next;
	delete temp;
}

int top(node*&head) {
	if(head == NULL) {
		return -1;
	}

	return head -> data;
}










int main() {

	node*head = NULL;
	push(head, 5);
	push(head, 4);
	push(head, 3);
	push(head, 2);
	push(head, 1);

	while(head != NULL) {
		cout << top(head) << " ";
		pop(head);
	}
	cout << endl;




	return 0;
}



