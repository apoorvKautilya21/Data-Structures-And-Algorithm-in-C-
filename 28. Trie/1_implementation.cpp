#include<iostream>
#include<unordered_map>
using namespace std;


class Node {
public:
	char data;
	unordered_map<char, Node*> children;
	bool terminal;	// stores if this node is the terminal or not

	Node() {

	}

	Node(char c) {
		data = c;
		terminal = false;
	} 
};


class Trie {

	Node* root;
	int cnt;

public:

	Trie() {
		root = new Node('\0');
	}

	void insert(char *c) {

		Node*temp = root;

		for(int i = 0; c[i] != '\0'; i++) {
			char ch = c[i];

			if(temp -> children.count(ch) == 0) {
				temp -> children[ch] = new Node(ch);
			}
			
			temp = temp -> children[ch];
		}
		temp -> terminal = true;
	}

	bool find(char *w) {

		Node*temp = root;
		for(int i = 0; w[i] != '\0'; i++) {

			char ch = w[i];
			if(temp -> children.count(ch) == 0) {
				return false;
			}
			
			temp = temp -> children[ch];
		}

		return temp -> terminal;
	}
};


int main() {

	Trie t;
	char words[][10] = {"a", "hello", "not", "news", "apple"};
	char w[10];
	cin >> w;

	for(int i = 0; i < 5; i++) {
		t.insert(words[i]);
	}

	if(t.find(w)) {
		cout << "Present" << endl;
	}
	else {
		cout << "Not Present" << endl;
	}


	return 0;
}