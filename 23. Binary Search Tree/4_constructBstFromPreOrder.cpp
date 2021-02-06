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


node* constructBstFromPre(int pre[], int n, int min_val, int max_val) {

	static int i = 0;
	// Base Case
	if(i >= n) {
		return NULL;
	}

	// Recursive Case
	if(pre[i] > min_val and pre[i] < max_val) {
		node*root = new node(pre[i]);
		i++;
		if(i < n) {
			root -> left = constructBstFromPre(pre, n, min_val, root -> data);
		}

		if(i < n) {
			root -> right = constructBstFromPre(pre, n, root -> data, max_val);
		}
		return root;
	}

	return NULL;
}


int main() {

	int pre[] = {5, 3, 1, 7, 6, 8};
	int n = sizeof(pre) / sizeof(int);

	node*root = constructBstFromPre(pre, n, INT_MIN, INT_MAX);

	bfsModified(root);
	cout << endl;
	printInOrder(root);
	cout << endl;

	return 0;
}