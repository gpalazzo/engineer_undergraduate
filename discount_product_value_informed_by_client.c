/*
Client will inform: product code, value and discount. If discount is greater than 30 per cent, then it will applies the maximum of 30 per cent discount. Otherwise,
it will apply the value informed by the client.
*/

#include <stdio.h>
#include <stdlib.h>

int code;
float value, perc_discount, price;

main () {

	printf ("Inform a code to the product:\n");
	scanf ("%d", &code);
	printf ("Product value:\n");
	scanf ("%f", &value);
	printf ("Discount in percentage:\n");
	scanf ("%f", &perc_discount);
	
	if ( perc_discount <= 30 ) {
		price = ((100-perc_discount)/100)*value;
	} else {
		printf ("Maximum discount is 30 per cent, so we will use it.\n");
		price = (value*0.7);
	}

	printf ("Product value without discount: %.2f\n",  value);
	printf ("Product value with discount: %.2f\n", price);
	
	system ("pause");
		
}