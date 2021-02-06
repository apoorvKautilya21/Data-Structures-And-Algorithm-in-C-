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

node* buildTreePreIn(int pre[], int in[], int s, int e) {
	static int i = 0;
	if(s > e) {
		return NULL;
	}

	node*root = new node(pre[i]);

	int index = s;
	for(; index <= e; index++) {
		if(in[index] == pre[i]) {
			break;
		}
	}

	i++;
	// for 1st element of pre root will be filled
	// then from second element of 'pre[]' if index > s then pre[1] will exist in..
	// in[] from [s --- index)
	root -> left = buildTreePreIn(pre, in, s, index - 1);
	root -> right = buildTreePreIn(pre, in, index + 1, e);

	return root;
}



int main() {

	int in[] = {3,2,8,4,1,6,7,5};
	int pre[] = {1,2,3,4,8,5,6,7};
	int n = sizeof(in) / sizeof(int);
	node*head = buildTreePreIn(pre, in, 0, n - 1);

	cout << endl;
	bfsModified(head);
	cout << endl;


	return 0;
}