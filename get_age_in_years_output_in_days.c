// get the age in years and transform into days.

#include <stdio.h>
#include <stdlib.h>

int age_years;
float age_days;

main () {

	printf ("Age in years: ");
	scanf ("%d", &age_years);
	age_days=(age_years*365.25);
	printf ("Age in days: %.2f\n", age_days);
	system ("pause");

}