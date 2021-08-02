/*Programa para cadastrar e listar o nome, a nota parcial e
a nota final dos alunos */

//declaração das bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

//declaração das variáveis
char nome[30], continua;
float notap, notaf;

//protótipo das funções
void cadastrar();
void listar();

//declaração do ponteiro para o arquivo
FILE *pontarq;

//função menu
void menu()
{
	//declaração variável local
	int opcao;
	//opções do menu
	system("cls");
	printf("1 - Cadastrar");
	printf("\n2 - Listar");
	printf("\n3 - Sair");
	printf("\nOpcao?: ");
	scanf("%i", &opcao);
	
	//execução das opções
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

//função principal
main()
{
	menu();
}

void cadastrar()
{
	//abrir o arquivo para gravação modo texto
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
		
		//gravar as informações no arquivo
		fprintf(pontarq, "%s %f %f", nome, notap, notaf);
		
		printf("Outro aluno <S/N>?: ");
		continua = getche();
	} while(toupper(continua)=='S');
	fclose(pontarq);
}

//função listar
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
