#include<iostream>
#include<cstring>
using namespace std;

int main() {

	char curr[1000];
	char largest[1000];

	int largest_len = 0;
	int n;
	cin >> n;
	cin.get();		// to get the extra '\n' character from the buffer.

	for(int i = 0; i < n; i++) {

		cin.getline(curr, 1000);
		int len = strlen(curr);

		if(len > largest_len) {
			largest_len = len;
			strcpy(largest, curr);
		}
	}

	cout << largest << " and " << largest_len;

	return 0;
}


