#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main() {
	int black[] = {3, 4, 1};
	int white[] = {2, 5, 6};
	int n = 3;

	sort(black, black + n);
	sort(white, white + n);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += abs(black[i] - white[i]);
	}
	cout << ans << endl;

}