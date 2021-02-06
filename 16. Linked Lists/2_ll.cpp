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

node* take_input() {
	int d;
	cin >> d;
	node* head = NULL;
	while(d != -1) {
		insertAtHead(head, d);
		cin >> d;
	}
	return head;
}

node* take_input_from_file() {
	int d;
	cin >> d;
	node* head = NULL;
	while(cin >> d) {
		insertAtHead(head, d);
	}
	return head;
	// in command pront write the following command 
	// 2_ll.cpp < input.txt
}

ostream& operator<<(ostream& os, node* head) {
	print_PassByValue(head);
	return os;
}

istream& operator>>(istream& is, node*& head) {
	head = take_input();
	return is;
}

void reverse(node*& head) {
	node*curr = head;
	node*prev = NULL;
	node*n = NULL;
	while(curr != NULL) {
		// save the next pointer
		n = curr -> next;
		// make current pointer points the previous node
		curr -> next = prev;
		// Update the current and previous node
		prev = curr;
		curr = n;
	}
	head = prev;
}

node* reverse_recursive(node*&head) {
	if(head -> next == NULL or head == NULL) {
		return head;
	}

	node *shead = reverse_recursive(head -> next);
	head -> next -> next = head;
	head -> next = NULL;
	return shead;
}

node* mid_node(node*& head) {

	if(head -> next == NULL or head == NULL) {
		return head;
	}

	node*slow = head;
	node*fast = head -> next;

	while(fast -> next != NULL and fast != NULL) {
		fast = fast -> next -> next;
		slow = slow -> next;
	}
	return slow;
}





int main() {

	// I.
	// node *head = take_input_from_file();
	// print_PassByValue(head);
	
	// // II.
	// // node* head1 = take_input();
	// // node* head2 = take_input();
	// node* head3 = NULL;
	// node* head4 = NULL;
	// cin >> head3 >> head4;
	// cout << head3 << head4;

	// III.
	node *head;
	cin >> head;
	cout << head;
	reverse(head);
	cout << head;

	head = reverse_recursive(head);
	cout << head;

	return 0;
 }