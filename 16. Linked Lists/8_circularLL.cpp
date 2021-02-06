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

void insertHead(node*&head, int d) {
	
	node*p = new node(d);
	node*temp = head;
	if(temp!=NULL) {
		while(temp -> next != head) {
			temp = temp -> next;
		}
		p -> next = head;
		temp -> next = p;
	}
	else {
		p -> next = p;
	}
	head = p;
}

void print(node*head) {
	if(head == NULL) {
		return;
	}
	node*temp = head;
	while(temp -> next != head) {
		cout << (temp->data) << " -> ";
		temp = temp -> next;
	}
	cout << (temp->data) << " -> " << endl;
}

node* getNode(node*&head, int d) {

	if(head == NULL) {
		return head;
	}
	node*temp = head;
	while(temp -> next != head) {
		if(temp -> data == d) {
			return temp;
		}
		temp = temp -> next;
	}
	if(temp -> data == d) {
		return temp;
	}
	return NULL;
}

void deleteNode(node*&head, int d) {

	node*del = getNode(head, d);
	if(del == NULL) {
		return;
	}

	if(del == head) {
		head = head -> next;	// is the head is deleted the significance of linked list 
		// will be demolished
	}

	node*prev = head;
	while(prev -> next != del) {
		prev = prev -> next;
	}

	prev -> next = del -> next;
	delete del;
}
 

int main() {

	node*head = NULL;
	insertHead(head, 6);
	insertHead(head, 5);
	insertHead(head, 4);
	insertHead(head, 3);
	insertHead(head, 2);
	insertHead(head, 1);
	print(head);
	deleteNode(head, 1);
	deleteNode(head, 5);
	print(head);

	return 0;
}