/* Exercício 2 - Prova Parcial */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

struct aluno {

	int codigo;
	char nome [30];
	float notap, notaf, media;
};

struct aluno classe[10];

char resp;
int i = 0;

main () {

	do {

		system("cls");

		printf("Informe o codigo: \n");
		scanf("%d", &classe[i].codigo);
		fflush (stdin);
		printf("Informe o nome: \n");
		gets(classe[i].nome);
		printf("Informe a nota parcial: \n");
		scanf("%f", &classe[i].notap);
		printf("Informe a nota final: \n");
		scanf("%f", &classe[i].notaf);
		classe[i].media = classe[i].notap*0.4 + classe[i].notaf*0.6;

		i++;

		printf("Deseja cadastrar outro aluno? <s/n>\n");
		resp = getche();
		resp = toupper(resp); //esse toupper é uma funcionalidade da biblioteca ctype.h que pega a variável e coloca o caracter dela como maiúsculo.
	} while (resp == 'S' && i < 10);
}