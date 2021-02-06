#include<iostream>
#include<list>
using namespace std;

// Template class + iterators (User Defined)  OR i can say that's how the people write code
// for iterators
template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator last, T key) {

	while(start != last) {

		if(*start == key){
			return start;
		}
		start++;
	}
	return last;
}


int main() {

	list<float> l;
	l.push_back(1.1);
	l.push_back(2.1);
	l.push_back(3.1);
	l.push_back(4.1);
	l.push_back(5.1);

	auto it = search(l.begin(), l.end(), float(3.1));

	if(it == l.end()) {
		cout << "Not present";
	}
	else {
		cout << *it;
	}
	return 0;
}