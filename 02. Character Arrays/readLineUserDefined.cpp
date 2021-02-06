#include<iostream>
using namespace std;


// cin.get reads single character at a single moment in a flow of input of of words from the user.
void readPara(char A[], int max_len, char delim='\n') {

	int i = 0;
	char ch = cin.get();
	while(ch != delim) {
		A[i] = ch;
		i++;

		if(i == max_len - 1) {
			return;
		}
		ch = cin.get();
	}

	A[i] = '\0';

}

int main() {

	char A[1000];
	readPara(A, 1000, '$');

	cout << A;

	return 0;
}