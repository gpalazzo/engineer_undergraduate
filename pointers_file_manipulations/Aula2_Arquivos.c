/* 
Para gravar de modo a não ter problemas com lixo de memória, guardamos as informações como se fossem registros (toda cadeia de informação
é guardada uma única vez).

Armazenamento em arquivo com os dados formatados

fprintf() - esse comando permite escrever as informações recebidas em arquivo, ou seja, permite gravar informações em arquivo de forma
formatada;

Sintaxe:
fprintf(ponteiro_arquivo, "tipo_dos_dados", variáveis);

Exemplo:
fprintf(arquivo, "%s %f %f", nome_aluno, nota1, nota2);

fscanf() - esse comando permite ler as informações armazenadas de maneira formatada em um arquivo

Sintaxe:
fscanf(ponteiro_arquivo, "tipo_dos_dados", variáveis);

Exemplo:
fscanf(arquivo, "%s %f %f", nome_aluno, &nota1, &nota2);

OBS: Não deve-se utilizar, no fscanf, o & antes do nome da variável apenas quando ela for do tipo string.
*/

// PROGRAMA PARA LER O NOME, O VALOR E A QUANTIDADE EM ESTOQUE DE N PRODUTOS E ARMAZENAR AS INFORMAÇÕES EM ARQUIVO DE MANEIRA FORMATADA

#include <ctype.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char resposta, nome_produto[30];
float valor;
int qtd_estoque;

FILE *ponteiro; //Criação do ponteiro para o arquivo

main () {

	// Abertura do arquivo para gravação em modo texto
	ponteiro = fopen("banco1.txt", "a"); //Com a letra "a", ele sempre faz o insert nesse arquivo existente

	do {

		printf("Informe o nome do produto: \n");
		fflush(stdin);
		gets(nome_produto);

		printf("Informe o valor do produto: \n");
		scanf("%f", &valor);

		printf("Informe a quantidade do %s em estoque: \n", nome_produto);
		scanf("%i", &qtd_estoque);

		//Gravar as informações em arquivo
		fprintf(ponteiro, "%s %.2f %i\n", nome_produto, valor, qtd_estoque);

		printf("Outro produto? <s/n>\n");
		resposta = getche();

	} while (toupper(resposta) == 'S');

	fclose(ponteiro);
}

/* Comando para comparar o login informado pelo usuário com as informações em um arquivo texto
char login[30];
while (fscanf(...) != EOF) {
	if (strcmp (login, usuario) == 0)
	...
}
*/