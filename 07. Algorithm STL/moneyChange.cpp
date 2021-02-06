#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b) {
	// cout << a << "  " << b << endl;
	return a <= b;
}

int main() {

	int coins[] = {1,2,5,10,20,50,100,200,500,2000};
	int n = sizeof(coins) / sizeof(int);
	int money = 1068;

	// we can directly use upper bound like this but we will use lower bound to show the use compare
	// int ub = upper_bound(coins, coins+n, money) - coins - 1;
	// cout << ub << " value: " << coins[ub];
	
	int lb = lower_bound(coins, coins+n, money, compare) - coins - 1;
	cout << lb << " value: " << coins[lb] << endl;	

	while(money != 0) {
		lb = lower_bound(coins, coins+n, money, compare) - coins - 1;
		money -= coins[lb];
		cout << coins[lb] << ", ";
	}

	return 0;
}