#include<iostream>
#include<cstring>
using namespace std;

bool isPalindrome(char A[]) {

	int i = 0;
	int j = strlen(A) - 1;
	while(i < j) {
		if(A[i] == A[j]) {
			i++;
			j--;
		}

		else {
			return false;
		}
	}

	return true;
}

int main() {

	char a[1000];
	cin >> a;

	if(isPalindrome(a))
		cout << "\nPalindrome";
	else
		cout << "\nNot a Palindrome";

	return 0;
}