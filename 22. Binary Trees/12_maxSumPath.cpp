// Input:- 10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1
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

class Pair{
public:
	int maxSum;
	int branchSum;

	Pair() {
		maxSum = 0;
		branchSum = 0;
	}
};


Pair maxPathSum(node*head) {
	Pair p;
	if(head == NULL) {
		return p;
	}

	// Recursive case
	Pair leftAns = maxPathSum(head -> left);
	Pair rightAns = maxPathSum(head -> right);

	// Various options for maximum sum including the root
	int op1 = head -> data;
	int op2 = head -> data + leftAns.branchSum;
	int op3 = head -> data + rightAns.branchSum;
	int op4 = head -> data + leftAns.branchSum + rightAns.branchSum;

	int maxSumIncludingRoot = max(op1, max(op2, max(op3, op4)));

	// for branch sum
	p.branchSum = max(leftAns.branchSum, max(rightAns.branchSum, 0)) + head -> data;
	p.maxSum = max(leftAns.maxSum, max(rightAns.maxSum, maxSumIncludingRoot));

	return p;
}


int main() {

	node *head = buildTree();
	bfsModified(head);
	cout << endl;

	cout << maxPathSum(head).maxSum << endl;

	return 0;
}