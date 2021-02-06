// https://www.spoj.com/problems/AGGRCOW/
#include<iostream>
using namespace std;


bool canCowsPlaced(int a[], int n, int c, int min_sep) {

	int last_cow_pos = 0;
	int count = 1;

	for(int i = 1; i < n; i++) {
		// cout << a[i] << " " << a[last_cow_pos] << endl;
		if(a[i] - a[last_cow_pos] >= min_sep) { 
			last_cow_pos = i;
			count ++;
			if(count == c) {
				return true;
			}
		}
	}
	return false;
}



int main() {
	// We will be given first the position of stalls then we will sort it to get
	int pos[] = {1,2,4,8,9};
	int n = 5;
	int c = 3;

	int s = 0;
	int e = pos[n-1] - pos[0];
	int ans = 0 ;

	while(s <= e) {

		int mid = (s + e) / 2;

		bool isPossible = canCowsPlaced(pos, n, c, mid);

		if(isPossible) {
			ans = mid;
			s = mid + 1;
		}

		else {
			e = mid - 1;
		}

	}
		
	cout << ans << endl;
	return 0;
}