// Exemplo de utilização de struct e array para encontrar o aluno com a menor nota

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criando a estrutura de dados

struct aluno{

	char nome[30];
	float notap, notaf;
};

// Declarando a estrutura de dados

struct aluno aluno[5];

int i;
float media;
char alunomenor[30];

int main () {

	for (i=0; i < 5; i++) {

		printf("Informe o nome: \n");
		fflush(stdin);
		fgets (aluno[i].nome, sizeof(aluno[i].nome), stdin);

		printf("Informe sua nota parcial: \n");
		scanf("%f", &aluno[i].notap);

		printf("Informe sua nota final: \n");
		scanf("%f", &aluno[i].notaf);

		system ("cls");

	}

	for (i=0; i < 5; i++) {

		printf("Nome: %s\n", aluno[i].nome);
		printf("Nota Parcial: %.2f\n", aluno[i].notap);
		printf("Nota Final: %.2f\n", aluno[i].notaf);
		printf("\n\n");

	}

	// Encontrar o aluno que possui a menor média

	media = aluno[0].notap*0.4+aluno[0].notaf*0.6;
	strcpy = (alunomenor, aluno[0].nome); 
	/* O comando strcpy serve para salvar uma string na outra, no caso a 
	string aluno[0].nome está sendo salva na string alunomenor. */

	for (i=1; i < 5; i++) { 
	/* Nesse caso começa em 1, pois a primeira média tem que ser a média do 1º aluno, não 
	havendo necessidade de comparar ele com ele mesmo. */

		// Colocando e comparando as médias
		if ((aluno[i].notap*0.4+aluno[i].notaf*0.6) < media){
			strcpy = (alunomenor, aluno[i].nome);
			media = aluno[i].notap*0.4 + aluno[i].notaf*0.6;
		}
	}

	printf("O aluno com menor média é: %s\n", alunomenor);

}