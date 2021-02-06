#include<iostream>
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

node* search(node*root, int data) {

	if(root == NULL) {
		return NULL;
	}

	if(root -> data == data) {
		return root;
	}

	else if(data < root -> data) {
		return search(root -> left, data);
	}
	else {
		return search(root -> right, data);
	}
}

node* deletionFromBST(node*root, int data) {

	if(root == NULL) {
		return NULL;
	}

	if(root -> data == data) {
		// 1. No child
		if(root -> left == NULL and root -> right == NULL) {
			delete root;
			return NULL;
		}
		// 2. 2 cases for One Child
		else if(root -> left and root -> right == NULL) {
			node*temp = root -> left;
			delete root;
			return temp;
		}
		else if(root -> left == NULL and root -> right) {
			node*temp = root -> right;
			delete root;
			return temp;
		}
		// 3. Last case for 2 child
		else {
			node*replace = root -> right;

			while(replace -> left != NULL) {
				replace = replace -> left;
			}

			root -> data = replace -> data;
			root -> right = deletionFromBST(root -> right, replace -> data);
			return root;
		}
	}
	else if(data < root -> data) {
		root -> left = deletionFromBST(root -> left, data);
		return root;
	}
	else {
		root -> right = deletionFromBST(root -> right, data);
		return root;
	}
}



int main() {

	node*head = built();

	bfsModified(head);
	cout << endl;
	printInOrder(head);
	cout << endl;

	// if(search(head, 7)) {
	// 	cout << "Present" << endl;
	// } 
	// else {
	// 	cout << "Absent" << endl;
	// }

	int s;
	cin >> s;

	head = deletionFromBST(head, s);
	bfsModified(head);
	printInOrder(head);



	return 0;
}