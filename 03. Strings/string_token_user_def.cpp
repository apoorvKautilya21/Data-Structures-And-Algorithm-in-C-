#include<iostream>
#include<cstring>
using namespace std;

char *mystrtok(char* s, char delim) {

	static char* input = NULL;
	// For 1st token sting won't be NULL
	if (s != NULL) {
		input = s;
	}

	// For last case when all tokens will be extracted
	if(input == NULL) {
		return NULL;	
	}

	char *output = new char[strlen(input) + 1];
	int i = 0;
	while(input[i] != delim && input[i] != '\0') {
		output[i] = input[i];
		i++;
	}

	output[i] = '\0';	
	if(input[i] == '\0') {
		input = NULL;
	}
	else {
		input = input + i + 1;
	}
	return output;
}



int main() {

	char s[100] = "Today, is a, rainy day";
	char *ptr = mystrtok(s, ',');
	cout << ptr << endl;

	while(ptr != NULL) {
		ptr = mystrtok(NULL, ',');
		cout << ptr << endl;
	}

	return 0;
}












