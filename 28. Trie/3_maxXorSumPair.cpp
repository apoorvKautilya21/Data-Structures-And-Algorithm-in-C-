#include<iostream>
using namespace std;


class Node{
public:

	Node*left;
	Node*right;

	Node() {
		left = NULL;
		right = NULL;
	}
};

class Trie {
public:
	Node*root;

	Trie() {
		root = new Node;
	}

	void insert(int n) {

		Node*temp = root;
		for(int i = 31; i >= 0; i--) {

			int bit = (n >> i) & 1;	// to find the msb and then bits after that

			if(bit == 0) {
				if(temp -> left == NULL) {
					temp -> left = new Node;
				}
				temp = temp -> left;
			}
			else {
				if(temp -> right == NULL) {
					temp -> right = new Node;
				}
				temp = temp -> right;
			}
		}
	}

	int max_xor_helper(int n) {

		Node*temp = root;
		int max_xor = 0;
		for(int i = 31; i >= 0; i--) {

			int bit = (n >> i) & 1;

			if(bit == 0) {
				if(temp -> right) {
					max_xor += 1 << i;
					temp = temp -> right;
				}
				else {
					temp = temp -> left;
				}
			} 

			else {
				if(temp -> left) {
					max_xor += (1 << i);
					temp = temp -> left; 
				}
				else {
					temp = temp -> right;
				}
			}
		}

		return max_xor;
	}

	int maxXorSumPair(int *input, int n) {

		int max_xor = 0;

		for(int i = 0; i < n; i++) {
			int val = input[i];
			insert(val);
			int curr_max = max_xor_helper(val);
			cout << curr_max << " ";
			max_xor = max(max_xor, curr_max);
		}

		return max_xor; 
	}
};

int main() {

	int input[] = {3, 10, 5, 25, 2, 8};
	int n = sizeof(input) / sizeof(int);
	Trie t;

	int max_xor = t.maxXorSumPair(input, n);
	cout << endl << max_xor;

	return 0;
}