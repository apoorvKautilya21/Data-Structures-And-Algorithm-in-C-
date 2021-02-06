#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node* prev;

	node(int d) {
		data = d;
		next = NULL;
		prev = NULL;
	}
};

void insertAthead(node*&head, int d) {
	if(head == NULL) {
		head = new node(d);
		return;
	}
	node*p = new node(d);
	p -> next = head;
	head -> prev = p;
	head = p;
}

void insertAtTail(node*&head, int d) {
	if(head == NULL) {
		head = new node(d);
		return;
	}

	node*temp = head;
	while(temp -> next != NULL) {
		temp = temp -> next;
	}
	node*p = new node(d);
	temp -> next = p;
	p -> prev = temp;
}

void deleteAtHead(node*&head) {
	if(head == NULL) {
		return;
	}
	head = head -> next;
	delete head -> prev;
	head -> prev = NULL;
}

void deleteAtTail(node*&head) {
	if(head == NULL) {
		return;
	}

	node*tail = head;
	while(tail -> next != NULL) {
		tail = tail -> next;
	}
	tail = tail -> prev;
	delete tail -> next;
	tail -> next = NULL;
}

node* takeInput() {
	int d;
	cin >> d;
	node*head = NULL;
	while(d != -1) {
		insertAthead(head, d);
		cin >> d;
	}
	return head;
}

void showOut(node*head) {
	while(head!=NULL) {
		cout << head -> data << " -> ";
		head = head -> next;
	}
	cout << endl;
}

istream& operator>>(istream& is, node*&head) {
	head = takeInput();
	return is;
}

ostream& operator<<(ostream& os, node*&head) {
	showOut(head);
	return os;
}

int length(node*head) {
	int len = 0;
	while(head != NULL) {
		len++;
		head = head -> next;
	}
	return len;
}

void insertMid(node*&head, int d, int p) {

	if(head == NULL or p <= 0) {
		insertAthead(head, d);
		return;
	}
	if(p >= length(head)) {
		insertAtTail(head, d);
		return;
	}

	int jumps = 0;
	node*temp = head;
	while(jumps < (p - 1)) {
		jumps++;
		temp = temp -> next;
	}
	node* n = new node(d);
	n -> next = temp -> next;
	(temp -> next) -> prev = n;
	temp -> next = n;
	n -> prev = temp;
}





int main() {

	// node*head = NULL;
	// insertAtTail(head, 1);
	// insertAtTail(head, 2);
	// insertAtTail(head, 3);
	// insertAtTail(head, 4);
	// insertAtTail(head, 5);
	// showOut(head);


	// node*head = takeInput();
	// showOut(head);
	// deleteAtTail(head);
	// deleteAtHead(head);
	// showOut(head);
 
 	node*head;
 	cin >> head;
 	cout << head;

 	insertMid(head, 52, 2);
 	cout << head;



	return 0;
}