/* Implementar um algoritmo utilizando a linguagem C para resolver o seguinte problema: O José tem 150 centímetros e cresce 
2 centímetros por ano. O Pedro tem 110 centímetros e cresce 3 centímetros por ano. Em quantos anos Pedro será maior que o José. */

#include <stdio.h>

int main () {

	int altura_jose = 150, cresc_jose_ano = 2, altura_pedro = 110, cresc_pedro_ano = 3, i = 1;

	do {

		altura_jose = altura_jose + (2 * i / i);
		altura_pedro = altura_pedro + (3 * i / i);
		i++;
	} while (altura_jose > altura_pedro);

	printf("Pedro passara Jose em %d anos.\n", i);
}