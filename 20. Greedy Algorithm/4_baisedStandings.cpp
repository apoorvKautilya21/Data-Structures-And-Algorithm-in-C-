// https://www.spoj.com/problems/BAISED/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main() {	

	int t;
	cin >> t;
	int arr[1000] = {0};

	while(t--) {
		int n;
		memset(arr, 0, sizeof(arr));
		cin >> n;
		string name;
		int rank;
		// counting sort
		for(int i = 0; i < n; i++) {
			cin >> name >> rank;
			arr[rank]++;
		}

		// Greedy approach - assign the team nearest rank available
		int actual_rank = 1;
		int sum = 0;
		for(int i = 1; i <= n; i++) {
			while(arr[i]) {
				sum += abs(actual_rank - i);
				actual_rank++;
				arr[i]--;
			}
		}
		cout << sum << endl;
	}



	return 0;
}