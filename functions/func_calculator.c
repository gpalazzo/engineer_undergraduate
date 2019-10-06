// Simulação de calculadora para executar as 4 operações fundamentais usando funções

#include <stdio.h>
#include <stdlib.h>

float calculadora (float num1, float num2, int operacao){

	switch (operacao){
		case 1: return num1 + num2;
		case 2: return num1 - num2;
		case 3: return num1 * num2;
		case 4: return num1 / num2;
	}
}

void menu () {

	system ("cls");
	int escolha;
	float numero1, numero2;

	printf("Informe a operacao a ser realizada, sendo:\n");
	printf("\n(1) Soma\n(2) Subtracao\n(3) Multiplicacao\n(4) Divisao\n(0) Sair do menu\n");
	scanf("%i", &escolha);
	if (escolha == 0){
		exit(0);
	}
	
	else if (escolha > 4){
		printf("Opcao invalida.\n");
		system ("pause");
		menu ();
	}
	
	else {
		printf("Informe o primeiro numero: \n");
		scanf("%f", &numero1);
		printf("Informe o segundo numero: \n");
		scanf("%f", &numero2);
	
		switch (escolha){
			case 1: {
				printf("Resultado = %.2f\n", calculadora(numero1, numero2, 1));
				system("pause");
				menu ();
			}
	
			case 2: {
				printf("Resultado = %.2f\n", calculadora(numero1, numero2, 2));
				system("pause");
				menu ();
			}
	
			case 3: {
				printf("Resultado = %.2f\n", calculadora(numero1, numero2, 3));
				system("pause");
				menu ();
			}
	
			case 4: {
				printf("Resultado = %.2f\n", calculadora(numero1, numero2, 4));
				system("pause");
				menu ();
			}
		}
	}
}
main (){

	menu ();
}