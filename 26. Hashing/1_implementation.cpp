#include<iostream>
#include<climits>
#include<cstring>
#include "hashtable.h"
#define ll long long
using namespace std;


int main() {

	HashTable<int> ht;

	ht.insert("Pizza", 180);
	ht.insert("Burger", 120);
	ht.insert("BurgerPizza", 150);
	ht.insert("Pepsi", 65);
	ht.insert("Noodles", 80);
	ht.insert("Coke", 55);
	ht.insert("Momos", 110);

	/*
	int*price = ht.search("Coke");
	if(price != NULL) 
		cout << "Price : " << *price;
	else 
		cout << "Not Found";

	cout << endl << endl;

	ht.erase("Coke");
	*/

	ht["Dosa"] = 60;
	ht["Dosa"] += 20;

	cout << ht["Dosa"] << endl; 

	ht.print();



	return 0;
}

