// https://www.spoj.com/problems/DEFKIN/
#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int t;
	cin >> t;

	while(t--) {

		int n, m;
		cin >> n >> m;
		int k;
		cin >> k;
		int x[1000];
		int y[1000];

		for(int i = 0; i < k; i++) {
			int tempx, tempy;
			cin >> tempx >> tempy;
			x[i] = tempx - 1;
			y[i] = tempy - 1;
		}

		// area = delx * dely; => we need to maximize delx and dely
		// this is what we are doing here

		sort(x, x + k);
		sort(y, y + k);

		int m_l = x[0];
		int m_b = y[0];

		for(int i = 0; i < k - 1; i++) {
			m_l = max(m_l, x[i+1] - x[i] - 1);
			m_b = max(m_b, y[i+1] - y[i] - 1);
		}
		m_l = max(m_l, n - x[k-1] - 1);
		m_b = max(m_b, m - y[k-1] - 1);

		cout << m_l*m_b << endl;
	}

	return 0;
}