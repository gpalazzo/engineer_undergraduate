/* Em um prédio há três elevadores denominados A, B e C. Para otimizar o sistema de controle dos elevadores foi realizado um levantamento 
no qual cada usuário respondia:
¥	o elevador que utilizava com mais frequência;
¥	o período em que utiliza o elevador, entre: M – matutino, V – vespertino e N – noturno
Elabore um algoritmo utilizando a linguagem C que calcule e imprima:
¥	qual é o elevador mais frequentado e em que período se concentra o maior fluxo;
¥	qual o período mais usado de todos e a que elevador pertence;
¥	qual a diferença percentual entre o mais usado dos horários e o menos usado. */

#include <stdio.h>
#include <stdlib.h>

int elevador, A, B, C, m, v, n;
char periodo, resp1, resp2;

void menu_elevador () {

	do {
	
		system("cls");
	
		printf("**** MENU ****\n");
		printf("1 - Elevador A\n");
		printf("2 - Elevador B\n");
		printf("3 - Elevador C\n");
		printf("**************\n");
	
		printf("Informe qual elevador você utiliza com mais frequencia: \n");
		scanf("%d", &elevador);
	
		switch (elevador) {
	
			case 1: {
				A++;
				break;
			}
	
			case 2: {
				B++;
				break;
			}
	
			case 3: {
				C++;
				break;
			}
			
			default: {
				printf("Opcao invalida.\n");
				system("pause");
			}
		}
		
		printf("Deseja cadastrar outra resposta?\n");
		scanf(" %c", &resp1);
	} while (resp1 == 's' || resp1 == 'S');
}

void menu_periodo () {
	
	system ("cls");

	do {
		printf("Informe o periodo do dia em que mais utiliza o elevador: \n");
		printf("M - Matutino\n");
		printf("V - Vespertino\n");
		printf("N - Noturno\n");
		scanf(" %c", &periodo);

		if (periodo == 'M') {
			m++;
		}

		else if (periodo == 'V') {
			v++;
		}

		else if (periodo == 'N') {
			n++;
		}

		else {
			printf("Opcao invalida.\n");
		}
		
		printf("Deseja cadastrar outra resposta?\n");
		scanf(" %c", &resp2);
	} while (resp2 == 's' || resp2 == 'S');
}

main () {

	menu_elevador ();

	menu_periodo ();

	if (A > (B && C)) {
		printf("O elevador mais utilizado e o A.\n");
	}

	else if (B > (A && C)) {
		printf("O elevador mais utilizado e o B.\n");
	}

	else {
		printf("O elevador mais utilizado e o C.\n");
	}

	if (m > (v && n)) {
		printf("O periodo mais utilizado e o Matutino.\n");
	}

	else if (v > (m && n)) {
		printf("O periodo mais utilizado e o Vespertino.\n");
	}

	else {
		printf("O periodo mais utilizado e o Noturno.\n");
	}
}