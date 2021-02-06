#include<iostream>
#include<list>
using namespace std;

class Book {
public:
	string name;
	int price;

	Book() {
	}

	Book(string name, int price) {
		this->name = name;
		this->price = price;
	}

};

class BookCompare{
public:

	bool operator()(Book A, Book B) {
		if(A.name == B.name) {
			return true;
		}
		return false;
	}
};

// template class + iterators + comparators
template<class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp) {

	while(start != end) {

		if(cmp(*start, key)) {
			return start;
		}
		start++;
	}
	return end;
}



int main() {

	Book b1("C++", 100);
	Book b2("Python", 150);
	Book b3("Java", 120);

	list <Book> l;
	l.push_back(b1);
	l.push_back(b2);
	l.push_back(b3);

	Book booktofind("C++", 110);
	BookCompare cmp;

	auto it = search(l.begin(), l.end(), booktofind, cmp);

	if(it != l.end()) {
		cout << it->name << " " << it->price << " Book Found in the library" ;
	}
	else {
		cout << "Not Found";
	}
	return 0;
}