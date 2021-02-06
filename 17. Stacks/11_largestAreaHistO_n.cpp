#include<iostream>
#include<stack>
using namespace std;

int findMax(int bar[], int n) {

	int max_area = 0;
	int area = 0;
	stack<int> s;

	for(int i = 0; i <= n; i++) {
		
		while(!s.empty() and bar[s.top()] > bar[i]) {
			int tp = s.top();
			s.pop();
			if(s.empty()) {
				area = bar[tp] * i; 
				max_area = max(max_area, area);
				break;
			}
			else {
				area = bar[tp] * (i - s.top() - 1);				
				max_area = max(max_area, area);
			}
		}
		s.push(i);
	}
	return max_area;
}

int main() {

	int bar[100] = {2,2,1,3,4,1,2};
	int n = 7;
	bar[n] = 0;
	cout << findMax(bar, n);


	return 0;
}