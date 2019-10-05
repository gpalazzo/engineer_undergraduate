//Calculate net salary based on discount ranges

#include <stdlib.h>
#include <stdio.h>

float salary, discount, net_salary;

main () {

	printf ("Gross salary: \n");
	scanf ("%f", &salary);

	if (salary <= 2000)
		discount = (salary*0.05);
	else if (salary <= 3000)
		discount = (salary-2000)*0.10 + 1000*0.05;
	else
		discount = (salary-3000)*0.15 + 1000*0.10 + 1000*0.05;

	net_salary = (salary-discount);
	printf ("Discount: %f\n", discount);
	printf ("%f - %f = %f\n", salary, discount, net_salary);
	printf ("Net salary: %f\n", net_salary);
	
	system ("pause");

}