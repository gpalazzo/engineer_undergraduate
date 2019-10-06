// O índice de melhoria da empresa (1 a 5), o grau de satisfação dos gestores (1 a 5) e o valor custo/benefício (em moeda).
// Implementar utilizando funções na linguagem C um programa que leia esses dados para um número não determinado de empresas
// (no máximo 20) e retorne o índice de melhoria mais encontrado, a média do grau de satisfação dos gestores e o menor valor
// custo/benefício.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct infos{
	int melhoria;
	int satisfacao;
	float valor;
};

struct infos infos[20];

void infos_empresa (int melhoria, int contador, int satisfacao, int somatorio, int indice1, int indice2, int indice3, 
	int indice4, int indice5, int i, int j, int r, float valor, float media, float aux, char resp){

	somatorio = 0;
	contador = 0;

	do {
		system("cls");
		printf("Informe o indice de melhoria da empresa, sendo 1 o menor valor e 5 o maior valor: \n");
		scanf("%i", &infos[contador].melhoria);

		switch (infos[contador].melhoria){
			case 1: {
				indice1++;
				break;
			}

			case 2: {
				indice2++;
				break;
			}

			case 3: {
				indice3++;
				break;
			}

			case 4: {
				indice4++;
				break;
			}

			case 5: {
				indice5++;
				break;
			}
		}
		
		printf("Informe o grau de satisfacao dos gestores da empresa, sendo 1 o menor valor e 5 o maior valor: \n");
		scanf("%i", &infos[contador].satisfacao);

		printf("Informe o custo/beneficio da empresa: \n");
		scanf("%f", &infos[contador].valor);

		printf("Deseja cadastrar outra empresa? <s/n>\n");
        resp = getche();
        printf("\n\n");
		contador++;
	} while ((resp == 's' || resp == 'S') && contador <= 3);

	if (indice1 > (indice2 && indice3 && indice4 && indice5)){
		printf("O indice mais encontrado foi o de valor 1.\n");
	}

	else if (indice2 > (indice1 && indice3 && indice4 && indice5)){
		printf("O indice mais encontrado foi o de valor 2.\n");
	}

	else if (indice3 > (indice1 && indice2 && indice4 && indice5)){
		printf("O indice mais encontrado foi o de valor 3.\n");
	}

	else if (indice4 > (indice1 && indice2 && indice3 && indice5)){
		printf("O indice mais encontrado foi o de valor 4.\n");
	}

	else if (indice5 > (indice1 && indice2 && indice3 && indice4)){
		printf("O indice mais encontrado foi o de valor 5.\n");
	}
	
	else if ((indice1 == indice2) > (indice3 && indice4 && indice5)){
		printf("Os indices de valores 1 e 2 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice1 == indice3) > (indice2 && indice4 && indice5)){
		printf("Os indices de valor 1 e 3 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice1 == indice4) > (indice2 && indice3 && indice5)){
		printf("Os indices de valor 1 e 4 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice1 == indice5) > (indice2 && indice3 && indice4)){
		printf("Os indices de valor 1 e 5 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice2 == indice3) > (indice1 && indice4 && indice5)){
		printf("Os indices de valor 2 e 3 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice2 == indice4) > (indice1 && indice3 && indice5)){
		printf("Os indices de valor 2 e 4 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice2 == indice5) > (indice1 && indice3 && indice4)){
		printf("Os indices de valor 2 e 5 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice3 == indice4) > (indice1 && indice2 && indice5)){
		printf("Os indices de valor 3 e 4 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice3 == indice5) > (indice1 && indice2 && indice4)){
		printf("Os indices de valor 3 e 5 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice4 == indice5) > (indice1 && indice2 && indice3)){
		printf("Os indices de valor 1 e 5 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice1 == indice2 == indice3) > (indice4 && indice5)){
		printf("Os indices de valor 1, 2 e 3 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice1 == indice2 == indice4) > (indice3 && indice5)){
		printf("Os indices de valor 1, 2 e 4 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice1 == indice2 == indice5) > (indice3 && indice4)){
		printf("Os indices de valor 1, 2 e 5 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice1 == indice3 == indice4) > (indice2 && indice5)){
		printf("Os indices de valor 1, 3 e 4 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice1 == indice3 == indice5) > (indice2 && indice4)){
		printf("Os indices de valor 1, 3 e 5 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice1 == indice4 == indice5) > (indice2 && indice3)){
		printf("Os indices de valor 1, 4 e 5 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice2 == indice3 == indice4) > (indice1 && indice5)){
		printf("Os indices de valor 2, 3 e 4 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice2 == indice4 == indice5) > (indice1 && indice3)){
		printf("Os indices de valor 2, 4 e 5 possuem a mesma quantidade de votos.\n");
	}
	
	else if ((indice3 == indice4 == indice5) > (indice1 && indice2)){
		printf("Os indices de valor 3, 4 e 5 possuem a mesma quantidade de votos.\n");
	}
	
	else{
		printf("Todos os indices possuem a mesma quantidade de votos.\n");
	}
	
	for (i = 0; i <= contador; i++){

		somatorio += infos[i].satisfacao;
	}

	media = somatorio/contador;

	printf("A media do grau de satisfacao dos gestores foi %.2f.\n", media);

	for (r = 0; r < contador; r++){

		for (j = 0; j < contador; j++){

			if (infos[j].valor > infos[j+1].valor){

				aux = infos[j].valor;
				infos[j].valor = infos[j+1].valor;
				infos[j+1].valor = aux;
			}
		}
	}

	printf("O menor valor de custo beneficio e: %.2f.\n", infos[0].valor);
}

main (){

	int melhoria, contador, satisfacao, indice1, indice2, indice3, indice4, indice5, i, j, somatorio, r;
	char resp;
	float valor, media, aux;

	infos_empresa (melhoria, contador, satisfacao, media, indice1, indice2, indice3, indice4,
 indice5, valor, resp, i, j, somatorio, aux, r);
}