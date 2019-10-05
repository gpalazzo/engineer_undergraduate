//Calculate the multiplication table (from 0 to 10) of any natural number

#include <stdio.h>
#include <stdlib.h>

int mult_table, i, R;

main ()
{
	printf ("Natural number: \n");
	scanf ("%d", &mult_table);
	printf ("Multiplication table from 0 to 10:\n");
	if (mult_table >= 0){
	
		for (i=0; i<=10; i++){
			R=(mult_table*i);
			printf ("%dx%d=%d\n", mult_table, i, R);
		}

	}

	else{
	printf ("Invalid value.\n");
	}

	system ("pause");
}
