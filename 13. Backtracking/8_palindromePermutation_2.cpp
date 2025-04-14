#include <bits/stdc++.h>
using namespace std;

void backtrack(int index, int n, string& curr, vector <int>&count, string&oddString, vector <string>&ans) {
    if (index == n) {
        string rev = curr;
        reverse(rev.begin(), rev.end());
        ans.push_back(curr + oddString + rev);
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i]) {
            count[i]--;
            curr.push_back('a' + i);

            backtrack(index + 1, n, curr, count, oddString, ans);

            count[i]++;
            curr.pop_back();
        }
    }
}

vector <string> solve(string s) {
    vector <int> count(26, 0);
    for (auto c : s) count[c - 'a']++;

    string oddString = "";
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2) oddString.push_back('a' + i);
        count[i] /= 2;
    }

    vector <string> ans;

    if (oddString.size() > 2) return ans;

    string curr = "";
    backtrack(0, s.size() / 2, curr, count, oddString, ans);

    return ans;
}

int main() {
    string s;
    cin >> s;

    vector <string> ans = solve(s);

    for (auto&str : ans)
        cout << str << endl;

    return 0;
}
