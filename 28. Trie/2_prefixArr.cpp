#include<iostream>
#include<unordered_map>
#include<string>
#include<cstring>
using namespace std;


class Node {
public:
	char data;
	unordered_map<char, Node*> children;
	bool terminal;	// stores if this node is the terminal or not
	int cnt;	// shows number of words branching from there

	Node() {

	}

	Node(char c) {
		data = c;
		terminal = false;
		cnt = 1;
	} 
};


class Trie {

	Node* root;

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
			else {
				temp -> children[ch] -> cnt += 1;
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

	void prefixWord(char*w) {

		int j = 0;
		char pre[200];
		Node*temp = root;

		for(int i = 0; w[i] != '\0'; i++) {

			char ch = w[i];

			if(temp -> children.count(ch) == 0) {
				cout << "-1" << endl;
				return;
			}

			temp = temp -> children[ch];
			pre[j++] = ch;
			if(temp -> cnt == 1) {

				pre[j] = '\0';
				cout << pre << endl;
				return;
			}
		}
		cout << "-1" << endl;
	}

};




int main() {

	Trie t;
	char words[][10] = {"cobra", "cobras", "dog", "dove", "duck", "zebra"};

	int n = 6;
	
	for(int i = 0; i < n; i++) {
		t.insert(words[i]);
	}

	for(int i = 0; i < n; i++) {
		t.prefixWord(words[i]);
	}

	return 0;
}