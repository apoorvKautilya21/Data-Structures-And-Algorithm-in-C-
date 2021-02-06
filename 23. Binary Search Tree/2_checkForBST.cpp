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


bool checkForBST(node*root, int min_val, int max_val) {

	if(root == NULL) {
		return true;
	}

	if(root -> data > min_val and root -> data < max_val and checkForBST(root -> left, min_val, root -> data) and checkForBST(root -> right, root -> data, max_val)) {
		return true;
	}

	return false;
}


int main() {

	node*head = built();

	bfsModified(head);
	cout << endl;
	printInOrder(head);
	cout << endl;

	if(checkForBST(head, INT_MIN, INT_MAX)) {
		cout << "Yes, its a bst" << endl;
	}
	else {
		cout << "No, not a bst" << endl;
	}



	return 0;
}