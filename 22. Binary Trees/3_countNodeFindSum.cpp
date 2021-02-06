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

int countNumOfNodes(node*head) {
	// Base Case
	if(head == NULL) {
		return 0;
	}
	// Recursive case
	int c1 = countNumOfNodes(head -> left);
	int c2 = countNumOfNodes(head -> right);

	return 1 + c1 + c2;
}

int sumOfAllNodes(node*head) {
	// base case
	if(head == NULL) {
		return 0;
	}
	// Recursive Case
	int s1 = sumOfAllNodes(head -> left);
	int s2 = sumOfAllNodes(head -> right);

	return head->data + s1 + s2;
}


int hieghtBT(node*root) {

	if(root == NULL) {
		return 0;
	}

	int lh = hieghtBT(root -> left);
	int rh = hieghtBT(root -> right);

	return max(lh, rh) + 1;
}


int findDiameter(node*head) {
	if(head == NULL) {
		return 0;
	}

	int d1 = findDiameter(head -> left);
	int d2 = findDiameter(head -> right);
	// Finding the hieght of left and right subtree of head
	int h_left = hieghtBT(head -> left);
	int h_right = hieghtBT(head -> right);

	return max(max(d1, d2), h_right + h_left);
}


int main() {

	node *head = buildTree();
	bfsModified(head);

	cout << countNumOfNodes(head) << endl;
	cout << sumOfAllNodes(head) << endl;

	cout << findDiameter(head) << endl;


	return 0;
}