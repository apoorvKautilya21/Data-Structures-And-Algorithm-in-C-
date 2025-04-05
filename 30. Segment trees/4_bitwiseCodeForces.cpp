// Xenia and bitwise operation (https://codeforces.com/problemset/problem/339/D)
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    int n;
    vector <int> segment;
    bool isOdd;

    void buildSegmentTreee(int index, int s, int e, vector <int>&a, bool orOp) {
        if (s > e) return;

        if (s == e) {
            segment[index] = a[s];

            return;
        }

        int mid = (s + e) >> 1;

        buildSegmentTreee(2 * index + 1, s, mid, a, !orOp);
        buildSegmentTreee(2 * index + 2, mid + 1, e, a, !orOp);

        if (orOp) {
           segment[index] = segment[2 * index + 1] | segment[2 * index + 2];
        } else {
            segment[index] = segment[2 * index + 1] ^ segment[2 * index + 2];
        }
    }

    int queryResUtil(int index, int left, int right, int l, int r, bool orOp) {
        if (left > right || left > r || right < l) return 0;
        if (left >= l && right <= r) {
            return segment[index];
        }

        int mid = (left + right) >> 1;

        int leftRes = queryResUtil(2 * index + 1, left, mid, l, r, !orOp);
        int rightRes = queryResUtil(2 * index + 2, mid + 1, right, l, r, !orOp);

        if (orOp) return leftRes | rightRes;

        return leftRes ^ rightRes;
    }

    void pointUpdateUtil(int index, int l, int r, int targetIndex, int val, bool orOp) {
        if (l == r) {
            segment[index] = val;
            return;
        }

        int mid = (l + r) >> 1;
        if (mid >= targetIndex) pointUpdateUtil(2 * index + 1, l, mid, targetIndex, val, !orOp);
        else pointUpdateUtil(2 * index + 2, mid + 1, r, targetIndex, val, !orOp);

        if (orOp) {
           segment[index] = segment[2 * index + 1] | segment[2 * index + 2];
        } else {
            segment[index] = segment[2 * index + 1] ^ segment[2 * index + 2];
        }
    }
public:

    SegmentTree(vector <int>&a, bool isOdd) {
        n = a.size();
        segment.resize(4 * n + 1);
        this -> isOdd = isOdd;

        // if n is odd then we should do OR first
        // if n is even then we should do XOR first
        buildSegmentTreee(0, 0, n - 1, a, isOdd);
    }

    int queryRange(int l, int r) {
        return queryResUtil(0, 0, n - 1, l, r, isOdd);
    }

    int getTopVal() {
        return segment[0];
    }

    void pointUpdate(int index, int val) {
        return pointUpdateUtil(0, 0, n - 1, index, val, isOdd);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    int sz = 1 << n;
    vector <int> a(sz);

    for (int i = 0; i < sz; i++) {
        cin >> a[i];
    }

    SegmentTree seg(a, n % 2); 

    while (m--) {
        int idx, val;
        cin >> idx >> val;

        seg.pointUpdate(idx - 1, val);

        cout << seg.getTopVal() << endl;
    }

    return 0;
}