#include<iostream>
#include<algorithm>
using namespace std;


int main() {

	int a[] = {1,2,3,11,12,123,1313,4,5,6};
	int n = sizeof(a) / sizeof(int);

	int key;
	cin >> key;
	auto it = find(a, a+n, key);		// Last term is not inclusive
	int index = it - a;

	if(index == n) {
		cout <<"Not Found" << endl;
	}
	else{
		cout << index << endl;
	}



	return 0;
}