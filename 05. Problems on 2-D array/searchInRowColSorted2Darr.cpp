#include<iostream>
using namespace std;

# define n 3
# define m 4

int main() {

	int a[][m] = {
		{10, 20, 30, 40},
		{15, 25, 35, 45},
		{27, 29, 37, 48}
	};

	int num;
	cin >> num;

	// O(n + m)
	int i = 0, j = m - 1;
	while(i < n && j >= 0) {
		if(a[i][j] == num){
			cout << "Found at arr[" << i <<"][" << j << "]." << endl;
			break;
		}
		else if(a[i][j] > num) {
			j--;
		}
		else{
			i++;
		}
	}

	if(i == n || j < 0) {
		cout << "Not Found" << endl;
	}

	return 0;
}