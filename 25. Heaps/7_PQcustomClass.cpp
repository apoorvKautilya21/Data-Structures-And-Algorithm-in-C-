#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class Person {
public:
	int age;
	string name;

	Person(int a, string s) {
		age = a;
		name = s;
	}
};


class PersonCompare {
public:

	bool operator()(Person A, Person B) {
		return A.age < B.age;
	}
};


int main() {

	priority_queue<Person, vector<Person>, PersonCompare> pq;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a;
		string s;
		cin >> s >> a;
		Person p(a, s);
		pq.push(p);
	}

	int k = 3;
	for(int i = 0; i < k; i++) {
		Person p = pq.top();
		cout << p.name << " " << p.age << endl;
		pq.pop();
	}

	return 0;
}