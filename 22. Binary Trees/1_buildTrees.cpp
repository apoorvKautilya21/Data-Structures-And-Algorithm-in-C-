#include<iostream>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree() {
	int d;
	cin >> d;

	if(d == -1) {
		return NULL;
	}

	node*p = new node(d);

	p -> left = buildTree();
	p -> right = buildTree();

	return p;
}

void printPre(node* head) {

	if(head == NULL) {
		// cout << "-1 ";
		return;
	}

	cout << (head->data) << " "; 
	printPre(head -> left);
	printPre(head -> right);
}

void printIn(node*head) {

	if(head == NULL) return;

	printIn(head->left);
	cout << (head -> data) << " ";
	printIn(head->right);
}

void printPost(node*head) {

	if(head==NULL) return;

	printPost(head->left);
	printPost(head->right);
	cout << (head->data) << " ";

}


void printKthLevel(node*root, int k) {

	if(root == NULL) {
		return;
	}

	if(k == 1) {
		cout << root->data << " ";
		return;
	}

	printKthLevel(root -> left, k - 1);
	printKthLevel(root -> right, k - 1);

	return;
}

int hieghtBT(node*root) {

	if(root == NULL) {
		return 0;
	}

	int lh = hieghtBT(root -> left);
	int rh = hieghtBT(root -> right);

	return max(lh, rh) + 1;
}

int main() {

	node *head = buildTree();
	printPre(head);
	cout << endl;

	printIn(head);
	cout << endl;

	printPost(head);
	cout << endl;

	int h = hieghtBT(head);
	cout << "Hieght of binary tree is given below " << h << endl;

	printKthLevel(head, 3);
	cout << endl << "Now the level order traversal is given below\n";

	for(int i = 1; i <= h; i++) {
		printKthLevel(head, i);
		cout << endl;
	}


	return 0;
}