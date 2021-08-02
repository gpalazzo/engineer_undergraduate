/*Exemplo de manipulação de arquivo com a função fwrite().
A função fwrite() é utilizada quando deseja-se armazenar 
as informações em arquivo no formato de registro (estrutura
de dados)
Sintaxe:
fwrite(ponteiro para os dados, tamanho da estrutura de dados,
quantidade de itens que serão gravados, ponteiro do arquivo)
o tamanho da estrutura de dados é encontrado com a função
sizeof().

Exemplo:
fwrite(&estrutura, sizeof(estrutura), 1, pontarquivo)
*/

//declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

//declaração da estrutura de dados
struct livro
{
	int ibsn;
	char titulo[40];
	char autor[40];
	int ano;
};

struct livro biblioteca;

//declaração das variáveis
char continua;

//declaração da função principal
main()
{
	//declaração do ponteiro do arquivo
	FILE *arquivo;
	
	//abrir o arquivo no modo texto para gravação
	arquivo = fopen("bancodedados.txt","a");
	
	//entrada de dados
	do
	{
		system("cls");
		printf("Informe o ISBN do livro: ");
		scanf("%i", &biblioteca.ibsn);
		printf("Informe o titulo do livro: ");
		fflush(stdin);
		gets(biblioteca.titulo);
		printf("Informe o autor do livro: ");
		fflush(stdin);
		gets(biblioteca.autor);
		printf("Informe o ano de publicacao do livro: ");
		scanf("%i", &biblioteca.ano);
		
		//gravar as informações em disco
		fwrite(&biblioteca,sizeof(biblioteca),1,arquivo);
		printf("Registro salvo com sucesso...");
		printf("Inserir outro registro <s/n>");
		continua = getche();
	} while(toupper(continua)=='S');
	//fechar o arquivo
	fclose(arquivo);
}










