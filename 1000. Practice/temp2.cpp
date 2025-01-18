#include<iostream>
#include<queue>
#include<stack>
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

node* buildTree(string moreChild) {
	if(moreChild == "false") {
		return NULL;
	}

	int d;
	cin >> d;

	node*p = new node(d);

	cin >> moreChild;
	p -> left = buildTree(moreChild);

	cin >> moreChild;
	p -> right = buildTree(moreChild);

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

void printZigZag(node*root) {

	stack<int> s;
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	bool flag = false;
	while(!q.empty()) {

		node*p = q.front();
		q.pop();

		if(flag) s.push(p -> data);
		else cout << (p -> data) << " ";

		if(p -> left) q.push(p -> left);
		if(p -> right) q.push(p -> right);

		if(!q.front()) {
			q.pop();
			if(flag) {
				while(!s.empty()) {
					cout << s.top() << " ";
					s.pop();
				}
			}
			flag = !flag;
			if(!q.empty()) q.push(NULL);
		}
	}

}


int main() {

	string flag = "true";
	node*root = buildTree(flag);

	printZigZag(root);





	return 0;
}