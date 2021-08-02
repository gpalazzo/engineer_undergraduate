/*Revisão estrutura de dados */

//declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

//declaração das estruturas de dados
struct pessoa
{
	int cpf;
	char nome[30];
	char datanasc[10];
};

struct pessoa_aluno
{
	struct pessoa pessoaalu;
	char curso[20];
};

struct pessoa_docente
{
	struct pessoa pessoadoc;
	int carga_horaria;
};

struct pessoa_aluno aluno[MAX];
struct pessoa_docente docente[MAX];

//protótipo das funções
void cadastra_aluno();
int mostra_aluno(char cursox[]);
void cadastra_docente();
void mostra_docente();

//função menu
void menu()
{
	//declaração da variável local
	int opcao;
	char coringa[20];
	printf("\n*** MENU ***");
	printf("\n1 - Cadastrar aluno");
	printf("\n2 - Mostrar Qtd alunos");
	printf("\n3 - Cadastrar docente");
	printf("\n4 - Mostrar docente");
	printf("\n0 - Sair");
	printf("\nOpcao: ? ");
	scanf("%d", &opcao);
	
	switch(opcao)
	{
		case 1 : cadastra_aluno();
				 menu(); 
		case 2 : {
			         printf("Informe o nome do curso: ");
			         fflush(stdin);
			         gets(coringa);
			         printf("Qtd alunos do curso %s = %i", coringa, mostra_aluno(coringa));
			     } 
			         menu();
		case 3 : cadastra_docente();
				 menu();
		case 4 : mostra_docente();
				 menu();
		case 0 : exit(0);
    } 
}

//função principal
main()
{
    menu();
}

void cadastra_aluno()
{
	int i;
	//entrada de dados aluno
	for(i=0; i<MAX; i++)
	{
		printf("Informe o cpf do aluno");
		scanf("%i", &aluno[i].pessoaalu.cpf);
		printf("Informe o nome do aluno");
		fflush(stdin);
		gets(aluno[i].pessoaalu.nome);
		printf("Informe a data de nascimento");
		fflush(stdin);
		gets(aluno[i].pessoaalu.datanasc);
		printf("Informe o curso");
		fflush(stdin);
		gets(aluno[i].curso);
	} 
}	

int mostra_aluno(char cursox[])
{
	int i, contaeng=0;
	for(i=0; i<MAX; i++)
	{
		//contar cursos
		if(strcmp(aluno[i].curso,cursox)==0)
			contaeng++;	
		
	}
	return contaeng;
}

void cadastra_docente()
{
	int i;
	//entrada de dados docente
	for(i=0;i<MAX;i++)
	{
		printf("Informe o cpf do professor");
		scanf("%i", &docente[i].pessoadoc.cpf);
		printf("Informe o nome do professor");
		fflush(stdin);
		gets(docente[i].pessoadoc.nome);
		printf("Informe a data nasc. do professor");
		fflush(stdin);
		gets(docente[i].pessoadoc.datanasc);
		printf("Informe a carga horaria do professor");
		scanf("%i", &docente[i].carga_horaria);
    }  
}

void mostra_docente()
{
    int i;
    for(i=0; i<MAX; i++)
    {
		//mostrar o nome dos docentes que têm carga horária >=20
		if(docente[i].carga_horaria >= 20)
		    printf("\nDocente: %s", docente[i].pessoadoc.nome);
	}
	
}


