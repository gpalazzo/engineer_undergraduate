//Exercício 2 Prova
//declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//declaração da estrutura de dados
struct aluno
{
	int codigo;
	char nome[30];
	float notap, notaf, media;
};

struct aluno classe[10];

//declaração das variáveis
char resp;
int i=0;

//declaração da função principal
main()
{
	//entrada de dados
	do
	{
		system("cls");
		printf("Informe o codigo");
		scanf("%i", &classe[i].codigo);
		fflush(stdin);
		printf("Informe o nome");
		gets(classe[i].nome);
		printf("Informe a nota parcial");
		scanf("%f", &classe[i].notap);
		printf("Informe a nota final");
		scanf("%f", &classe[i].notaf);
		classe[i].media=classe[i].notap*0.4+classe[i].notaf*0.6;
		
		//controlar a estrutura de repetição
		i++;
		printf("Outro aluno <s/n>:? ");
		resp = getche();
	} while((resp=='s'||resp=='S') && i<10);
}



