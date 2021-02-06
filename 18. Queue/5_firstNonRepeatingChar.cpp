#include<iostream>
#include<queue>
using namespace std;


int main() {

	queue<char> q;
	int freq[26] = {0};
	char a;
	cin >> a;

	while(a != '.') {

		int ind = a - 'a';
		freq[ind]++;
		q.push(a);
		while(!q.empty() and freq[q.front() - 'a'] > 1) {
			q.pop();
		}

		if(q.empty()) {
			cout << "-1\n";
		}
		else {
			cout << q.front() << "\n";
		}
		cin >> a;
	}

	return 0;
}

