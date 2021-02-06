#include<iostream>
#include<cstring>
using namespace std;

int main() {

	// char s[100] = "Today is a rainy day";
	// char *ptr = strtok(s, " ");
	// cout << ptr << endl;

	// while(ptr != NULL) {
	// 	ptr = strtok(NULL, " ");
	// 	cout << ptr << endl;
	// }
	// delete ptr;

	char s1[100] = "Today, is a rainy, day";
	char *ptr1 = strtok(s1, ",");
	cout << ptr1 << endl;

	while(ptr1 != NULL) {
		ptr1 = strtok(NULL, ",");
		cout << ptr1 << endl;
	}

	return 0;
}