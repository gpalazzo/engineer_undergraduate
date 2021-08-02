/*Exemplo do uso de estrutura de dados declarada em outra
estrutura de dados */

//declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//criação da estrutura genérica
struct pessoa
{
	int codigo;
	char nome[40];
	char telefone[11];
};

//criação da estrutura específica pessoa física
struct pessoa_fisica
{
      //declaração da estrutura pessoa
      struct pessoa pessoaf;
      char rg[13];
      char cpf[15];
};

//criação da estrutura específica pessoa jurídica
struct pessoa_juridica
{
	//declaração da estrutura pessoa
	struct pessoa pessoaj;
	char cnpj[19];
	char ie[19];
};

//declaração das estruturas específicas
struct pessoa_juridica pjuridica;
struct pessoa_fisica pfisica;

//declaração das variáveis
char resp;
int tipo;

main()
{
	//estrutura de repetição para gerenciar o cadastro
	do
	{
		//informar o tipo da pessoa
		printf("\Informe o tipo da pessoa:\n1-fisica\n2-juridica");
		scanf("%i",&tipo);
		
		//estrutura condicional
		switch(tipo)
		{
			case 1 :
				{
					printf("\nInforme o codigo: ");
					scanf("%d", &pfisica.pessoaf.codigo);
					printf("\nInforme o nome: ");
					fflush(stdin);
					gets(pfisica.pessoaf.nome);
					printf("\nInforme o telefone: ");
					fflush(stdin);
					gets(pfisica.pessoaf.telefone);
					printf("\nInforme o RG");
					fflush(stdin);
					gets(pfisica.rg);
					printf("\nInforme o CPF");
					fflush(stdin);
					gets(pfisica.cpf);
				}
			break;
			case 2 :
				{
					printf("\nInforme o codigo: ");
					scanf("%d", &pjuridica.pessoaj.codigo);
					printf("\nInforme o nome: ");
					fflush(stdin);
					gets(pjuridica.pessoaj.nome);
					printf("\nInforme o telefone: ");
					fflush(stdin);
					gets(pjuridica.pessoaj.telefone);
					printf("\nInforme o CNPJ");
					fflush(stdin);
					gets(pjuridica.cnpj);
					printf("\nInforme a IE");
					fflush(stdin);
					gets(pjuridica.ie);
				}
			break;
		default : printf("\nOpcao Invalida");
		}
	
		printf("\nInformar outro cliente <s/n>:? ");
		resp = getche();	
	} while (resp == 's' || resp == 'S');
	
}	
	






