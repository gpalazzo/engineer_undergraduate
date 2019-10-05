//Calculate weighted average considering two values.

#include <stdio.h>
#include <stdlib.h>

float value1, value2, weighted_avg;

main () {
	
	printf ("Value 1: ");
	scanf ("%f", &value1);
	printf ("Value 2: ");
	scanf ("%f", &value2);
	weighted_avg = (value1*0.4 + value2*0.6);
	printf ("Weighted average: %.3f\n", weighted_avg);

	system ("pause");	

}