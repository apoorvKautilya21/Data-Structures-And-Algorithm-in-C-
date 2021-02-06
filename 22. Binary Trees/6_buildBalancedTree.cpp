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

// First element of pair contains the height of the tree
pair<int, bool> isBalanced(node*head) {
	if(head == NULL) {
		return make_pair(0, true);
	}

	pair<int, bool> p1 = isBalanced(head -> left);
	pair<int, bool> p2 = isBalanced(head -> right);
	
	pair<int,bool> p;
	p.first = max(p1.first, p2.first) + 1;

	if(abs(p1.first - p2.first) <= 1 and p1.second and p2.second) {
		p.second = true;
	}	
	else {
		p.second = false;
	}

	return p;
}

int main() {

	node *head = buildTree();
	cout << endl;
	bfsModified(head);
	cout << endl;

	if(isBalanced(head).second) {
		cout << "Balanced";
	}
	else {
		cout << "Not Balanced";
	}

	return 0;
}