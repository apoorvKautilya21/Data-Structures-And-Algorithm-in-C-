// Range Sum Query - Mutable (https://leetcode.com/problems/range-sum-query-mutable/?envType=problem-list-v2&envId=segment-tree)
#include <bits/stdc++.h>
using namespace std;

class Solution {
	vector <int> segment;
	int n;

	void buildSegment(int index, int s, int e, vector <int>&a) {
		if (s > e) return;
		if (s == e) {
			segment[index] = a[s];

			return;
		}

		int mid = (s + e) / 2;

		buildSegment(2 * index + 1, s, mid, a);
		buildSegment(2 * index + 2, mid + 1, e, a);

		segment[index] = segment[2 * index + 1] + segment[2 * index + 2];
	}

	int queryRangeSumUtil(int index, int low, int high, int l, int r) {
		if (low >= l && high <= r) return segment[index];

		if (high < l || low > r) return 0;

		int mid = (low + high) / 2;

		return queryRangeSumUtil(2 * index + 1, low, mid, l, r) + queryRangeSumUtil(2 * index + 2, mid + 1, high, l, r);
	}

	void pointUpdateUtil(int index, int s, int e, int target, int value) {
		if (s == e) {
			segment[index] += value;

			return;
		}

		int mid = (s + e) / 2;

		if (target <= mid) pointUpdateUtil(2 * index + 1, s, mid, target, value);
		else pointUpdateUtil(2 * index + 2, mid + 1, e, target, value);

		segment[index] = segment[2 * index + 1] + segment[2 * index + 2];
	}
public:
	Solution(vector <int>&a) {
		this -> n = a.size();
		segment = vector <int>(4 * n + 1);

		buildSegment(0, 0, n - 1, a);
	}

	int queryRangeSum(int l, int r) {
		return queryRangeSumUtil(0, 0, n - 1, l, r);
	}

	void pointUpdate(int index, int value) {
		pointUpdateUtil(0, 0, n - 1, index, value);
	}
};

int main() {


	int n; cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	Solution s(a);

	cout << s.queryRangeSum(0, 5) << endl;
	cout << s.queryRangeSum(3, 5) << endl;

	s.pointUpdate(3, 10); // do a[3]+=5
	s.pointUpdate(1, 12); // do a[1]+=12

	cout << s.queryRangeSum(0, 5) << endl;
	cout << s.queryRangeSum(3, 5) << endl;



	return 0;
}