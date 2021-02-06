#include<iostream>
#include<unordered_map>
using namespace std;

int numberOfRightTraingle(int x[], int y[], int n) {

	unordered_map<int, int> xparrPoints;	// first number stores x coor and secodnd stores count of number stores that x coordinate
	unordered_map<int, int> yparrPoints;


	for(int i = 0; i < n; i++) {
		xparrPoints[x[i]]++;
		yparrPoints[y[i]]++;
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		// Total Number of points parallel to y - axis that can make right angled traingle with pivot point a (x[i], y[i])
		int x_points = xparrPoints[x[i]] - 1;
		// Total Number of points parallel to x - axis that can make right angled traingle with pivot point a (x[i], y[i])
		int y_points = yparrPoints[y[i]] - 1;

		ans += x_points * y_points;
	}

	return ans;
}

int main() {

	int n;
	int x[100], y[100];
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	cout << numberOfRightTraingle(x, y, n) << endl;

	return 0;
}