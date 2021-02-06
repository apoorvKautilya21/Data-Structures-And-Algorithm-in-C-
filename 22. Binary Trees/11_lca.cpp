// Input:- 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
#include<iostream>
#include<queue>
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

// Assumption that both a and b are present in the tree
node* lca(node*root, int a, int b) {

	if(root == NULL) {
		return NULL;
	}

	if(root -> data == a or root -> data == b) {
		return root;
	}

	node*leftAns = lca(root -> left, a, b);
	node*rightAns = lca(root -> right, a, b);

	if(leftAns and rightAns) {
		return root;
	}

	if(leftAns) {
		return leftAns;
	}
	return rightAns;
}


int main() {

	node *head = buildTree();
	bfsModified(head);
	cout << endl;

	cout << "Lca of 4 and 7 is " << lca(head, 4, 7)->data << endl;
	cout << "Lca of 6 and 9 is " << lca(head, 6, 9)->data << endl;

	return 0;
}