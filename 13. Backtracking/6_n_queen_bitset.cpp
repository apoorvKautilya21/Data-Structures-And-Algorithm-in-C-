#include<iostream>
#include<bitset>
using namespace std;

bitset<40> col, dleft, dright;

void solve(int n, int i, int &ans) {
	// Base case
	if(i == n) {ans++;	return;}
	// Recursive Case
	for(int c = 0; c < n; c++) {
		if(!col[c] && !dleft[i - c + n - 1] && !dright[i + c]) {
			col[c] = dleft[i - c + n - 1] = dright[i + c] = 1;
			solve(n, i + 1, ans);
			col[c] = dleft[i - c + n - 1] = dright[i + c] = 0;
		}
	}
}

int main() {

	int n;
	cin >> n;

	int ans = 0;	
	solve(n, 0, ans);
	cout << ans;

	return 0;
}