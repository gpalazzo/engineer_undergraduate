#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

FILE *cadastro_login;

char nome[30], nome_usuario[30];
int senha;

void Cadastro () {

	char resposta;

	cadastro_login = fopen ("Login.txt", "a");

	do {

		printf("Informe seu nome: \n");
		scanf("%s", nome);
		printf("Informe um login para cadastro: \n");
		scanf("%s", nome_usuario);
		printf("Informe uma senha para cadastro: \n");
		scanf("%d", &senha);

		fprintf(cadastro_login, "%s %d\n", nome_usuario, senha);

		printf("Deseja cadastrar outro usuario? <s/n>\n");
		scanf(" %c", &resposta);

	} while (toupper(resposta) == 'S');

	fclose (cadastro_login);
}

void Login () {

	char nome_usuario_informado[30];
	int senha_informada, contador = 0, achou = 0;

	cadastro_login = fopen ("Login.txt", "r");

	printf("Informe seu nome de usuario: \n");
	scanf("%s", nome_usuario_informado);

	printf("Informe sua senha: \n");
	scanf("%d", &senha_informada);

	while ((fscanf(cadastro_login, "%s %d", nome_usuario, &senha)) != EOF && !achou) {

		if ((strcmp(nome_usuario_informado, nome_usuario) == 0) && (senha == senha_informada)) {
			printf("Login efetuado com sucesso.\n");
			achou = 1;
			
		}

		else {
			contador++;
			
			// Colocar loop de leitura do contador no arquivo!
		}
	}
	
	fclose (cadastro_login);
}

void Menu () {

	int escolha;

	printf("1 - Cadastrar Usuario\n");
	printf("2 - Logar no Sistema\n");
	printf("3 - Sair\n");
	
	printf("Qual opcao voce deseja?");
	scanf("%d", &escolha);
	
	switch (escolha) {
	
		case 1: {
			Cadastro ();
			Menu ();
		}

		case 2: {
			Login ();
			Menu ();
		}

		case 3: exit(0);
	}
}

int main () {

	Menu ();
}
