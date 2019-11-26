/*Programa para cadastrar e listar o nome, a nota parcial e
a nota final dos alunos */

//declara��o das bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

//declara��o das vari�veis
char nome[30], continua;
float notap, notaf;

//prot�tipo das fun��es
void cadastrar();
void listar();

//declara��o do ponteiro para o arquivo
FILE *pontarq;

//fun��o menu
void menu()
{
	//declara��o vari�vel local
	int opcao;
	//op��es do menu
	system("cls");
	printf("1 - Cadastrar");
	printf("\n2 - Listar");
	printf("\n3 - Sair");
	printf("\nOpcao?: ");
	scanf("%i", &opcao);
	
	//execu��o das op��es
	switch(opcao)
	{
		case 1 : cadastrar();
				menu();
		case 2 : listar();
				menu();
		case 3 : exit(0);
		default : 
				{
					printf("opcao invalida!!!");
					system("pause");
			    }  
				menu();			
	}
}

//fun��o principal
main()
{
	menu();
}

void cadastrar()
{
	//abrir o arquivo para grava��o modo texto
	pontarq = fopen("banco2.txt", "a");
	do
	{
		system("cls");
		printf("Informe o nome do aluno");
		fflush(stdin);
		gets(nome);
		printf("Informe a nota parcial");
		scanf("%f", &notap);
		printf("Informe a nota final");
		scanf("%f", &notaf);
		
		//gravar as informa��es no arquivo
		fprintf(pontarq, "%s %f %f", nome, notap, notaf);
		
		printf("Outro aluno <S/N>?: ");
		continua = getche();
	} while(toupper(continua)=='S');
	fclose(pontarq);
}

//fun��o listar
void listar()
{
	//abrir arquivo para leitura em modo texto
	if((pontarq=fopen("banco2.txt", "r"))==NULL)
	{
		printf("erro ao abrir o arquivo");
		system("pause");
		menu();
	}
	while((fscanf(pontarq, "%s %f %f", nome, &notap, &notaf))!=EOF)
	{
		printf("\nNome: %s \nNota Parcial: %.2f", nome, notap);
		printf("\nNota Final: %.2f \nMedia: %.2f", notaf, notap*0.4+notaf*0.6);
	}
	system("pause");
}
