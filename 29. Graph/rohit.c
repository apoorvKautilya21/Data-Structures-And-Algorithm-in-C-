#include <stdio.h>
#include <stdlib.h>

// Making A Structure that stores the parameters of a tennis day
struct TennisDay{
	int outlook;
	int humid;
	int wind;
};

int main() {

	FILE *fp;
	int i, flag;
	struct TennisDay s[5];

	fp = fopen("TennisDay.txt", "w");

	if(fp == NULL) {
		printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
	}

	fprintf(fp, "\n18 / 03 / 2021\n\n");
	// Allowing 5 user to enter the parameters
	for(i = 0; i < 5; i++) {
		printf("\nEnter the outlook: Sunny as 0, Overcast as 1 and Rain as 2 : ");
		scanf("%d", &s[i].outlook);

		printf("\nEnter the Humidity: High as 0, Normal as 1 : ");
		scanf("%d", &s[i].humid);

		printf("\nEnter the Wind: Strong as 0, Weak as 1 : ");
		scanf("%d", &s[i].wind);

		fprintf(fp, "%d %d %d\n", s[i].outlook, s[i].humid, s[i].wind);
	}

	fprintf(fp, "\nOutput : \n");

	// Now we are finding out whether a match can be played or not
	for(i = 0; i < 5; i++) {

		if(s[i].outlook == 0) {
			flag = s[i].humid;
		}

		else if(s[i].outlook == 1) {
			flag = 1;
		} 

		else {
			flag = s[i].wind;
		}

		if(flag) {
			fprintf(fp, "\nMatch can be played on Day %d\n", i + 1);
		}
		else {
			fprintf(fp, "\nMatch can't be played on Day %d\n", i + 1);	
		}
	}

	fclose(fp);

	return 0;
}