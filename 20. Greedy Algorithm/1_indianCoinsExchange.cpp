#include<iostream>
#include<algorithm>
using namespace std;


int MinCoins(int coins[], int n, int money) {

	int n_coin = 0;
	while(money) {
		int ub = upper_bound(coins, coins + n, money) - coins - 1;
		money = money - coins[ub];
		cout << coins[ub] << " ";
		n_coin++;
	}
	cout << endl;
	return n_coin;
}


int main() {

	int money;
	cin >> money;

	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
	int n = sizeof(coins) / sizeof(int);
	cout << "Number of coins " << MinCoins(coins, n, money);





	return 0;
}