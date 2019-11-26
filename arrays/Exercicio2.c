/* 
Faça um programa que carregue um vetor com sete números inteiros, calcule e mostre:
a) os números múltiplos de 2;
b) os números múltiplos de 3;
c) os números múltiplos de 2 e 3.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamanho_vetor 7

int main () {

	int vetor[tamanho_vetor], i, multiplos2[tamanho_vetor], multiplos3[tamanho_vetor], multiplos6[tamanho_vetor];

	for (i = 0; i < tamanho_vetor; i++) {
		printf("Informe o %d valor do vetor: \n", i+1);
		scanf("%d", &vetor[i]);

		if (vetor[i] % 2 == 0) {
			fflush(stdin);
			vetor[i] = multiplos2[i];
		}

		if (vetor[i] % 3 == 0) {
			fflush(stdin);
			vetor[i] = multiplos3[i];
		}

		if (vetor[i] % 6 == 0) {
			fflush(stdin);
			vetor[i] = multiplos6[i];
		}
	}

	printf("Os multiplos de 2 sao: \n");
	for (i = 0; i < tamanho_vetor; i++) {
		printf("%d ", multiplos2[i]);
	}
}