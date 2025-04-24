/**

You are given a list of N elements. Each element is a tuple (value, can_decrement) where:

value is an integer (positive or negative),
can_decrement is a boolean indicating how the value can be adjusted:
If True, you are only allowed to decrement the value.
If False, you are only allowed to increment the value.
You are allowed to increment/decrement each number as much as you want, but only in the allowed direction. Your task is to determine whether it's possible to transform all values into a valid permutation of [1, 2, ..., N].

If it's possible, return the mapping in the form {original: transformed}
If it's not possible, return an empty dictionary.

**/

#include <bits/stdc++.h>
using namespace std;

bool compare(vector <int>&a, vector <int>&b) {
    if (a[1] == b[1]) return a[0] < b[0];

    return a[1] < b[1];
}

unordered_map <int, int> solve(vector <vector <int>>&v) {
    vector <vector <int>> ranges;
    unordered_map <int, int> res, emptyList;
    int n = v.size();

    for (int i = 0; i < n; i++) {
        auto interval = v[i];
        if (interval[1] == true) {
            if (interval[0] <= 0) return emptyList;

            ranges.push_back({1, interval[0], i});
        } else if (interval[1] == false) {
            if (interval[0] > n) return emptyList;

            ranges.push_back({interval[0], n, i});
        }
    }

    sort(ranges.begin(), ranges.end(), compare);

    int target = 1;
    for (auto interval : ranges) {
        if (target > interval[1] && target < interval[0]) return emptyList;

        res[target] = interval[2];
        target++;
    }

    if (target <= n) return emptyList;

    return res;
}

int main() {
    int n; cin >> n;
    vector <vector <int>> v(n, 2);

    for (int i = 0; i < n; i++)
        cin >> v[i][0] >> v[i][1];





    return 0;
}