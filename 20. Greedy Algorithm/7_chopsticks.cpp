// https://www.codechef.com/problems/TACHSTCK
#include<iostream>
#include<algorithm>
#define ll long long
# define N 100010 
using namespace std;
	
ll a[N];

int main() {

	int n;
	ll d;
	cin >> n >> d;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	int ans = 0;
	int i = 0;
	while(i < n - 1) {
		if(a[i + 1] - a[i] <= d) {
			ans++;
			i += 2;
		}
		else {
			i++;
		}
	}

	cout << ans;

	return 0;
}