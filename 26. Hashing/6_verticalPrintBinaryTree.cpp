#include<iostream>
#include<queue>
#include<map>
using namespace std;

int arr[20000004];

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


void verticalOrderPrint(node*root, int x, map<int, vector<int> > &m) {
	if(root == NULL) {
		return;
	}

	m[x].push_back(root -> data);
	verticalOrderPrint(root -> left, x - 1, m);
	verticalOrderPrint(root -> right, x + 1, m);
	return;
}



int main() {

	node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    map<int, vector<int> > m;
    int x = 0;
    verticalOrderPrint(root, x, m);

    for(auto x:m) {
    	cout << x.first << " -> ";
    	for(int y:x.second) {
    		cout << y << ",";
    	}
    	cout << endl;
    }

	return 0;
}