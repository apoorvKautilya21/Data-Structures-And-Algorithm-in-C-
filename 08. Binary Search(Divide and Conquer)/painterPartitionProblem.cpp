// https://hack.codingblocks.com/app/practice/1/1057/problem
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int getMax(int arr[], int n) 
{ 
    int max = INT_MIN; 
    for (int i = 0; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
    return max; 
} 

int getSum(int arr[], int n) 
{ 
    int total = 0; 
    for (int i = 0; i < n; i++) 
        total += arr[i]; 
    return total; 
} 

bool isPossibleMidPainters(int a[], int n, int k, int curr_min) {

	int req_painters = 1;
	int spent_time = 0;
	for(int i = 0; i < n; i++) {

		spent_time += a[i];
		if(spent_time > curr_min) {
			req_painters += 1;
			spent_time = a[i];

			if(req_painters > k) {
				return false;
			}
		}
	}

	return true;
}

int minTime(int a[], int n, int k) {

	int s = getMax(a,n);
	int e = getSum(a,n);
	int ans = INT_MAX;

	while(s <= e) {

		int mid = (s+e) / 2;

		if(isPossibleMidPainters(a, n, k, mid)) {
			e = mid - 1;
			ans = min(mid, ans);
		}

		else {
			s = mid + 1;
		}
	}
	return ans;
}

int main() {

	int k;
	int n;
	int a[20];

	cin >> k;
	cin >> n;

	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}

	cout << minTime(a, n, k);
	return 0;
}
  



