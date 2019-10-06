// Exemplo de implementação de funções para calcular média ponderada parcial de um aluno

#include <stdio.h>
#include <stdlib.h>

// Declaração do protótipo da função
float mediap (float valor, float peso);

float nota1, nota2;

main () {

	// Considerando trabalho como peso 3 e prova parcial como peso 7 para cálculo de média parcial.

	printf("Informe a nota do trabalho: \n");
	scanf("%f", &nota1);
	printf("Informe a nota da prova: \n");
	scanf("%f", &nota2);
	printf("Media Parcial = %.2f\n", mediap(nota1, 0.3) + mediap(nota2, 0.7));

	printf("\nInforme a nota parcial: \n");
	scanf("%f", &nota1);
	printf("Informe a nota final: \n");
	scanf("%f", &nota2);
	printf("\nMedia = %.2f", mediap(nota1, 0.4) + mediap(nota2, 0.6));
}

// Função mediap
float mediap (float valor, float peso){
	return (valor*peso);
}