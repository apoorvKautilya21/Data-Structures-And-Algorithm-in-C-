#include<iostream>
#include<cstring>
using namespace std;

int main() {

	char a[] = "apple mango";
	int n = strlen(a);

	int curr_len = 1;
	int max_len  = 1;

	int visited_at[256]; 
	for(int i = 0; i < 256; i++) {
		visited_at[i] = -1;
	} 
	visited_at[a[0]] = 0;

	for(int i = 1; i < n; i++) {
		int last_occur = visited_at[a[i]];
		if(last_occur == -1 or i - curr_len > last_occur) {
			curr_len += 1;
		}
		else {
			curr_len = i - last_occur;
		}
		max_len = max(max_len, curr_len);
		visited_at[a[i]] = i;
	}

	cout << max_len << " ";

	return 0;
}