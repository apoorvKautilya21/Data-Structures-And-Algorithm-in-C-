#include<iostream>
#include<stack>
using namespace std;


int main() {

	int price[] = {100,80,90,70,60,75,85};
	int n = sizeof(price)/sizeof(int);
	int ind[n];
	stack<int> s;
	ind[0] = 1;
	s.push(0);

	for(int i = 1; i < n; i++) {
		
		while(!s.empty() and price[i] >= price[s.top()]) {
			s.pop();
		}
		if(s.empty()) {
			ind[i] = i + 1;
		}
		else {
			ind[i] = i - s.top();
		}
		s.push(i);		
	}

	for(int i = 0; i < n; i++) {
		cout << ind[i] << " ";
	}




	return 0;
}