#include<iostream>
#include<climits>
#include<queue>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;

	node() {
		left = NULL;
		right = NULL;
	}

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};


node* insertInBST(node*root, int data) {
	if(root == NULL) {
		return new node(data);
	}

	if(data <= root->data) {
		root -> left = insertInBST(root -> left, data);
	}
	else {
		root -> right = insertInBST(root -> right, data);
	}
	return root;
}

node* built() {
	int data;
	cin >> data;
	node*root = NULL;

	while(data != -1) {
		root = insertInBST(root, data);
		cin >> data;
	}
	return root;
}

void bfsModified(node*head) {

	queue<node*> q;
	q.push(head);
	// After inserting head a new level starts
	// therefore we are adding NULL for reference
	q.push(NULL);

	while(!q.empty()) {
		node*p = q.front();
		cout << p->data << " ";
		q.pop();

		if(p -> left) {
			q.push(p -> left);
		}
		if(p -> right) {
			q.push(p -> right);
		}

		// Check for New Line
		if(!q.front()) {
			q.pop();
			cout << endl;

			if(!q.empty()) {
				q.push(NULL);
			}
		}
	} 
}

void printInOrder(node*head) {

	if(head == NULL) {
		return;
	}
	printInOrder(head -> left);
	cout << head -> data << " ";
	printInOrder(head -> right);
}

class LinkedList {
public:
	node* head;
	node* tail;

	LinkedList () {
		head = NULL;
		tail = NULL;
	}
};

LinkedList flatten(node* root) {
	LinkedList LL;
	// Base Case
	if(root == NULL) {
		return LL;
	}

	// Recursive Case
	LinkedList leftLL = flatten(root -> left);
	LinkedList rightLL = flatten(root -> right);

	if(leftLL.tail)  leftLL.tail -> right = root;
	root -> right = rightLL.head;

	LL.head = leftLL.head;
	LL.tail = rightLL.tail;

	if(LL.head == NULL) {
		LL.head = root;
	} 
	if(LL.tail == NULL) {
		LL.tail = root;
	}

	return LL;
}


int main() {

	node*root = built();

	bfsModified(root);
	cout << endl;
	printInOrder(root);
	cout << endl;

	LinkedList l = flatten(root);
	node*temp = l.head;

	while(temp != NULL) {
		cout << temp->data << " --> ";
		temp = temp -> right;
	}

	return 0;
}