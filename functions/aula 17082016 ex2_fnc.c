/*Exemplo de menu por meio de função */

//declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//função menu
void menu()
{
	//declaração de variável local
	int opcao;
	
	//limpar a tela
	system("cls");
	
	//opções do menu
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

//declaração da função principal
main()
{
	//teste de execução do menu
	menu();
}
