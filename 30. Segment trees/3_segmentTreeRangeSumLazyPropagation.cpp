#include <bits/stdc++.h>
using namespace std;

class Solution {
	vector <int> segment;
	vector <int> lazy;
	int n;

	void buildSegmentTree(int index, int s, int e, vector <int>&a) {
		if (s == e) {
			segment[index] = a[s];

			return;
		}

		int mid = (s + e) >> 1;
		buildSegmentTree(2 * index + 1, s, mid, a);
		buildSegmentTree(2 * index + 2, mid + 1, e, a);

		segment[index] = segment[2 * index + 1] + segment[2 * index + 2];

	}

	void incrementRangeUtil(int index, int left, int right, int l, int r, int value) {
		if (left > right) return;
		if (lazy[index] != 0) {
			segment[index] += lazy[index] * (right - left + 1);
			if (left != right) {
				lazy[2 * index + 1] += lazy[index];
				lazy[2 * index + 2] += lazy[index];
			}

			lazy[index] = 0;
		}

		if (right < l || left > r) return;

		if (left >= l && right <= r) {
			segment[index] += (right - left + 1) * value;
			if (left != right) {
				lazy[2 * index + 1] += value;
				lazy[2 * index + 2] += value;
			}

			return;
		}

		int mid = (left + right) / 2;

		incrementRangeUtil(2 * index + 1, left, mid, l, r, value);
		incrementRangeUtil(2 * index + 2, mid + 1, right, l, r, value);

		segment[index] += segment[2 * index + 1] + segment[2 * index + 2];
	}

	int querySumLazyUtil(int index, int left, int right, int s, int e) {
		if (left > right) return 0;
		if (lazy[index] != 0) {
			segment[index] += lazy[index] * (right - left + 1);
			if (left != right) {
				lazy[2 * index + 1] += lazy[index];
				lazy[2 * index + 2] += lazy[index];
			}

			lazy[index] = 0;
		}

		if (right < s || left > e) return 0;

		if (left >= s && right <= e) {
			return segment[index];
		}

		int mid = (left + right) >> 1;
		return querySumLazyUtil(2 * index + 1, left, mid, s, e) + querySumLazyUtil(2 * index + 2, mid + 1, right, s, e);
	}
public:
	Solution(vector <int>&a) {
		n = a.size();
		segment = vector <int>(4 * n + 1);
		lazy = vector <int>(4 * n + 1, 0);
		buildSegmentTree(0, 0, n - 1, a);
	}

	void incrementRange(int l, int r, int value) {
		if (value == 0) return;

		incrementRangeUtil(0, 0, n - 1, l, r, value);
	}

	int querySumLazy(int l, int r) {
		return querySumLazyUtil(0, 0, n - 1, l, r);
	}

};

int main() {


	int n; cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	Solution s(a);

	cout << s.querySumLazy(1, 3) << endl;
	cout << s.querySumLazy(6, 9) << endl;

	s.incrementRange(1, 3, 2);

	cout << s.querySumLazy(1, 3) << endl;
	cout << s.querySumLazy(3, 3) << endl;
	cout << s.querySumLazy(4, 4) << endl;

	return 0;
}