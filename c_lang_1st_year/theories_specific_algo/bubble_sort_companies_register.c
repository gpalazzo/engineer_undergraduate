/* Uma agência de publicidade quer prestar serviços somente para as maiores companhias – em número de funcionários – em cada 
uma das classificações: grande (G), média (M), pequena (P) e microempresa (E). Para tal, consegue um conjunto de dados com o código, 
o número de funcionários e o porte da empresa. Elabore um algoritmo na linguagem C que liste o código da empresa com maiores recursos 
humanos dentro de sua categoria. Utilize como finalizador o código de empresa igual a 0. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int i = 0, j = 0, m = 0, k = 0;

struct infos_gerais {
	int codigo;
	int num_funcionarios;
};

struct infos_gerais grande_porte[50];
struct infos_gerais medio_porte[50];
struct infos_gerais pequeno_porte[50];
struct infos_gerais micro_porte[50];

void bubble_sort (){
	
	int bubble, auxiliar, repetidor;

	for (int repetidor = 0; repetidor < 50; repetidor++){

		for (int bubble = 0; bubble < 50; bubble++){
			if (grande_porte[bubble].num_funcionarios < grande_porte[bubble+1].num_funcionarios){

				grande_porte[bubble].num_funcionarios = auxiliar;
				grande_porte[bubble].num_funcionarios = grande_porte[bubble+1].num_funcionarios;
				grande_porte[bubble+1].num_funcionarios = auxiliar;

				grande_porte[bubble].codigo = auxiliar;
				grande_porte[bubble].codigo = grande_porte[bubble+1].codigo;
				grande_porte[bubble+1].codigo = auxiliar;
			}
		}
	}

	for (int repetidor = 0; repetidor < 50; repetidor++){

		for (int bubble = 0; bubble < 50; bubble++){
			if (medio_porte[bubble].num_funcionarios < medio_porte[bubble+1].num_funcionarios){

				medio_porte[bubble].num_funcionarios = auxiliar;
				medio_porte[bubble].num_funcionarios = medio_porte[bubble+1].num_funcionarios;
				medio_porte[bubble+1].num_funcionarios = auxiliar;

				medio_porte[bubble].codigo = auxiliar;
				medio_porte[bubble].codigo = medio_porte[bubble+1].codigo;
				medio_porte[bubble+1].codigo = auxiliar;
			}
		}
	}

	for (int repetidor = 0; repetidor < 50; repetidor++){

		for (int bubble = 0; bubble < 50; bubble++){
			if (pequeno_porte[bubble].num_funcionarios < pequeno_porte[bubble+1].num_funcionarios){

				pequeno_porte[bubble].num_funcionarios = auxiliar;
				pequeno_porte[bubble].num_funcionarios = pequeno_porte[bubble+1].num_funcionarios;
				pequeno_porte[bubble+1].num_funcionarios = auxiliar;

				pequeno_porte[bubble].codigo = auxiliar;
				pequeno_porte[bubble].codigo = pequeno_porte[bubble+1].codigo;
				pequeno_porte[bubble+1].codigo = auxiliar;
			}
		}
	}

	for (int repetidor = 0; repetidor < 50; repetidor++){

		for (int bubble = 0; bubble < 50; bubble++){
			if (micro_porte[bubble].num_funcionarios < micro_porte[bubble+1].num_funcionarios){

				micro_porte[bubble].num_funcionarios = auxiliar;
				micro_porte[bubble].num_funcionarios = micro_porte[bubble+1].num_funcionarios;
				micro_porte[bubble+1].num_funcionarios = auxiliar;

				micro_porte[bubble].codigo = auxiliar;
				micro_porte[bubble].codigo = micro_porte[bubble+1].codigo;
				micro_porte[bubble+1].codigo = auxiliar;
			}
		}
	}
	
	printf("\nA maior empresa de Grande Porte possui o codigo: %d.\n", grande_porte[0].codigo);
	printf("A maior empresa de Medio Porte possui o codigo: %d.\n", medio_porte[0].codigo);
	printf("A maior empresa de Pequeno Porte possui o codigo: %d.\n", pequeno_porte[0].codigo);
	printf("A maior empresa de Micro Porte possui o codigo: %d.\n", micro_porte[0].codigo);
}

void menu (){
	int opcao;

	system ("cls");

	printf("*** MENU ***\n");
	printf("\n1 - Grande\n");
	printf("2 - Media\n");
	printf("3 - Pequena\n");
	printf("4 - Micro\n");
	printf("0 - Sair\n");

	printf("\nQual porte de empresa voce deseja cadastrar?");
	scanf("%d", &opcao);

	switch (opcao){

		case 1: {
			// i += 1;
			printf("Voce escolheu cadastrar empresa de grande porte.\n");
			system ("pause");
			printf("Informe o codigo da empresa: \n");
			scanf("%d", &grande_porte[i].codigo);
			printf("Informe o numero de funcionario da empresa: \n");
			scanf("%d", &grande_porte[i].num_funcionarios);
			i += 1;
			menu ();
		}

		case 2: {
			// j += 1;
			printf("Voce escolheu cadastrar empresa de medio porte.\n");
			system ("pause");
			printf("Informe o codigo da empresa: \n");
			scanf("%d", &medio_porte[j].codigo);
			printf("Informe o numero de funcionario da empresa: \n");
			scanf("%d", &medio_porte[j].num_funcionarios);
			j += 1;
			menu ();
		}

		case 3: {
			// k += 1;
			printf("Voce escolheu cadastrar empresa de pequeno porte.\n");
			system ("pause");
			printf("Informe o codigo da empresa: \n");
			scanf("%d", &pequeno_porte[k].codigo);
			printf("Informe o numero de funcionario da empresa: \n");
			scanf("%d", &pequeno_porte[k].num_funcionarios);
			k += 1;
			menu ();
		}

		case 4: {
			// m += 1;
			printf("Voce escolheu cadastrar empresa de micro porte.\n");
			system ("pause");
			printf("Informe o codigo da empresa: \n");
			scanf("%d", &micro_porte[m].codigo);
			printf("Informe o numero de funcionario da empresa: \n");
			scanf("%d", &micro_porte[m].num_funcionarios);
			m += 1;
			menu ();
		}

		case 0: {
			bubble_sort ();
			exit(0);
		}

		default: {
			printf("Opcao invalida. \n");
			system ("pause");
			menu ();
		}
	}
}

int main () {

	menu ();
}