/* Algoritmos de indexação e ordenação

--> Bubble Sort

for (i = 0; i < 4; i++) {

	for (j = i+1; j < 4; j++) {

		if (vetor[i] > vetor[j]) {

			auxiliar = vetor[j];
			vetor[i] = vetor[j];
			vetor[j] = auxiliar;
		}
	}
}


// Ordenação na leitura de arquivos

Algoritmo para gerenciar uma agenda de contatos com os seguintes dados: nome, celular e e-mail. As informações devem ser recebidas em uma
estrutura de dados e armazenadas em arquivo e devem ser listadas em ordem alfabética.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

FILE *ponteiro;

struct contato {

	char nome[40], celular[15], email[50];
};

struct contato agenda;

// Protótipo das funções
void inserir ();
void listar ();
int contar ();

char continua;

void menu () {

	int opcao;

	system("cls");
	printf("*** MENU ***\n");
	printf("1 - Inserir\n");
	printf("2 - Listar\n");
	printf("0 - Sair\n");

	printf("Opcao: \n");
	scanf("%d", &opcao);

	switch (opcao) {

		case 1: {
			inserir ();
			menu ();
		}

		case 2: {
			listar ();
			menu ();
		}

		case 0: exit(0);

		default: {

			printf("Opcao invalida.\n");
			system("pause");
			menu ();
		}
	}
}

void inserir () {

	ponteiro = fopen ("BancoDados_Agenda.txt", "a");

	do {

		system ("cls");

		// Reservar espaço no bloco de notas para as variáveis, de acordo com seus respectivos tamanhos (preenche-se com espaços)
		strcpy (agenda.nome, "                                        ");
		strcpy (agenda.celular, "               ");
		strcpy (agenda.email, "                                                  ");

		printf("Informe o nome do contato: \n");
		fflush(stdin);
		gets(agenda.nome);
		printf("Informe o celular do contato: \n");
		fflush(stdin);
		gets(agenda.celular);
		printf("Informe o e-mail do contato: \n");
		fflush(stdin);
		gets(agenda.email);

		// Gravando as informações no arquivo

		fwrite (&agenda, sizeof(agenda), 1, ponteiro); // Comando para escrever

		printf("Outro contato? <s/n>\n");
		continua = getche();

	} while (toupper(continua) == 'S');

	fclose (ponteiro);
}

int contar () {

	int numreg = 0;

	if ((ponteiro = fopen ("BancoDados_Agenda.txt", "r")) == NULL) {

		printf("Erro ao abrir o arquivo.\n");
		exit (0);
	}

	while ((fread(&agenda, sizeof(agenda), 1, ponteiro)) == 1) {

		numreg++;
	}

	fclose (ponteiro);
	return numreg;
}

void listar () {

	int registro, i = 0, j = 0;

	registro = contar ();

	struct contato agendaordena[registro];
	struct contato auxiliar;

	if ((ponteiro = fopen ("BancoDados_Agenda.txt", "r")) == NULL) {

		printf("Erro ao abrir o arquivo.\n");
		exit (0);
	}

	while ((fread(&agenda, sizeof(agenda), 1, ponteiro)) == 1) {

		strcpy (agendaordena[i].nome, agenda.nome);
		strcpy (agendaordena[i].celular, agenda.celular);
		strcpy (agendaordena[i].email, agenda.email);

		i++;
	}

	for (i = 0; i < registro; i++) {

		for (j = i+1; j < registro; j++) {

			if (strcmp(agendaordena[i].nome, agendaordena[j].nome) > 0) {
				/* No comando strcmp, quando as strings são comparadas, é retornado um valor que pode ser 1, 0 ou -1. Se ele retornar
				1, significa que a 1ª string é maior que a 2ª. Se retornar 0, significa que elas são iguais e se retornar -1,
				significa que a 2ª é maior que a 1ª */

				// Bubble sort com todas as estruturas da struct

				strcpy (auxiliar.nome, agendaordena[i].nome);
				strcpy (auxiliar.celular, agendaordena[i].celular);
				strcpy (auxiliar.email, agendaordena[i].email);

				strcpy (agendaordena[i].nome, agendaordena[j].nome);
				strcpy (agendaordena[i].celular, agendaordena[j].celular);
				strcpy (agendaordena[i].email, agendaordena[j].email);

				strcpy (agendaordena[j].nome, auxiliar.nome);
				strcpy (agendaordena[j].celular, auxiliar.celular);
				strcpy (agendaordena[j].email, auxiliar.email);
			}
		}
	}

	// Mostrar o que está na estrutura
	for (i = 0; i < registro; i++) {

		printf("\nNome: %s", agendaordena[i].nome);
		printf("\nCelular: %s", agendaordena[i].celular);
		printf("\nE-mail: %s", agendaordena[i].email);
	}

	system("pause");
}

main () {
	
	menu ();
}
