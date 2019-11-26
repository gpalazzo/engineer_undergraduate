/*Simulação de uma calculadora - uso de funções */

//declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//função calculadora
float calculadora(float num1, float num2, int operacao)
{
	switch(operacao)
	{
		case 1 : return num1 + num2;
		case 2 : return num1 - num2;
		case 3 : return num1 * num2;
		case 4 : return num1 / num2;
	}
}

//função menu
void menu()
{
	//declaração de variável local
	int opcao;
	float numero1, numero2;
	printf("Informe o primeiro numero");
	scanf("%f", &numero1);
	printf("\nInforme o segundo numero");
	scanf("%f", &numero2);
	printf("\n1-Soma\n2-Subtracao\n3-Multiplicacao\n4-Divisao\n0-Sair");
	printf("\nOperacao?: ");
	scanf("%i", &opcao);
	
	//estrutura condicional
	switch(opcao)
	{
		case 1 : {
	         		printf("Resultado = %.2f",calculadora(numero1,numero2,1));
	         		system("pause");
	         		menu();
		         } 
		case 2 : {
	         		printf("Resultado = %.2f",calculadora(numero1,numero2,2));
	         		system("pause");
	         		menu();
		         } 		  
		case 3 : {
	         		printf("Resultado = %.2f",calculadora(numero1,numero2,3));
	         		system("pause");
	         		menu();
		         } 
		case 4 : {
	         		printf("Resultado = %.2f",calculadora(numero1,numero2,4));
	         		system("pause");
	         		menu();
		         }
		case 0 : exit(0);		  
		default : {
					printf("Opcao Invalida!!!");
			        system("pause");
			        menu();
			      }	
    } 
}

//declaração da função principal
main()
{
	//chamada da função
	menu();
}


