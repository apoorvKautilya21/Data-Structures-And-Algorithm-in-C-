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

void printKthLevel(node*root, int k) {

	if(k < 0){
		return;
	}
	if(root == NULL) {
		return;
	}

	if(k == 0) {
		cout << root->data << " ";
		return;
	}

	printKthLevel(root -> left, k - 1);
	printKthLevel(root -> right, k - 1);

	return;
}


int printKthDistanceNodes(node*head, node*target, int k) {

	// if target is not present in this part
	if(head == NULL) {
		return -1;
	}
	// printing the nodes in the lower side of the root node
	if(head == target) {
		printKthLevel(target, k);
		return 0;
	}

	// exploring the left part
	int ld = printKthDistanceNodes(head -> left, target, k);
	// now we will print the nodes at distance k from the on the right upward side
	// if root is present there
	if(ld != -1) { 
		// if ancestor is present at distance k from target or ld + 1 from target
		if(k == ld + 1) {
			cout << head->data << " ";
		}
		// printing the right subparts of the target
		else{
			printKthLevel(head -> right, k - 2 - ld);
		}	
		return ld + 1;
	}

	// if node is present in the left side then go and explore the right side	
	int rd = printKthDistanceNodes(head -> right, target, k);

	if(rd != -1) {
		// if ancestor is present at distance k from target or ld + 1 from target
		if(k == rd + 1) {
			cout << head->data << " ";
		}
		// printing the left subparts of the target
		else {
			printKthLevel(head -> left, k - 2 - rd);
		}
		return rd + 1;
	}
	// if target is not present in right and left subtrees return -1
	return -1;
}




int main() {

	node *head = buildTree();
	bfsModified(head);
	cout << endl;

	node*target = head -> left -> left;
	printKthDistanceNodes(head, target, 2);


	return 0;
}