//Calculate value to be paid due to extra luggage weight
   
#include <stdio.h>
#include <stdlib.h>

float weight, value, extra_weight;

main () {

	printf ("Luggage weight: \n");
	scanf ("%f", &weight);

	if ( weight <= 20 )
		value = 0;
	else if ( weight <= 40 )
		value = (weight-20)*2;
	else
		value = (weight-40)*5 + 20*2;

	extra_weight = (weight-20);
	printf ("Luggage weight: %.2f\n", weight);
	printf ("Extra luggage weight: %.2f\n", extra_weight);
	printf ("Value to be paid: %.2f\n", value);
	
	system ("pause");

}
