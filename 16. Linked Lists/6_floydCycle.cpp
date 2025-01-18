// Cycle Detection method
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

ostream& operator<<(ostream& os, node* head) {
	print_PassByValue(head);
	return os;
}

istream& operator>>(istream& is, node*& head) {
	head = take_input();
	return is;
}

node* merge(node*a, node*b) {
	if(a == NULL) {
		return b;
	}
	else if(b == NULL) {
		return a;
	}

	node *c = NULL;
	if((a->data) > (b->data)) {
		c = b;
		c -> next = merge(a, b -> next);
	}
	else {
		c = a;
		c -> next = merge(a->next, b);
	}
	return c;
}

node* mid_node(node* head) {

	if(head -> next == NULL or head == NULL) {
		return head;
	}

	node*slow = head;
	node*fast = head -> next;

	while(fast != NULL and fast -> next != NULL) {
		fast = (fast -> next) -> next;
		slow = slow -> next;
	}
	return slow;
}


node* mergeSort(node* head) {
	// Base Case
	if(head == NULL or head -> next == NULL) {
		return head;
	}
	// Recursive Case
	// 1. Divide the ll
	node* mid = mid_node(head);

	node*a = head;
	node*b = mid -> next;
	mid -> next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	return merge(a, b);
}

bool iscyclePresent(node*head) {
	if(head == NULL or head -> next == NULL) {
		return false;
	} 
	node*slow = head;
	node*fast = head;
	while(fast!=NULL or fast->next!=NULL) {
		fast = fast -> next -> next;
		slow = slow -> next;
		if(slow == fast) {
			return true;
		}
	}
	return false;
}

void removeCycle(node*& head) {
	if(head == NULL or head -> next == NULL) {
		return;
	} 

	node*slow = head;
	node*fast = head;
	node*prev;
	while(fast!=NULL or fast->next!=NULL) {
		fast = fast -> next -> next;
		prev = slow;
		slow = slow -> next;
		if(slow == fast) break;
	}
	
	slow = head;
	while(slow!=fast) {
		prev = fast;
		fast = fast -> next;
		slow = slow -> next;
	}

	prev -> next = NULL;
}


int main() {

	node*head1;
	node*head2;
	cin >> head1 >> head2;
	cout << head1 << head2;

	node*tail1 = head1;
	node*tail2 = head2;
	while(tail1 -> next != NULL) {
		tail1 = tail1 -> next;
	}

	while(tail2 -> next != NULL) {
		tail2 = tail2 -> next;
	}
	tail2 -> next = head2;
	tail1 -> next = head2;

	cout << iscyclePresent(head1) << endl;

	removeCycle(head1);
	cout << head1;


	return 0;
 }