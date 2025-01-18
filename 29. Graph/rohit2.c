#include <stdio.h>

int main() {

	int number;
	int temp, last_dig;
	int even = 0, odd = 0;
	printf("\nEnter the number : ");
	scanf("%d", &number);

	for(temp = number; temp != 0; temp = temp / 10) {
		// Extracting out the last digit
		last_dig = temp % 10;
		
		if(last_dig % 2 == 0) {
			even++;
		}
		else {
			odd++;
		}
	}

	printf("Even = %d\n", even);

	return 0;
}