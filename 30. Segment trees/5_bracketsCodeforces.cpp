// Sereja and Brackets (https://codeforces.com/problemset/problem/380/C)

#include <bits/stdc++.h>
using namespace std;

vector <int> zeros = {0, 0, 0};

class SegmentTree {
    int n;
    // 1st number will be total components
    // 2nd number will be unmatched (
    // 3rd number will be unmatched )
    vector <vector <int>> segment;

    vector <int> merge(vector <int>&vl, vector <int>&vr) {
        vector <int> ans(3);

        int matchedFromUnmatched = min(vl[1], vr[2]);
        ans[0] = vl[0] + vr[0] + 2 * matchedFromUnmatched;
        ans[1] = vl[1] + vr[1] - matchedFromUnmatched;
        ans[2] = vl[2] + vr[2] - matchedFromUnmatched;

        return ans;
    }

    void buildSegmentTree(int index, int l, int r, string&s) {
        if (l == r) {
            segment[index] = {0, s[l] == '(' ? 1 : 0, s[l] == ')' ? 1 : 0};
            return;
        }

        int mid = (l + r) >> 1;
        buildSegmentTree(2 * index + 1, l, mid, s);
        buildSegmentTree(2 * index + 2, mid + 1, r, s);

        segment[index] = merge(segment[2 * index + 1], segment[2 * index + 2]);
    }

    vector <int> queryRangeUtil(int index, int segL, int segR, int l, int r) {
        if (segL > segR || segL > r || segR < l) return zeros;

        if (segL >= l && segR <= r) return segment[index];

        int mid = (segL + segR) >> 1;

        auto vl = queryRangeUtil(2 * index + 1, segL, mid, l, r);
        auto vr = queryRangeUtil(2 * index + 2, mid + 1, segR, l, r);

        return merge(vl, vr);
    }
public:

    SegmentTree(string&s) {
        n = s.size();
        segment = vector <vector <int>>(4 * n + 1, vector <int>(3));

        buildSegmentTree(0, 0, n - 1, s);
    }

    int queryRange(int l, int r) {
        return queryRangeUtil(0, 0, n - 1, l, r)[0];
    }
};

int main() {
    string s; cin >> s;
    SegmentTree seg(s);

    int q; cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << seg.queryRange(l - 1, r - 1) << endl;
    }

    return 0;
}
