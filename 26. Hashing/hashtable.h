#include<iostream>
#include<climits>
#include<cstring>
#define ll long long
using namespace std;

template<typename T>
class Node {
public:

	string key;
	T value;
	Node<T>* next;

	Node(string key, T val) {
		this -> key = key;
		this -> value = val;
	}

	~Node() {
		// Recursive Call
		if(next != NULL) {
			delete next;
		}
	}
};

template<typename T>
class HashTable {

	Node<T>** table;
	int table_size;
	int current_size;

	int hashFunc(string key) {

		int idx = 0;
		ll p = 1;

		for(int i = 0; i < key.length(); i++) {
			idx = idx + (key[i] * p) % table_size;
			idx = idx % table_size;
			p = (p * 27) % table_size;
		}	
		return idx;
	}

	void rehash() {

		Node<T>**oldTable = table;
		int oldTableSize = table_size;
		table_size = table_size * 2;
		table = new Node<T>*[table_size];

		for(int i = 0; i < table_size; i++) {
			table[i] = NULL;
		}
		current_size = 0;

		for(int i = 0; i < oldTableSize; i++) {
			Node<T>*temp = oldTable[i];
			while(temp!=NULL) {
				insert(temp -> key, temp -> value);
				temp = temp -> next;
			}
			if(oldTable[i]) {
				delete oldTable[i];
			}
		}

		delete [] oldTable;
	}

public:

	HashTable(int ts = 7) {

		table_size = ts;
		table = new Node<T>*[table_size];
		current_size = 0;

		for(int i = 0; i < table_size; i++) {
			table[i] = NULL;
		}
	}

	void insert(string key, T value) {

		int idx = hashFunc(key);
		Node<T>*n = new Node<T>(key, value);

		n -> next = table[idx];
		table[idx] = n;
		current_size++;

		// Rehash...
		float lf = current_size / (1.0 * table_size);

		if(lf > 0.7) {
			rehash();
		}

	}

	// Looking Inside
	void print() {

		for(int i = 0; i < table_size; i++) {
			Node<T>* temp = table[i];
			cout << "Bucket " << i << " -> \n";
			while(temp != NULL) {
				cout << "\t" << temp -> key << " : " << temp -> value << endl;
				temp = temp -> next;
			}
			cout << endl;
		} 

	}

	
	T* search(string key) {

		int idx = hashFunc(key);
		Node<T>*temp = table[idx];

		while(temp != NULL) {
			if(temp -> key == key) {
				return &(temp -> value);
			} 
			temp = temp -> next;
		}

		return NULL;
	}

	void erase(string key) {

		int idx = hashFunc(key);
		Node<T>*temp = table[idx];
		Node<T>*prev = temp;
		while(temp) {
			if(temp -> key == key) {
				if(temp == table[idx]) {
					table[idx] = temp -> next;
				}
				else {
					prev -> next = temp -> next;
				}
				temp -> next = NULL;
				delete temp;
				break;
			}
			prev = temp;
			temp = temp -> next;
		}
	}

	T& operator[](string key) {

		T*price = search(key);

		if(price == NULL) {
			T garbage;
			insert(key, garbage);
			price = search(key);
		}
	
		return *price;
	}

};


