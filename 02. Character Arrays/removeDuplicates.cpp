#include<iostream>
#include<cstring>
using namespace std;

void removeDuplicate(char A[]) {

	int i = 1;
	int j = 0;

	if(strlen(A) <= 1)
		return;

	for(; A[i] != '\0'; i++) {

		if(A[j] != A[i]) {
			j++;
			A[j] = A[i];
		}
	}

	A[++j] = A[i];
	return;
}

int main() {

	char A[1000];
	cin >> A;
	cout << endl << A;

	removeDuplicate(A);
	cout << endl << A;

	return 0;
}

