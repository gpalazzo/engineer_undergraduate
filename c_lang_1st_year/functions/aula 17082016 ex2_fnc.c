/*Exemplo de menu por meio de fun��o */

//declara��o das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//fun��o menu
void menu()
{
	//declara��o de vari�vel local
	int opcao;
	
	//limpar a tela
	system("cls");
	
	//op��es do menu
	printf("*** MENU ***");
	printf("\n1 - Opcao1");
	printf("\n2 - Opcao2");
	printf("\n3 - Opcao3");
	printf("\n0 - Sair");
	printf("\n\nOpcao: ? ");
	
	//entrada de dados
	scanf("%d", &opcao);
	
	//estrutura condicional
	switch(opcao)
	{
		case 1 : {
		     		printf("Opcao 1");
		     		system("pause");
		     		menu();      
		     	 }  
		case 2 : {
		     		printf("Opcao 2");
		     		system("pause");
		     		menu();      
		     	 }  
		case 3 : {
		     		printf("Opcao 3");
		     		system("pause");
		     		menu();      
		     	 } 
	    case 0 : exit(0);
	    default : {
		              printf("opcao invalida");
		              system("pause");
		              menu();
	              }
    } 
}

//declara��o da fun��o principal
main()
{
	//teste de execu��o do menu
	menu();
}
