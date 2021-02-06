#include <iostream>
#include <cstring>
using namespace std;


class Fun {
public:
	void operator()(string s) {
		cout << "Having fun with " << s;
	}
};

int main() {

	Fun f;
	f("C++");	// It's an object but behaving as a function call hence it's known as functor or functional Object
	

	return 0;
}