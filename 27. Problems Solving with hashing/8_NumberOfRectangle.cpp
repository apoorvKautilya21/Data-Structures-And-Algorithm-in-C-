// https://www.geeksforgeeks.org/how-to-create-an-unordered_set-of-user-defined-class-or-struct-in-c/
#include<iostream>
#include<functional>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;
/*

8
0 0
0 1
1 1
1 0
2 1
2 0
3 1
3 0

*/

class Point {
public:
	int x, y;

	Point() {

	}

	Point(int x, int y){
		this -> x = x;
		this -> y = y;
	}

	bool operator==(const Point&p) const{
		return p.x == x and p.y == y;
	}
};

class hash_pair { 
public:
    size_t operator()(const Point& p) const
    { 
    	hash<int> myHash;
        auto hash1 = myHash(p.x); 
        auto hash2 = myHash(p.y); 
        return hash1 + hash2; 
    } 
}; 


int numberOfRightTraingle(vector<Point> coord) {
		
	int n = coord.size();
	unordered_set<Point, hash_pair> lookUp;

	for(auto p:coord) {
		lookUp.insert(p);
	}	

	int count = 0;
	for(auto it : lookUp) {
		for(auto jt : lookUp) {
			Point p1 = it;
			Point p2 = jt;

			// if points are horizontal or vertical to each other than continue
			if(p1.x == p2.x or p1.y == p2.y) {
				continue;
			}

			Point p3(p1.x, p2.y);
			Point p4(p2.x, p1.y);

			if(lookUp.find(p3) != lookUp.end() and lookUp.find(p4) != lookUp.end()) {
				count++;
			}
		}
	}

	return count / 4;
}

int main() {

	int n;
	int x[100], y[100];
	cin >> n;

	vector<Point> coord;

	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		Point p(x, y);
		coord.push_back(p);	
	}

	cout << numberOfRightTraingle(coord) << endl;

	return 0;
}

// .	.	.	.

// .	.	.	.
