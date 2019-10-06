/*Algoritmo para exemplificar o uso de estrutura de dados,
em que deve-se informar os proventos de um colaborador para
o c�lculo do seu sal�rio bruto */

//declara��o das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//cria��o da estrutura de dados
struct folhacredito
{
	char nome[30];
	float salario;
	float he50;
	float he100;
	float adicnoturno;
};

//declara��o das vari�veis
char resp;
struct folhacredito provento;

//declara��o da fun��o principal
main()
{
	do 
	{
		printf("Informe o nome do colaborador");
		fflush(stdin);
		gets(provento.nome);
		printf("\nInforme o salario do colaborador");
		scanf("%f", &provento.salario);
		printf("\nInforme o numero de HE 50%");
		scanf("%f", &provento.he50);
		printf("\nInforme o numero de HE 100%");
		scanf("%f", &provento.he100);
		printf("\nInforme o numero de horas noturnas");
		scanf("%f", &provento.adicnoturno);
		
		//Mostrar o valor dos proventos
		printf("\nSalario = R$ %.2f", provento.salario);
		printf("\nValor HE50%% = R$ %.2f", ((provento.salario/220)*provento.he50)*1.5);
		printf("\nValor HE100%% = R$ %.2f", ((provento.salario/220)*provento.he100)*2);
		printf("\nValor Adicional Noturno = R$ %.2f", ((provento.salario/220)*provento.adicnoturno)*0.20);
		printf("\nTOTAL = R$ %.2f", (((provento.salario/220)*provento.he50)*1.5) + (((provento.salario/220)*provento.he100)*2)+(((provento.salario/220)*provento.adicnoturno)*0.20)+provento.salario);
				
		//perguntar se haver� outro c�lculo
		printf("\nOutro colaborador <s/n>?: ");
		resp = getche();
		
		
		
		
	} while (resp == 's' || resp == 'S');
}












