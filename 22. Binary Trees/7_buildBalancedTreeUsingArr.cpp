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

node* buildBalancedTree(int a[], int s, int e) {

	if(s > e) {
		return NULL;
	}

	int mid = (s + e) / 2;
	node*root = new node(a[mid]);
	root -> left = buildBalancedTree(a, s, mid - 1);
	root -> right = buildBalancedTree(a, mid + 1, e);

	return root;
}

int main() {

	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(a) / sizeof(int);

	node*head = buildBalancedTree(a, 0, n - 1);
	bfsModified(head);	

	return 0;
}