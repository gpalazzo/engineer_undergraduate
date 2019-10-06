// Exemplo de menu por meio de função

#include <stdio.h>
#include <stdlib.h>

// Função menu

void menu (){
	int opcao;

	system ("cls");

	// Opções do menu
	printf("*** MENU ***\n");
	printf("\n1 - Opcao1\n");
	printf("2 - Opcao2\n");
	printf("3 - Opcao3\n");
	printf("0 - Sair\n");

	printf("\n Qual opcao voce deseja?");
	scanf("%d", &opcao);

	switch (opcao){

		case 1: {
			printf("Opcao 1\n");
			system ("pause");
			menu ();
		}

		case 2: {
			printf("Opcao 2\n");
			system ("pause");
			menu ();
		}

		case 3: {
			printf("Opcao 3\n");
			system ("pause");
			menu ();
		}

		case 0: exit (0);

		default: {
			printf("Opcao invalida. \n");
			system ("pause");
			menu ();
		}
	}
}

main () {
	// Teste de execução

	menu ();
}