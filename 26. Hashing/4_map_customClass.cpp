#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
	
class Student {
public:

	string firstName;
	string lastName;
	string rollNumber;

	Student(string fn, string ln, string rn) {
		firstName = fn;
		lastName = ln;
		rollNumber = rn;
	}

	bool operator==(const Student &s) const {
		return rollNumber == s.rollNumber;
	}
};

class HashFunc {
public:

	size_t operator()(const Student &s) const{
		return s.firstName.length() + s.lastName.length() + s.rollNumber.length();
	}
};


int main() {

	Student s1("Prateek", "Narang", "010");
	Student s2("Rahul", "Kumar", "023");
	Student s3("Aman", "Gupta", "012");
	Student s4("Prateek", "Singh", "023");
	Student s5("Anuj", "Gupta", "076");
	Student s6("Rahul", "Kumar", "827");

	unordered_map<Student, int, HashFunc> student_map;

	student_map[s1] = 100;
	student_map[s2] = 90;
	student_map[s3] = 78;
	student_map[s4] = 85;
	student_map[s5] = 83;
	student_map[s6] = 53;

	cout << student_map[s4] << endl;

	for(auto x:student_map) {
		cout << x.first.firstName << " " << x.first.lastName << " " << x.first.rollNumber << " : Marks " << x.second << endl;
	}

	return 0;
}