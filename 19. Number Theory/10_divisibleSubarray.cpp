// https://hack.codingblocks.com/app/practice/3/1065/problem
#include<iostream>
#include<cstring>
using namespace std;

int pre[100005] = {0};

int main() {

	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;
		memset(pre, 0, sizeof(pre));
		pre[0] = 1;

		int sum = 0;
		for(int i = 0; i < n; i++) {
			int num;
			cin >> num;
			sum += num;
			sum %= n;
			sum = (sum + n) % n;
			pre[sum]++;
		}
		long long ans = 0;
		for(int i = 0; i < n; i++) {
			long long m = pre[i];
			ans += (m) * (m - 1) / 2;
		}
		cout << ans << endl;
	}	

	return 0;
}