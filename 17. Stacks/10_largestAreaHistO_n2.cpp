#include<iostream>
using namespace std;

int Min(int a[], int s, int e) {
	int ans = s;
	for(int i = s + 1; i <= e; i++) {
		if(a[ans] >= a[i]) {
			ans = i;
		}
	}
	return ans;
}
int max(int a, int b, int c) {
	return (b>c)? (b>a? b:a): (c>a?c:a);
} 

int findMax(int bar[], int s, int e) {
	if(s == e) {
		return bar[s];
	}

	// Recursive case
	int mini = Min(bar, s, e);
	int left = findMax(bar, s, mini - 1);
	int right = findMax(bar, mini + 1, e);
	int curr = bar[mini] * (e-s+1);

	return max(curr,left,right);

}

int main() {

	int bar[] = {6,2,5,4,5,1,6};
	int n = sizeof(bar) / sizeof(int);

	cout << findMax(bar, 0, n - 1);





	return 0;
}