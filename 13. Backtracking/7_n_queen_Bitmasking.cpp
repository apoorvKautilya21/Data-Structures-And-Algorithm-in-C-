#include<iostream>
using namespace std;

int n = 0;
int ans = 0, DONE;

void solve(int row_mask, int ld, int rd) {
	if(row_mask == DONE) {ans++;	return;}

	int safe = DONE & (~(row_mask | ld | rd));
	while(safe) {
		int p = safe & (-safe);
		safe = safe - p;
		solve(row_mask | p, (ld | p) << 1, (rd | p) >> 1);
	} 
}

int main() {

	cin >> n;
	DONE = (1<<n) - 1;
	solve(0, 0, 0);
	cout << ans << endl;

	return 0;
}