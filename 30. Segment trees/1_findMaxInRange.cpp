#include<bits/stdc++.h>
using namespace std;

// similarly you can add sums, mins, max etc.

vector <int> a;
vector <int> seg;


// O(N)
// keep building the tree until s == e
// precompute the results the range which can be recursively calculated
void build(int index, int s, int e) {
    if (s == e) {
        seg[index] = a[s];

        // cout << index << " : " << s << " " << e << " " << seg[index] << endl;

        return;
    }

    int mid = (s + e) / 2;

    build(2 * index + 1, s, mid);
    build(2 * index + 2, mid + 1, e);

    seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);

    // cout << index << " : " << s << " " << e << " " << seg[index] << endl;
}

// O(logN)
// low and high - range of original array a
// l and r - query range for which we need to find the result
int query(int index, int low, int high, int l, int r) {
    // completly lies 
    // in this case return the already computed value
    if (low >= l && high <= r) {
        return seg[index];
    }

    // out of range
    // ignore this case hence returning INT_MIN
    if (high < l || low > r) return INT_MIN;

    // partially covered
    // explore left and right side of tree recursively and return the max of both answers
    int mid = (low + high) / 2;

    return max(query(2 * index + 1, low, mid, l, r), query(2 * index + 2, mid + 1, high, l, r));
}


int main() {
    int n;
    cin >> n;

    a = vector <int>(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    seg = vector <int>(4 * n + 1);

    build(0, 0, n - 1);

    cout << query(0, 0, n - 1, 3, 8) << endl;
    cout << query(0, 0, n - 1, 1, 4) << endl;
    cout << query(0, 0, n - 1, 2, 4) << endl;

    return 0;
}