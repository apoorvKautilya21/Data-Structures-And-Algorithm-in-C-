#include<iostream>
#include<unordered_set>
using namespace std;
	

int findLargestSeq(int a[], int n) {

	unordered_set<int> s;

	for(int i = 0; i < n; i++) {
		s.insert(a[i]);
	}

	int max_streak = 1;

	for(int i = 0; i < n; i++) {

		if(s.find(a[i] - 1) == s.end()) {
			// It means that a[i] is the starting point of the streak
			int next_no = a[i] + 1;
			int streak_len = 1;
			while(s.find(next_no) != s.end()) {
				next_no++;
				streak_len++;
			}
			max_streak = max(max_streak, streak_len);
		}	
	}

	return max_streak;
}

int main() {

	int arr[] = {14,5,1,2,6,3,7,8,9,13,15,11,12,13,17,10};
	int n = sizeof(arr) / sizeof(int);

	cout << findLargestSeq(arr, n);

	return 0;
}