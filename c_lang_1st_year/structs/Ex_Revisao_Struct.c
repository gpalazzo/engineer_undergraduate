/* Revis�o de estrutura de dados */

// O retorno de uma fun��o � sempre �nico!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3

struct pessoa {
	int cpf;
	char nome[30];
	char datanasc[10];
};

struct pessoa_aluno {
	struct pessoa pessoaalu;
	char curso[20];
};

struct pessoa_docente {
	struct pessoa pessoadoc;
	int carga_horaria;
};

struct pessoa_aluno aluno[MAX];
struct pessoa_docente docente[MAX]; //MAX � definido pela diretiva #define.

// Como algumas fun��es foram declaradas depois da fun��o principal, temos que declarar o prot�tipo delas antes da main:
void cadastra_aluno ();
int mostra_aluno (char cursox []);
void cadastra_docente ();
void mostra_docente (int carga_horaria_informada);

void menu () {

	system("cls");
	
	int opcao, carga_horaria_informada; // Vari�vel local
	char coringa[40];

	printf("\n *** MENU *** \n");
	printf("1 - Cadastrar aluno\n");
	printf("2 - Mostrar quantidade de alunos\n");
	printf("3 - Cadastrar docente\n");
	printf("4 - Mostrar docente\n");
	printf("0 - Sair\n");

	printf("\nQual opcao voce deseja?\n");
	scanf("%d", &opcao);

	switch (opcao) {

		case 1: {
			cadastra_aluno ();
			menu ();
		}

		case 2: {
			printf("Informe o nome do curso: \n");
			fflush(stdin);
			gets(coringa);
			printf("Quantidade de alunos do curso %s = %i.\n", coringa, mostra_aluno(coringa));
			system("pause");
		}
		menu ();

		case 3: {
			cadastra_docente ();
			menu ();
		}

		case 4: {
			printf("Informe a carga horaria que deseja comparar: \n");
			scanf("%d", &carga_horaria_informada);
			mostra_docente (carga_horaria_informada);
		}
		menu ();
		

		case 0: exit(0);
	}
}

main () {

	menu ();
}

void cadastra_aluno () {

	int i;

	for (i = 0; i < MAX; i++) {

		// Entrada de dados do aluno
		printf("Informe o cpf do aluno: \n");
		scanf("%d", &aluno[i].pessoaalu.cpf);

		printf("Informe seu nome do aluno: \n");
		fflush(stdin);
		gets(aluno[i].pessoaalu.nome);

		printf("Informe a data de nascimento do aluno: \n");
		fflush(stdin);
		gets(aluno[i].pessoaalu.datanasc);

		printf("Informe o curso: \n");
		fflush(stdin);
		gets(aluno[i].curso);

		system ("cls");
	}
}

int mostra_aluno (char coringa []) {

	int i, contaeng = 0;
	// Contar cursos
	for (i = 0; i < MAX; i++) {
		if (strcmp(aluno[i].curso, coringa) == 0) { 		// Quando ele compara 2 strings pela strcmp e devolve o valor 0, significa que
			contaeng++;									// n�o h� diferen�a entre as 2 strings. Quando comparar 2 strings que s�o vari�veis,
		}												// se ele devolver valor negativo, significa que a 1� string � menor que a 2� e
	}													// e quando retornar valor positivo, significa que a 1� � maior que a 2�.

	return contaeng;
	system("cls");
}

void cadastra_docente () {

	int i;
	// Entrada de dados do docente
	for (i = 0; i < MAX; i++) {
		printf("Informe o cpf do professor: \n");
		scanf("%d", &docente[i].pessoadoc.cpf);

		printf("Informe o nome do professor: \n");
		fflush(stdin);
		gets(docente[i].pessoadoc.nome);

		printf("Informe a data de nascimento do professor: \n");
		fflush(stdin);
		gets(docente[i].pessoadoc.datanasc);

		printf("Informe a carga horaria do professor: \n");
		scanf("%i", &docente[i].carga_horaria);

		system ("cls");
	}
}
		
void mostra_docente (int carga_horaria_informada) {

	int i;
	
	printf("Docente(s) com carga horaria maior ou igual a %d: \n", carga_horaria_informada);
	for (i = 0; i < MAX; i++) {
		if (docente[i].carga_horaria >= carga_horaria_informada) {
			printf("Docente: %s\n", docente[i].pessoadoc.nome);
		}
	}
	system ("pause");
}
