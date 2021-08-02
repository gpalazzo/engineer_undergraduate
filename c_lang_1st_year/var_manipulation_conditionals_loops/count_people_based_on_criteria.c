/*
Count people based on some criteria, such as:
	- gender;
	- eyes color;
	- hair color.

female_condition:
	gender == F (Female);
	eye_color == 1 (Blue);
	15 <= age <= 30
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int qtym=0, qtyf=0, eye_color, age, blue_eyes=0, black_eyes=0, brown_eyes=0, hair_color, blond_hair=0, brown_hair=0, black_hair=0, female_condition;
char gender;

main() {

	for (int i=0; i<3; i++) {

		system ("cls");
		printf ("Gender (M or F): ");
		gender=getche();

		if (gender == 'M')
			qtym+=1;
		else
			qtyf+=1;

		printf ("\n Color eyes \n<1 - Blue>");
		printf ("\n");
		printf ("<2 - Brown>");
		printf ("\n");
		printf ("<3 - Black>");
		printf ("\n");
		scanf ("%d", &eye_color);

		switch (eye_color) {
			case 1: blue_eyes+=1;
			break;
			case 2: brown_eyes+=1;
			break;
			case 3: black_eyes+=1;
			break;
		}

		printf ("\n Hair color\n<1 - Blond>");
		printf ("\n");
		printf ("<2 - Brown>");
		printf ("\n");
		printf ("<3 - Black>");
		scanf ("%d", &hair_color);

		switch (hair_color) {
			case 1: blond_hair+=1;
			break;
			case 2: brown_hair+=1;
			break;
			case 3: black_hair+=1;
			break;
		}

	    printf ("\n Age: ");
	    scanf ("%d", &age);	
	    
	    if ( gender == 'F' && eye_color == 1 && age >= 15 && age <= 30)
	    	condicaofeminina+=1;
	}

    printf ("\n Results");
    printf ("\n");
	printf ("There is %d people from Male gender.", qtym);
    printf ("\n There is %d people from Female gender", qtyf);
    printf ("\n\n");
    printf ("There is %d people with blue eyes", blue_eyes);
    printf ("\n There is %d people with brown eyes", brown_eyes);
    printf ("\n There is %d people with black eyes", black_eyes);
    printf ("\n\n");
    printf ("There is %d people matching the female condition", condicaofeminina);
    printf ("\n");

    system ("pause");

}
