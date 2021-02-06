#include <bits/stdc++.h>
using namespace std;

string FindRepeatedSubString(string s) {

    int i = 0, j = 1, itr = 1, k1, k2;
    int n = s.length();
    for(int i = n / 2 - 1; i >= 0; i--) {
        if(n % (i + 1) == 0) {
            int num_of_repeates = n / (i + 1);
            string s1 = s.substr(0, i + 1);
            string s2 = "";
            for(int i = 0; i < num_of_repeates; i++) {
                s2.append(s1);
            }
            if(s2 == s) {
                return s1;
            }
        }
    }
    return s;
}


long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// Function to return LCM of two numbers 
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}



int main() {

    int t;
    cin >> t;

    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        string repeated1 = FindRepeatedSubString(s1);
        string repeated2 = FindRepeatedSubString(s2);

        if(repeated1 != repeated2) {
            cout << "-1" << endl;
        }
        else {
            int num1 = s1.length() / repeated1.length();
            int num2 = s2.length() / repeated2.length();

            int ans;
            if(num1 > num2) {
                ans = lcm(num1, num2);
            }
            else {
                ans = lcm(num2, num1);
            }
            for(int i = 0; i < ans; i++) {
                cout << repeated1;
            }
            cout << endl;
        }

    }

    return 0;
}
