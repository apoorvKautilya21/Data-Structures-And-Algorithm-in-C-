#include<iostream>
#include<vector>
using namespace std;

class MinMaxStack {

	vector<int> stack;
	vector<int> min_stack;
	vector<int> max_stack;

public:
	void push(int data) {
		int current_min = data;
		int current_max = data;

		if(stack.size()) {
			current_max = max(data, max_stack.back());
			current_min = min(data, min_stack.back());
		}
		stack.push_back(data);
		min_stack.push_back(current_min);
		max_stack.push_back(current_max);
	}

	void pop() {
		stack.pop_back();
		min_stack.pop_back();
		max_stack.pop_back();
	}

	int get_min() {
		return min_stack[stack.size() - 1];
	}

	int get_max() {
		return max_stack[stack.size() - 1];
	}

	bool isEmpty() {
		return stack.size() == 0;
	}

	bool top() {
		return stack[stack.size() - 1];
	}

	void print() {
		for(int x:stack) {
			cout << x << " ";
		}
		cout << endl;

		for(int x:min_stack) {
			cout << x << " ";
		}
		cout << endl;

		for(int x:max_stack) {
			cout << x << " ";
		}
		cout << endl;

	}
};





int main() {

	MinMaxStack s;
	s.push(1);
	s.push(5);
	s.push(3);
	s.push(8);
	s.print();
	s.pop();
	s.print();

	return 0;
}



