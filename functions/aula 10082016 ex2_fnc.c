/*Vetor de estrutura de dados */
//declara��o das bibliotecas
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//cria��o da estrutura de dados
struct aluno
{
	char nome[30];
	float notap, notaf;
};

//declara��o da estrutura de dados
struct aluno aluno[5];

//declara��o das vari�veis 
int i;
float media;
char alunomenor[30];

//declara��o da fun��o principal
main()
{
	//entrada de dados
	for(i=0; i<5; i++)
	{
		printf("Informe o nome: ");
		fflush(stdin);
		gets(aluno[i].nome);
		printf("\nInforme a nota parcial");
		scanf("%f", &aluno[i].notap);
		printf("\nInforme a nota final");
		scanf("%f", &aluno[i].notaf);
	}
	
	//sa�da de dados
	for(i=0; i<5; i++)
	{
		printf("Nome: %s", aluno[i].nome);
		printf("Nota Parcial: %.2f", aluno[i].notap);
		printf("Nota Final: %.2f", aluno[i].notaf);
		printf("\n");
	}
	
	//encontrar o aluno que tem a menor m�dia
	media=aluno[0].notap*0.4+aluno[0].notaf*0.6;
	strcpy(alunomenor,aluno[0].nome);
	for(i=1;i<5;i++)
	{
		//colocar e comparar as m�dias
		if((aluno[i].notap*0.4+aluno[i].notaf*0.6)<media)
		{
			strcpy(alunomenor,aluno[i].nome);
			media = aluno[i].notap*0.4+aluno[i].notaf*0.6;
		}
	}
	//mostrar o nome do aluno com a menor m�dia
	printf("\nAluno com < media: %s", alunomenor);
		
}




