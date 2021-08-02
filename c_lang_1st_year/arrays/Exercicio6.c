/* 
Faça um programa que receba o total das vendas de cada vendedor e armazene-as em um vetor. Receba também o percentual de comissão de cada 
vendedor e armazene-os em outro vetor. Receba os nomes desses vendedores e armzene-os em um terceiro vetor. Existem apenas dez vendedores. 
Calcule e mostre:

a) Um relatório com os nomes dos vendedores e os valores a receber;
b) O total das vendas de todos os vendedores;
c) O maior valor a receber e quem o receberá;
d) O menor valor a receber e quem o receberá.
*/

#include <stdio.h>
#include <string.h>
#define MAX 2

main () {

	float comissao[MAX], vendas[MAX];
	char nome[30][MAX];
	int i;

	for (i = 0; i < MAX; i++) {

		printf("\nInforme seu nome: \n");
		fflush(stdin);
		gets(nome[i]);
		printf("\n%s, informe o total de vendas que realizou: \n", nome[i]);
		scanf("%f", &vendas[i]);
		printf("%s, informe o percentual de comissão recebido: \n", nome[i]);
		scanf("%f", &comissao[i]);
	}

	printf("Relatorio: \nNome      Vendas      Comissao\n");
	for (i = 0; i < MAX; i++) {
		printf("     %s     %f     %f\n", nome[i], vendas[i], comissao[i]);
	}
}