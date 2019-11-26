/* Faça um programa que carregue 3 vetores com 10 posicões cada um. O 
primeiro vetor com os nomes de dez produtos. O segundo vetor com os códigos 
dos dez produtos e o terceiro vetor com os preços dos produtos. Mostre um 
relatório apenas com o nome, o código, o preço e o novo preço dos produtos 
que sofrerão aumento. Sabe-se que os produtos que sofrerão aumento são 
aqueles que possuem código par ou preço superior a R$1.000,00. Sabe-se, 
ainda, que se o produto satisfaz as 2 condições acima (código e preço), 
o aumento será de 20%, se satisfaz apenas a condição do código, o aumento 
será de 15% e, se satisfizer apenas a condição do preço, o aumento será de 10%.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define arraysize 10

main () {

char nome_produto[sizeof(nome_produto)][arraysize], nome_produto_aumentou[sizeof(nome_produto_aumentou)][arraysize];
int codigo[arraysize], codigo_aumentou[arraysize];
float preco[arraysize], preco_aumentou[arraysize], preco_antigo[arraysize];

for (int i = 1; i <= arraysize; i++) {
	
	system("cls");
	printf("Informe o nome do %d produto: \n", i);
	fflush(stdin);
	gets(nome_produto[i]);

	printf("Informe o codigo do(a) %s: \n", nome_produto[i]);
	scanf("%d", &codigo[i]);

	printf("Informe o preco do(a) %s: \n", nome_produto[i]);
	scanf("%f", &preco[i]);
}

for (int i = 1; i <= arraysize; i++) {
	
	if ((codigo[i] % 2 == 0) && preco[i] > 1000) {
		preco_aumentou[i] = preco[i]*1.2;
		codigo_aumentou[i] = codigo[i];
		preco_antigo[i] = preco[i];
		strcpy (nome_produto_aumentou[i], nome_produto[i]);
	}

	else if (codigo[i] % 2 == 0) {
		preco_aumentou[i] = preco[i]*1.15;
		codigo_aumentou[i] = codigo[i];
		preco_antigo[i] = preco[i];
		strcpy (nome_produto_aumentou[i], nome_produto[i]);
	}

	else if (preco[i] > 1000) {
		preco_aumentou[i] = preco[i]*1.10;
		codigo_aumentou[i] = codigo[i];
		preco_antigo[i] = preco[i];
		strcpy (nome_produto_aumentou[i], nome_produto[i]);
	}

	else {}
}
	
	printf("Produtos que sofreram aumento: \n\n");
	printf("Nome          Codigo          Preco Antigo          Novo Preco\n");

for (int i = 1; i <= arraysize; i++) {

	printf("%s            %.0d            %.2f            %.2f\n", nome_produto_aumentou[i], codigo_aumentou[i], preco_antigo[i], preco_aumentou[i]);
}
}