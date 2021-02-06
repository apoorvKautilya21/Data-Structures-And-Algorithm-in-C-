#include<iostream>
#include<algorithm>
using namespace std;

void display(int a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
}

bool next_perm(int a[], int n) {
	
	// 1043  -x> 1034
	// 1034  -> 1043
	// since 3 < 4 so next permutation after a[2] possible

	// 103542 will permutate after 2 i.e., a[2]

	int inverse_pt = n - 2;
	while(inverse_pt >= 0 and a[inverse_pt] >= a[inverse_pt + 1]) 
		inverse_pt --;

	if(inverse_pt < 0) {
		return false;
	}

	reverse(a + inverse_pt + 1, a + n);
	int ub = upper_bound(a+inverse_pt+1, a+n, a[inverse_pt]) - a;
	swap(a[inverse_pt], a[ub]);
	display(a,n);
	return true;
}

int main() {

	int arr[] = {1,2,3,4};
	int n = sizeof(arr) / sizeof(int);

	bool check=true;
	int count = 0;
	while(check){
		check = next_perm(arr, n);
		count++;
	}
	cout << count - 1 << " ";

	return 0;
}