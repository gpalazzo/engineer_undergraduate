//Exemplo de arquivo modo leitura
//declara��o das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//declara��o do ponteiro do arquivo
FILE *arquivo;

//vari�vel de sa�da de dados
char saida;

//declara��o da fun��o principal
main()
{
	//abertura do arquivo em modo de leitura
	if((arquivo=fopen("arquivo1.txt","r"))==NULL)
	{
	   printf("nao foi possivel abrir o arquivo");
	   exit(0);
    }  
	while((saida = getc(arquivo)) != EOF)
	    printf("%c",saida); 
	
	//fechar o arquivo
	fclose(arquivo);  
}


