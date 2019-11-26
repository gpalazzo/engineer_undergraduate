/*Exemplo de manipula��o de arquivo com a fun��o fwrite().
A fun��o fwrite() � utilizada quando deseja-se armazenar 
as informa��es em arquivo no formato de registro (estrutura
de dados)
Sintaxe:
fwrite(ponteiro para os dados, tamanho da estrutura de dados,
quantidade de itens que ser�o gravados, ponteiro do arquivo)
o tamanho da estrutura de dados � encontrado com a fun��o
sizeof().

Exemplo:
fwrite(&estrutura, sizeof(estrutura), 1, pontarquivo)
*/

//declara��o das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

//declara��o da estrutura de dados
struct livro
{
	int ibsn;
	char titulo[40];
	char autor[40];
	int ano;
};

struct livro biblioteca;

//declara��o das vari�veis
char continua;

//declara��o da fun��o principal
main()
{
	//declara��o do ponteiro do arquivo
	FILE *arquivo;
	
	//abrir o arquivo no modo texto para grava��o
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
		
		//gravar as informa��es em disco
		fwrite(&biblioteca,sizeof(biblioteca),1,arquivo);
		printf("Registro salvo com sucesso...");
		printf("Inserir outro registro <s/n>");
		continua = getche();
	} while(toupper(continua)=='S');
	//fechar o arquivo
	fclose(arquivo);
}










