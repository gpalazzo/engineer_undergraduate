// Elaborar um algoritmo na linguagem C que seja capaz de dar a classificação olímpica de 3 países informados. 
// Para cada país é informado o nome, a quantidade de medalhas de ouro, prata e bronze. Considere que cada medalha de ouro tem peso 3, 
// cada prata tem peso 2 e cada bronze, peso 1.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info_paises {

	char nome[30];
	int ouro;
	int prata;
	int bronze;
	int resultado;
};

struct info_paises infos[3];

main (){

	int i, aux = 0, j, r, k;

	for (i = 0; i < 3; i++){

		printf("Informe o nome do pais: \n");
		fflush(stdin);
		gets(infos[i].nome);

		printf("Informe a quantidade de medalhas de ouro: \n");
		scanf("%d", &infos[i].ouro);

		printf("Informe a quantidade de medalhas de prata: \n");
		scanf("%d", &infos[i].prata);

		printf("Informe a quantidade de medalhas de bronze: \n");
		scanf("%d", &infos[i].bronze);

		infos[i].resultado = infos[i].ouro*3 + infos[i].prata*2 + infos[i].bronze;
	}
	
	
	for (k = 0; k < 3; k++) {
		for (j = 0; j < 3; j++) {
	
			if (infos[j].resultado < infos[j+1].resultado) {
	
				aux = infos[j].resultado;
				infos[j].resultado = infos[j+1].resultado;
				infos[j+1].resultado = aux;
			}
		}

	}
	
	for (r = 0; r < 3; r++) {
		printf("%s ficou em %d com %d pontos.\n", infos[2-r].nome, r+1, infos[r].resultado);
	}
}