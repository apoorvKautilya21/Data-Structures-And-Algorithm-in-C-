#include<iostream>
using namespace std;


class node {
public:
	int data;
	node * next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

void insertAtHead(node* &head, int d) {
	if(head == NULL) {
		head = new node(d);
		return;
	}
	node *n = new node(d);
	n -> next = head;
	head = n;

}


void print_PassByValue(node*head) {
	while(head != NULL) {
		cout << head -> data << " -> ";
		head = head -> next;
	}
	cout << endl;
	// after the function call head will again point at the start of the linked lis
}

void print_PassByReference(node*&head) {
	while(head != NULL) {
		cout << head -> data << " -> ";
		head = head -> next;
	}
	cout << endl;
	// after the function call head will again point to the NULL because actual head is 
	// passed in the function
}

int length(node *head) {
	int cnt = 0;
	while(head != NULL) {
		cnt++;
		head = head -> next;
	}
	return cnt;
}

void insertAtTail(node*&head, int d) {
	if(head == NULL) {
		head = new node(d);
		return;
	}
	node *tail = head;
	while(tail -> next != NULL) {
		tail = tail -> next;
	}
	tail -> next = new node(d);
}


void insertInMid(node*&head, int d, int p) {

	if(head == NULL or p == 0) {
		insertAtHead(head, d);
	}
	else if(p > length(head)) {
		insertAtTail(head, d);
	}
	else {
		int jumps = 1;
		node *temp = head;
		while(jumps < p) {
			temp = temp -> next;
			jumps++;
		}
		node* n = new node(d);;
		n -> next = temp -> next;
		temp -> next = n;
	}
} 

void deleteAtHead(node*& head) {
	if(head == NULL) {
		return;
	}

	node *temp = head -> next;
	delete head;
	head = temp;
}

void deleteAtTail(node*&head) {
	if(head == NULL) {
		return;
	}
	else if(head -> next == NULL) {
		delete head;
		return;
	}

	node*prev = head;
	while((prev->next) -> next != NULL) {
		prev = prev -> next;
	} 
	delete prev -> next;
	prev -> next = NULL;
}

void deleteAtMid(node*&head, int p) {
	if(head == NULL or p==0) {
		return;
	}
	if(p==1) {
		deleteAtHead(head);
		return;
	}
	if(p >= length(head)) {
		deleteAtTail(head);
		return;
	}

	int jumps = 1;
	node* prev = head;
	while(jumps < p - 1) {
		jumps++;
		prev = prev -> next;
	}
	node *n = prev -> next;
	prev -> next = n -> next;
	delete n;
}

bool search(node* head, int d) {
	while(head != NULL) {
		if(head -> data == d) {
			return true;
		}
		head = head -> next;
	}
	return false;
}

bool search_recursive(node*head, int d) {
	if(head == NULL) {
		return false;
	}
	if(head -> data == d) {
		return true;
	}
	return search_recursive(head -> next, d);
}


int main() {

	node *head = NULL;
	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);

	print_PassByValue(head);
	print_PassByValue(head);

	print_PassByReference(head);
	print_PassByReference(head);	// this won't print anything as head is now NULLA

	// this inplies print function must take head by value as in printByValue 
	// so that we can print the Linked list as many time we want

	// Now head = NULL

	cout << "-------------------\n";

	insertAtHead(head, 7);
	insertAtHead(head, 6);
	insertAtHead(head, 5);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	print_PassByValue(head);

	insertInMid(head, 3, 2);
	insertInMid(head, 4, 3);
	print_PassByValue(head);

	deleteAtHead(head);
	deleteAtTail(head);
	print_PassByValue(head);

	deleteAtMid(head, 3);
	print_PassByValue(head);

	if(search(head, 3)) {
		cout << "Element is present" << endl;
	}
	else {
		cout << "Not present" << endl;
	}

	if(search_recursive(head, 3)) {
		cout << "Element is present" << endl;
	}
	else {
		cout << "Not present" << endl;
	}
	
	return 0;
}