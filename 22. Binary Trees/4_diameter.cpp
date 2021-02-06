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

// class Pair {
// public:
// 	int ht;
// 	int dmt;

// 	Pair(int h, int d) {
// 		ht = h;
// 		dmt = d;
// 	}
// };


// Pair findDiameterOptimized(node*head) {
// 	if(head == NULL) {
// 		Pair p(0, 0);
// 		return p;
// 	}

// 	Pair p1 = findDiameterOptimized(head -> left);
// 	Pair p2 = findDiameterOptimized(head -> right);
// 	// Finding the hieght of left and right subtree of head
// 	int h = max(p1.ht, p2.ht) + 1;
// 	int d = max(max(p1.dmt, p2.dmt), p1.ht + p2.ht);
// 	Pair ans(h, d); 

// 	return ans;
// }

pair<int, int> findDiameterOptimized2(node*head) {
	// here first element denotes hieght and second denotes diameter
	if(head == NULL) {
		return make_pair(0, 0);
	}

	pair<int, int> p1 = findDiameterOptimized2(head -> left);
	pair<int, int> p2 = findDiameterOptimized2(head -> right);

	int h = max(p1.first, p2.first) + 1;
	int d = max(max(p1.second, p2.second), p1.first + p2.first);

	return make_pair(h, d);
}


int main() {

	node *head = buildTree();
	cout << endl;
	bfsModified(head);
	cout << endl;

	cout << findDiameter(head) << endl;

	// Pair ht_dt = findDiameterOptimized(head);
	// cout << ht_dt.dmt << " " << ht_dt.ht << endl;

	pair<int,int> ans = findDiameterOptimized2(head);
	cout << ans.second << " " << ans.first << endl;


	return 0;
}