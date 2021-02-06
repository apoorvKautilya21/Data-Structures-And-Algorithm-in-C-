#include<iostream>
#include<cstring>
using namespace std;

// c[] = "1234"
int string2Int(char *c, int n) {

	if(n == 0) {
		return 0;
	}
	// Assumed that it will find 123
	int num = string2Int(c, n - 1);		
	// when i have 123 i will multiply it with 10 and (c[n - 1] - '0') that's last element
	num = num * 10 + (c[n - 1] - '0');	
	return num;
}


int main() {

	char c[] = "4121";
	int n = strlen(c);

	int ans = string2Int(c, n);
	cout << ans << endl << ans + 1;

	return 0;
}