#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(char c[]) {
	stack<char> s;	

	int i = 0;
	while(c[i] != '\0') {

		if(c[i] == '(') {
			s.push(c[i]);
		}
		else if(c[i] == ')') {
			if(s.empty()) {
				return false;
			}
			s.pop();
		}
		i++;		
	}
	return s.empty();
}


int main() {

	char c[] = "((a+b)-(s-h))";
	
	cout << isBalanced(c);

	return 0;
}