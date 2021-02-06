#include<iostream> 
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Car{
public:
	string car_name;
	int x, y;

	Car() {
	}

	Car(string name, int x, int y) {
		this -> car_name = name;
		this -> x = x;
		this -> y = y;
	}

	int dist() {
		return x*x + y*y;
	}
};

bool compare(Car a, Car b) {
	int da = a.dist();
	int db = b.dist();

	if(da == db) {
		return a.car_name.length() < b.car_name.length();
	}
	return da < db;
}

int main() {
	int n;
	cin >> n;

	vector<Car> v;

	for(int i = 0; i < n; i++) {
		int x, y;
		string name;
		cin >> name >> x >> y;
		Car temp(name,x,y);
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), compare);

	for(auto p:v) {
		cout << "Car " << p.car_name << " Location " << p.x << "," << p.y << endl;
	}



	return 0;
}