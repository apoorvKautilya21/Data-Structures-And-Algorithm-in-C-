// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
long long int sumArr(long long int a[], int n) {
    long long int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += a[i];
    }
    return ans;
}
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k) {
        
        long long int total_sum = 0;
        sort(a, a + n);
        int i;
        for(i = 0; i < n; i++) {
            if(k > 0 and a[i] < 0) {
                a[i] *= -1;
                k--;
            }
            else{
                break;
            }
        }

        if(i == n) i--;

        if(k == 0 or k % 2 == 0) {
            return sumArr(a, n);
        }

        if(k % 2 and a[i] > a[i - 1]) i--;
        a[i] *= -1;
        
        return sumArr(a, n);
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends