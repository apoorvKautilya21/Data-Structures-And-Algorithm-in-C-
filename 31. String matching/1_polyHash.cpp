#include <bits/stdc++.h>
using namespace std;

// If string is abcd then hash is a + b * 10 + c * 10^2 + d * 10^3;
long long int getPolyHashVal(string&s) {
  long long int hash = 0, prime = 101;
  long long int primePower = 1, mod = 1e9 + 7;

  for (auto c : s) {
    hash = (hash + primePower * (c - 'a' + 1)) % mod;
    primePower = (primePower * prime) % mod;
  }

  return hash;
}

// If string is abcd then hash is a * 10^3 + b * 10^2 + c * 10 + d;
long long int getPolyHashVal2(string&s) {
  long long int hash = 0, prime = 101, mod = 1e9 + 7;
  
  // it's like converting "1231412412" to an integer
  for (auto c : s) {
    hash = (hash * prime + c - 'a' + 1) % mod;
  }

  return hash;
}


int main() {
  string s; cin >> s;

  cout << getPolyHashVal(s) << endl;
  cout << getPolyHashVal2(s) << endl;

  return 0;
}