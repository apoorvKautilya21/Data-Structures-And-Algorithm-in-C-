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


int hieghtBT(node*root) {

	if(root == NULL) {
		return 0;
	}

	int lh = hieghtBT(root -> left);
	int rh = hieghtBT(root -> right);

	return max(lh, rh) + 1;
}


int sumOfChildNodes(node*head) {

	if(head == NULL) {
		return 0;
	}
	if(head -> left == NULL and head -> right == NULL) {
		return head -> data;
	}

	int leftSum = sumOfChildNodes(head -> left);
	int rightSum = sumOfChildNodes(head -> right);

	int ans = leftSum + rightSum + head -> data;
	head -> data = leftSum + rightSum;

	return ans;
}



int main() {

	node *head = buildTree();
	cout << endl;
	bfsModified(head);
	cout << endl;

	sumOfChildNodes(head);
	bfsModified(head);

	return 0;
}