#include<stdio.h>

int main() {

	int n, i, j;
	scanf("%d", &n);

	for(i = 1; i <= n; i++) {
		// First off all we are printing n - i spaces 
		for(j = 1; j <= n - i; j++) {
			printf("  ");
		}
		// Now Printing numbers from 1 to i
		j = 0;
		while(j < i) {
			j++;
			printf("%d ", j);
		}
		j--;
		// Now we are printing number from i - 1 to 1 in decreasing order
		while(j >= 1) {
			printf("%d ", j);
			j--;
		}
		// after each loop we are going to a new line
		printf("\n");
	}
}