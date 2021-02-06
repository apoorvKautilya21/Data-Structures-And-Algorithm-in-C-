#include<iostream>
#include<string>
#include<climits>
using namespace std;

string findWindow(string s, string pat) {

	int SL = s.length();
	int PL = pat.length();

	if(PL > SL) {
		return "None";
	}

	int fs[256] = {0};
	int fp[256] = {0};

	for(int i = 0; i < PL; i++) {
		fp[pat[i]]++;
	}

	int count = 0;	// to count the number of matched characters
	int min_window_length = INT_MAX;
	int start = 0;
	int start_ind = -1;		// start index for minimum window

	for(int i = 0; i < SL; i++) {

		char ch = s[i];
		fs[ch]++;

		// Maintain the count of the character matched
		if(fp[ch] != 0 and fs[ch] <= fp[ch]) {
			count++;
		}

		if(count == PL) {
			// Contract the window
			char temp = s[start];
			// loop to remove all the unwanted characters
			while(fp[temp] == 0 or fs[temp] > fp[temp]) {
				fs[temp] --;
				start += 1;
				temp = s[start];
			}

			// window size
			int window_size = i - start + 1;
			if(window_size < min_window_length) {
				min_window_length = window_size;
				start_ind = start;
			}

		}
	}
 
	if(start_ind == -1) {
		return "None";
	}

	string ans = s.substr(start_ind, min_window_length);
	return ans;
}

int main() {

	string s = "qwerty asdfgh qazxsw";
	string p = "qas";

	cout << findWindow(s, p) << endl;

	return 0;
}