//Calculate production price of a product considering certain taxes in Brazil (PIS and INSS)

#include <stdio.h>
#include <stdlib.h>

float work_force_value, raw_mat_value, pis, inss, prod_price;

main ()
{
	printf ("Raw material value: \n");
	scanf ("%f", &raw_mat_value);
	printf ("Work force value: \n");
	scanf ("%f", &work_force_value);
	pis = (work_force_value + raw_mat_value)*0.01;
	inss = (work_force_value + raw_mat_value)*0.10;
	prod_price = (work_force_value + raw_mat_value + pis + inss);
	printf ("Production price: %.4f\n", prod_price);
	printf ("PIS tax value: %.2f\n", pis);
	printf ("INSS tax value: %.2f\n", inss);
	
	system ("pause");
}
