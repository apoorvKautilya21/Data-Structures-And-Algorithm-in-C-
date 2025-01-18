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

// 2 3 4
// 5 6 7
// 2 3 4
// 7 6 5
// 2 3 4 5 6 7
//  a b c d e 
// abcbcdcde
// a2b3c2de
// cbcdabcde