#include<iostream>
using namespace std;

char words[][10] = {"Zero ","One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};

void int2string(int n) {
	switch(n) {
		case 0:
			cout << "Zero ";
			break;
		case 1:
			cout << "One ";
			break;
		case 2:
			cout << "Two ";
			break;
		case 3:
			cout << "Three ";
			break;
		case 4:
			cout << "Four ";
			break;
		case 5:
			cout << "Five ";
			break;
		case 6:
			cout << "Six ";
			break;
		case 7:
			cout << "Seven ";
			break;
		case 8:
			cout << "Eight ";
			break;
		case 9:
			cout << "Nine ";
			break;
	}
}

void spelling(int n) {

	if(n == 0) {
		return;
	}

	spelling(n / 10);
	// 2 methods
	// 1.
	// int2string(n%10);
	// 2. 
	cout << words[n % 10];
}

int main() {

	int n;
	cin >> n;
	spelling(n);

	return 0;
}