// Programa para cadastrar e lista o nome, nota parcial e nota final dos alunos.
// Toda vez que abrir um arquivo, independente do que for fazer com ele, tem que fechar.

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char nome[30], continua, aluno_procurado[30];
float notap, notaf;
int contador1 = 0;

//Declaração do ponteiro para o arquivo
FILE *pontarq;

void menu ();

// Funções
void cadastrar () {

	pontarq = fopen ("banco1.txt", "a");
	int contador = 0;

	do {
		system("cls");
		
		printf("Informe o nome do aluno: \n");
		fflush(stdin);
		gets(nome);

		printf("Informe a nota parcial: \n");
		scanf("%f", &notap);
	
		printf("Informe a nota final: \n");
		scanf("%f", &notaf);
		
		fseek (pontarq, 0, SEEK_SET);
		fprintf(pontarq, "%s %f %f\n", nome, notap, notaf);
		
		contador++;

		printf("Outro aluno? <s/n>\n");
		continua = getche();
	
	} while (toupper(continua) == 'S');
	
	fscanf(pontarq, "%d", &contador1);
	contador1 += contador;
	fseek(pontarq, 0, SEEK_END);
	fprintf(pontarq, "%d\n", contador1);

	fclose (pontarq);
}

void listar () {

	if ((pontarq = fopen ("banco1.txt", "r")) == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		system("pause");
		menu ();
	}
	
	int contador = 0;
	fseek (pontarq, 0, SEEK_END);
	fscanf (pontarq, "%d", &contador1);
	contador = contador1;
	
	while ((fscanf(pontarq, "%s %f %f", nome, &notap, &notaf)) != EOF && (contador != 0)) {
		printf("\nNome: %s \nNota Parcial: %.2f \nNota Final: %.2f \nMedia: %.2f\n", nome, notap, notaf, notap*0.4+notaf*0.6);
		contador--;
	}
	
	system("pause");
	fclose (pontarq);
}

void aprovados () {
	
	int aprovados = 0;

	if ((pontarq = fopen ("banco1.txt", "r")) == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		system("pause");
		menu ();
	}
	
	int contador = 0;
	fseek(pontarq, 0, SEEK_END);
	fscanf(pontarq, "%d", &contador1);
	contador = contador1;

	while ((fscanf(pontarq, "%s %f %f", nome, &notap, &notaf)) != EOF) {
		if (notap*0.4+notaf*0.6 >= 5) {
			if (contador != fscanf(pontarq, "%d", &contador1)) {
				printf("\n%s", nome);
				aprovados++;
			}
		}	
	}

	if (aprovados == 0) {
		printf("Ninguem foi aprovado.\n");
	}
	
	system("pause");
	fclose (pontarq);
}

void pesquisa_aluno () {
	
	if ((pontarq = fopen ("banco1.txt", "r")) == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		system("pause");
		menu ();
	}
	
	printf("Informe o nome do aluno que deseja procurar: \n");
	fflush(stdin);
	gets(aluno_procurado);

	int contador = 0;
	fseek(pontarq, 0, SEEK_END);
	fscanf (pontarq, "%d", &contador1);
	contador = contador1;

	while ((fscanf (pontarq, "%s %f %f", nome, &notap, &notaf)) != EOF) {
		if ((strcmp (nome, aluno_procurado)) != 0) {
			contador--;

			if (contador == 0) {
				printf("Aluno nao cadastrado.\n");
			}
		}

		else {
			printf("\nNota Parcial: %.2f \nNota Final: %.2f \nMedia: %.2f\n", notap, notaf, notap*0.4+notaf*0.6);
			break;
		}
	}
	
	system("pause");
	fclose(pontarq);
}

void menu () {

	int opcao;

	system("cls");

	printf("1 - Cadastrar\n");
	printf("2 - Listar\n");
	printf("3 - Mostrar Aprovados\n");
	printf("4 - Pesquisar Aluno\n");
	printf("5 - Sair\n");

	printf("Qual opcao voce deseja? \n");
	scanf("%i", &opcao);

	switch (opcao) {

		case 1: {
			cadastrar ();
			menu ();
		}

		case 2: {
			listar ();
			menu ();
		}

		case 3: {
			aprovados ();
			menu ();
		}

		case 4: {
			pesquisa_aluno ();
			menu ();
		}

		case 5: exit (0);

		default: {
			printf("Opcao invalida.\n");
			system("pause");
		}
		
		menu ();
	}
}

int main () {
	
	menu ();
}
