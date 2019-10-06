//Exercício simulando calculo do Índice Kappa

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int i;
float observada, esperada, kappa;

float cobservada (int valor1, int valor2) { //Funcão para calcular a concordância observada.

	float total = 6, resultado;
	resultado = (valor1+valor2)/total;
	return resultado;
}

float cesperada (int total1, int total2) { //Funcão para calcular a concordância esperada.

	float total = 36, resultado;
	resultado = (total1 + total2) / total;
	return resultado;
}

float ckappa (float obs, float esp) { //Funcão para calcular a concordância kappa.

	float resultado;

	if (obs == 1) {
		resultado = 1;
	}

	else {
		resultado = (obs - esp) / ( 1 - esp);
	}

	return resultado;
}

main () {

	int SS = 0, SN = 0, NS = 0, NN = 0, A1, A2, B1, B2;
	char juiz1, juiz2;

	for (i = 1; i <= 6; i++) {

		printf("Informe resposta Juiz1: \n");
		juiz1 = getche();
		juiz1 = toupper(juiz1);
		printf("Informe resposta Juiz2: \n");
		juiz2 = getche();
		juiz2 = toupper(juiz2);

		if (juiz1 == 'S' && juiz2 == 'S') {
			SS++;
		}

		else if (juiz1 == 'S' && juiz2 == 'N') {
			SN++;
		}

		else if (juiz1 == 'N' && juiz2 == 'S') {
			NS++;
		}

		else if (juiz1 == 'N' && juiz2 == 'N') {
			NN++;
		}

		else {
			printf("Resposta incorreta.\n");
			i--;
		}
	}

	A1 = SS + NS;
	A2 = SN + NN;
	B1 = SS + SN;
	B2 = NS + NN;

	observada = cobservada (SS, NN);
	printf("Concordancia Observada = %.2f\n", observada);

	esperada = cesperada (A1 * B1, A2 * B2);
	printf("Concordancia Esperada = %.2f\n", esperada);

	kappa = ckappa (observada, esperada);
	printf("Concordancia Kappa = %.2f\n", kappa);

}