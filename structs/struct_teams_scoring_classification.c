/* Deseja-se informatizar os resultados obtidos pelas equipe de futebol e de basquete de Ribeirão Preto.

Para cada equipe armazena-se o:
- Nome da equipe;
- Número de vitórias;
- Número de derrotas.

Para as equipes de futebol, acrescente as informações:
- Número de empates;
- Número de gols contra;
- Nome do goleador da equipe;
- Número de gols do goleador;

Para as equipes de basquete, acrescente as informações:
- Número de perdas de bola;
- Número de rebotes pegos;
- Nome do melhor realizar de arremessos de 3 pontos.

São 5 equipes de futebol e 3 equipes de basquete. */

#include <stdio.h>
#include <stdlib.h>

// Declarando a estrutura genérica

struct infogeral {
	char nome_equipe[20];
	int vitorias, derrotas;
};

struct equipeFutebol {
	struct infogeral infoFutebol;
	int empates, gols_contra, gols_pro;
	char goleador[30];
};

struct equipeBasquete {
	struct infogeral infoBasquete;
	int perdas_bola, rebotes;
	char arremessador[30];
};

struct equipeFutebol eqFut[5];
struct equipeBasquete eqBasq[3];

int i, j;

main () {

	for (i=0; i < 5; i++) {

		printf("Informe os dados da %i equipe de Futebol: \n", i+1);

		printf("Informe o nome da equipe: \n");
		fflush(stdin);
		gets (eqFut[i].infoFutebol.nome_equipe);

		printf("Informe o numero de vitorias: \n");
		scanf("%d", &eqFut[i].infoFutebol.vitorias);

		printf("Informe o numero de derrotas: \n");
		scanf("%d", &eqFut[i].infoFutebol.derrotas);

		printf("Informe o numero de empates: \n");
		scanf("%d", &eqFut[i].empates);

		printf("Informe a quantidades de gols contra: \n");
		scanf("%d", &eqFut[i].gols_contra);

		printf("Informe a quantidade de gols a favor: \n");
		scanf("%d", &eqFut[i].gols_pro);

		printf("Informe o nome do goleador da equipe: \n");
		fflush(stdin);
		gets (eqFut[i].goleador);
	}

	for (j=0; j < 3; j++) {

		printf("Informe os dados da %i equipe de Basquete: \n", j+1);

		printf("Informe o nome da equipe: \n");
		fflush(stdin);
		gets (eqBasq[j].infoBasquete.nome_equipe);

		printf("Informe o numero de derrotas: \n");
		scanf("%d", &eqBasq[j].infoBasquete.derrotas);

		printf("Informe o numero de vitorias: \n");
		scanf("%d", &eqBasq[j].infoBasquete.vitorias);

		printf("Informe o numero de rebotes: \n");
		scanf("%d", &eqBasq[j].rebotes);

		printf("Informe o numero de turnovers: \n");
		scanf("%d", &eqBasq[j].perdas_bola);

		printf("Informe o nome do melhor arremessador de 3 pontos: \n");
		fflush(stdin);
		gets (eqBasq[j].arremessador);
	}
	
}


