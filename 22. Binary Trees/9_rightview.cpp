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


void rightViewDfs(node*head, int h) {
	static int max_height = 1;
	if(head == NULL) {
		return;
	}

	if(h == max_height) {
		cout << head->data << " ";
		max_height++;
	}
	// first go to right to get the first right element with h = max height
	rightViewDfs(head->right, h + 1);
	rightViewDfs(head->left, h + 1);
}

void rightViewBfs(node*head) {
	queue<node*> q;
	q.push(head);
	q.push(NULL);

	while(!q.empty()) {

		node*f = q.front();
		q.pop();

		if(f -> left) {
			q.push(f -> left);
		}
		if(f -> right) {
			q.push(f -> right);
		}

		if(q.front() == NULL) {
			cout << f->data << " ";
			q.pop();
			if(!q.empty()) {
				q.push(NULL);
			}
		}
	}
}



int main() {

	node *head = buildTree();
	cout << endl;
	bfsModified(head);
	cout << endl;

	rightViewDfs(head, 1);
	cout << endl;
	rightViewBfs(head);


	return 0;
}