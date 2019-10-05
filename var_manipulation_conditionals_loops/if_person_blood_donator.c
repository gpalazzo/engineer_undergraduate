/*
Says if a person can be a blood donator based on some criteria:
1. age;
2. weight;
3. amount of days since last donation;
4. gender.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char gender;
int age, last_donation_days;
float weight;

main () {

	printf ("Age: \n");
	scanf ("%d", &age);
	printf ("Weight: \n");
	scanf ("%f", &weight);
	printf ("Amount of days since last donation: \n");
	scanf ("%d", &last_donation_days);
	printf ("Gender as M or F\n");
	gender = getche();

	if ((age >= 16 && age <= 69 && weight >= 50 && gender == 'M' && last_donation_days >= 60) || (age >= 16 && age <= 69 && weight >= 50 && gender == 'F' && last_donation_days >= 90)) {
		printf ("\n");
		printf ("Donation approved\n");
	} else {
		printf ("\n");
		printf ("Donation disapproved\n");
	}

	system ("pause");

}
