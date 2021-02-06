#include<iostream>
using namespace std;

// n = 5 (let's say)
// 5 numbers are  ----  1 2 3 1 2
// here 1 and occurs 2 times and 3 occurs one time only
// we get answer here 3
//
// 
// in this situation we have given with n numbers in which all number appears 2 times
// except one... we have find that one....... 
// IN THIS CASE IT IS 
// ***   3    ***
// NOTE ------- HERE "N" IS ODD (in the form of (2n+1))

int main() {

	int n;
	cin >> n;

	int no;
	int ans = 0;
	while(n--) {
		cin >> no;
		ans = ans ^ no;
	}
	cout << ans;

	return  0;
}