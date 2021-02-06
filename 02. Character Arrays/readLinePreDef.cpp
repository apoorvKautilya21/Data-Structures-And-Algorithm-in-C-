#include<iostream>
#include<cstring>
using namespace std;

int main() {

	char a[1000], b[1000];

	cin.getline(a,1000);
	cout << a << endl;

	cin.getline(b,1000, '$');
	cout << b;

	return 0;
}