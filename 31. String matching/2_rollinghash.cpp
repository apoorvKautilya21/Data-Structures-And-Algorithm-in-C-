#include <bits/stdc++.h>
using namespace std;

long long int prime = 101, mod = 1e9 + 7;
int getHash(string&s) {
    long long int hash = 0;

    for (auto c : s) {
        hash = (hash * prime + c - 'a' + 1) % mod;
    }

    return hash;
}

bool hasSamePattern(string&text, string&pattern, int l, int r) {
    bool isSame = true;
    for (int i = l; i <= r; i++) {
        if (text[i] != pattern[i - l]) {
            isSame = false;
            break;
        }
    }

    return isSame;
}

int findFirstMatchingIndex(string&text, string&pattern, int len, int patternHash) {
    int l = 0, r = 0;
    long long int maxPower = 1, hash = 0;
    while (r < len) {
        hash = (hash * prime + text[r] - 'a' + 1) % mod;
        if (r) maxPower = (maxPower * prime) % mod;
        r++;
    }

    if (hash == patternHash && hasSamePattern(text, pattern, l, r - 1)) {
        return 0;
    }

    while (r < text.size()) {
        hash = (hash - maxPower * (text[l] - 'a' + 1) + mod) % mod;
        hash = (hash * prime + text[r] - 'a' + 1) % mod;
        l++;
        if (hash == patternHash && hasSamePattern(text, pattern, l, r)) return l;
        r++;
    }

    return -1;
}


int main() {
    string text = "abaaabaababababaaaabaaababaaababababa";
    string pattern = "aaabaa";

    int patternHash = getHash(pattern);

    cout << findFirstMatchingIndex(text, pattern, pattern.size(), patternHash);

    return 0;
}