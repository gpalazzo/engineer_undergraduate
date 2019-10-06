/*
Deseja-se informatizar os resultados obtidos pelas equipes de 
futebol e de basquete de Ribeirão Preto. 
Para cada equipe armazena-se o:
Nome da equipe;
Número de vitórias;
Número de derrotas.
 
Para as equipes de futebol, acrescente as informações:
- Número de empates;
- Número de gols contra;
- Nome do goleador da equipe;
- Número de gols do goleador.
 
Para as equipes de basquete, acrescente as informações:
- Número de perdas de bola;
- Número de rebotes pegos;
- Nome do melhor realizador de arremessos de três pontos;

Ao final, mostra-se a equipe ganhadora no basquete e o maior goleador do futebol.

São 10 equipes de futebol e 6 equipes de basquete.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_fut 10
#define max_basq 6

struct infos_gerais {
	char nome_equipe[30];
	int vitorias, derrotas;
};

struct infos_futebol {
	struct infos_gerais infos_fut;
	int empates, gols_pro, gols_contra, gols_goleador;
	char nome_goleador[30];
};

struct infos_basquete {
	struct infos_gerais infos_basq;
	int perdas_bola, rebotes, arremessos3;
	char nome_melhor_arremessador[30];
};

struct infos_futebol infos_futebol[max_fut];
struct infos_basquete infos_basquete[max_basq];

int contador_basq = 0, contador_fut = 0, auxiliar_bubblesort;
char auxiliar_nome[30];

void cadastro_equipe_basquete () {

	for (int i = 0; i < max_basq; i++) {
		
		system("cls");
		
		printf("Informe o nome da equipe: \n");
		fflush(stdin);
		gets(infos_basquete[i].infos_basq.nome_equipe);
		printf("As informacoes abaixo referem-se a equipe: %s\n", infos_basquete[i].infos_basq.nome_equipe);
		printf("\nInforme a quantidade de vitorias: \n");
		scanf("%d", &infos_basquete[i].infos_basq.vitorias);
		printf("Informe a quantidade de derrotas: \n");
		scanf("%d", &infos_basquete[i].infos_basq.derrotas);
		printf("Informe a quantidade de bolas perdidas: \n");
		scanf("%d", &infos_basquete[i].perdas_bola);
		printf("Informe a quantidade de rebotes: \n");
		scanf("%d", &infos_basquete[i].rebotes);
		printf("Informe o nome do melhor arremessador de 3 pontos: \n");
		fflush(stdin);
		gets(infos_basquete[i].nome_melhor_arremessador);
		printf("Informe a quantidade de arremessos de 3 pontos convertidos pelo %s:\n", infos_basquete[i].nome_melhor_arremessador);
		scanf("%d", &infos_basquete[i].arremessos3);
	}

	contador_basq++;
}

void cadastro_equipe_futebol () {

	for (int i = 0; i < max_fut; i++) {
		
		system("cls");
		
		printf("Informe o nome da equipe: \n");
		fflush(stdin);
		gets(infos_futebol[i].infos_fut.nome_equipe);
		printf("As informacoes abaixo referem-se a equipe: %s\n", infos_futebol[i].infos_fut.nome_equipe);
		printf("Informe a quantidade de vitorias: \n");
		scanf("%d", &infos_futebol[i].infos_fut.vitorias);
		printf("Informe a quantidade de derrotas: \n");
		scanf("%d", &infos_futebol[i].infos_fut.derrotas);
		printf("Informe a quantidade de empates: \n");
		scanf("%d", &infos_futebol[i].empates);
		printf("Informe a quantidade de gols a favor: \n");
		scanf("%d", &infos_futebol[i].gols_pro);
		printf("Informe a quantidade de gols contra: \n");
		scanf("%d", &infos_futebol[i].gols_contra);
		printf("Informe o nome do goleador da equipe: \n");
		fflush(stdin);
		gets(infos_futebol[i].nome_goleador);
		printf("Informe quantos gols o %s fez: \n", infos_futebol[i].nome_goleador);
		scanf("%d", &infos_futebol[i].gols_goleador);
	}

	contador_fut++;
}

void melhores_arremessadores (struct infos_basquete infos_basquete[max_basq]) {

	system("cls");

	printf("Os melhores arremessadores sao: \n\n");
	printf("Equipe               Nome do Jogador\n");

	for (int i = 0; i < max_basq; i++) {
		printf("%s                     %s\n", infos_basquete[i].infos_basq.nome_equipe, infos_basquete[i].nome_melhor_arremessador);
	}
	system("pause");
}

void ganhador_basquete (struct infos_basquete infos_basquete[max_basq]) {

	system("cls");

	//Bubble sort
	for (int i = 0; i < max_basq; i++) {
		for (int j = 0; j < max_basq; j++) {
			if (infos_basquete[j].infos_basq.vitorias < infos_basquete[j+1].infos_basq.vitorias) {

				strcpy (auxiliar_nome, infos_basquete[j].infos_basq.nome_equipe);
				strcpy (infos_basquete[j].infos_basq.nome_equipe, infos_basquete[j+1].infos_basq.nome_equipe);
				strcpy (infos_basquete[j+1].infos_basq.nome_equipe, auxiliar_nome);

				infos_basquete[j].infos_basq.vitorias = auxiliar_bubblesort;
				infos_basquete[j].infos_basq.vitorias = infos_basquete[j+1].infos_basq.vitorias;
				infos_basquete[j+1].infos_basq.vitorias = auxiliar_bubblesort;
			}
		}
	}

	printf("A equipe ganhadora foi a %s. \n\n", infos_basquete[0].infos_basq.nome_equipe);
	system("pause");
	printf("\n");
}

void goleador_futebol (struct infos_futebol infos_futebol[max_fut]) {

	for (int i = 0; i < max_fut; i++) {
		for (int j = 0; j < max_fut; j++) {
			if (infos_futebol[j].gols_goleador < infos_futebol[j+1].gols_goleador) {

				strcpy (auxiliar_nome, infos_futebol[j].nome_goleador);
				strcpy (infos_futebol[j].nome_goleador, infos_futebol[j+1].nome_goleador);
				strcpy (infos_futebol[j+1].nome_goleador, auxiliar_nome);

				infos_futebol[j].gols_goleador = auxiliar_bubblesort;
				infos_futebol[j].gols_goleador = infos_futebol[j+1].gols_goleador;
				infos_futebol[j+1].gols_goleador = auxiliar_bubblesort;
			}
		}
	}

	printf("O maior goleador da liga de futebol foi o jogador: %s\n\n", infos_futebol[0].nome_goleador);
	system("pause");
	printf("\n");
}

void menu () {

	int opcao;

	printf("******     ******\n");
	printf("Bem-Vindo ao Menu\n");
	printf("******     ******\n\n");

	printf("Informe qual opcao voce deseja: \n\n");

	printf("1 - Cadastrar equipes de basquete\n");
	printf("2 - Cadastrar equipes de futebol\n");
	printf("3 - Listagem dos melhores arremessadores de 3 pontos\n");
	printf("4 - Mostrar maior goleador da liga de futebol\n");
	printf("5 - Mostrar a equipe ganhadora da liga de basquete\n");
	printf("0 - Sair do menu\n");

	scanf("%d", &opcao);

	switch (opcao) {
		case 1: {

			if (contador_basq == 0) {
				cadastro_equipe_basquete ();
				menu ();	
			}

			else {
				printf("Voce ja cadastrou as equipes de basquete. Favor escolher outra opcao.\n\n");
				menu ();
			}
		}

		case 2: {

			if (contador_fut == 0) {
				cadastro_equipe_futebol ();
				menu ();
			}

			else {
				printf("Voce ja cadastrou as equipes de futebol. Favor escolher outra opcao.\n\n");
				menu ();
			}
		}

		case 3: {

			if (contador_basq == 0) {
				printf("Voce precisa primeiro cadastrar as equipes de basquete.\n\n");
				menu ();
			}

			else {
				melhores_arremessadores (infos_basquete);
				menu ();
			}
		}

		case 4: {

			if (contador_fut == 0) {
				printf("Voce precisa primeiro cadastrar as equipes de futebol.\n\n");
				menu ();
			}

			else {
				goleador_futebol (infos_futebol);
				menu ();
			}
		}

		case 5: {

			if (contador_basq == 0) {
				printf("Voce precisa primeiro cadastrar as equipes de basquete.\n\n");
				menu ();
			}

			else {
				ganhador_basquete (infos_basquete);
				menu ();
			}
		}

		case 0: exit(0);
	}
}

main () {

	menu ();
}