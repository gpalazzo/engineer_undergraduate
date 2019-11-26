//Exemplo de arquivo modo leitura
//declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//declaração do ponteiro do arquivo
FILE *arquivo;

//variável de saída de dados
char saida;

//declaração da função principal
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


