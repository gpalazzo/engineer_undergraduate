#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

char resp = 'S';
int contador[4];
float peso, altura;

main () {

	do {
		
		system("cls");
		
		printf("Informe seu peso: \n");
		scanf("%f", &peso);

		printf("Informe sua altura, em metros: \n");
		scanf("%f", &altura);

		if ((peso/(altura*altura)) < 18.5) {
			contador[0] += 1;
		}

		else if ((peso/(altura*altura)) < 25) {
			contador[1] += 1;
		}

		else if ((peso/(altura*altura)) < 30) {
			contador[2] += 1;
		}

		else {
			contador[3] += 1;
		}

		printf("Deseja informar outra pessoa? <s/n>\n");
		resp = getche ();
	} while (toupper(resp) == 'S');

	printf("\nHa %d pessoas(s) abaixo do peso.\n", contador[0]);
	printf("Ha %d pessoa(s) com peso normal.\n", contador[1]);
	printf("Ha %d pessoa(s) acima do peso.\n", contador[2]);
	printf("Ha %d pessoa(s) obesas.\n", contador[3]);

	if (contador[0] > (contador[1] && contador[2] && contador[3])) {
		printf("\nHa mais pessoas abaixo do peso (IMC < 18.5)\n");
	}

	else if (contador[1] > (contador[0] && contador[2] && contador[3])) {
		printf("\nHa mais pessoas com peso normal (IMC < 25)\n");
	}

	else if (contador[2] > (contador[0] && contador[1] && contador[3])) {
		printf("\nHa mais pessoas acima do peso (IMC < 30)\n");
	}

	else {
		printf("\nHa mais pessoas obesas (IMC >= 30)\n");
	}
}
