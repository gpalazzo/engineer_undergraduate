/*Exemplo do uso da função fread
A função fread() é utilizada para ler as informações de um
arquivo que estão gravadas como registro (estrutura de dados)
Sintaxe:
fread(ponteiro dos dados, tamanho da estrutura de dados,
quantidade de itens de dados, ponteiro do arquivo)

Exemplo:
fread(&dados, sizeof(dados), 1, pontarquivo)
*/

//declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declaração da estrutura de dados
struct biblioteca
{
	int isbn;
	char titulo[40];
	char autor[40];
	int ano;
};

struct biblioteca livro;

//declaração da função principal
main()
{
	//declaração do ponteiro do arquivo
	FILE *pontarquivo;
	
	//abertura do arquivo em modo de leitura
	if((pontarquivo=fopen("bancodedados.txt","r"))==NULL)
	{
	    printf("Nao foi possivel abrir o arquivo");
	    exit(0);
	}
	
	//ler os dados do arquivo
	while((fread(&livro, sizeof(livro),1,pontarquivo)==1))
	{
		printf("\n\nISBN = %i ",livro.isbn);
		printf("\nTitulo = %s ",livro.titulo);
		printf("\nAutor = %s ", livro.autor);
		printf("\nAno  = %i ", livro.ano);
	}
	system("pause");
}
