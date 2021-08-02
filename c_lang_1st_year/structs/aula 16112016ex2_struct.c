/*Algoritmo para gerenciar uma agenda de contatos com os seguintes
dados: nome, celular e e-mail. As informações devem ser recebidas
em uma estrutura de dados e armazenadas em arquivo e devem ser
listadas em ordem alfabética. */

//declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//criação de uma estrutura de dados
struct contato
{
	char nome[40], celular[15], email[50];
};

//declaração da estrutura
struct contato agenda;

//declaração das variáveis
char continua;

//protótipo das funções
void inserir();
void listar();

//função menu()
void menu()
{
	int opcao;
	system("cls");
	printf("*** MENU ***");
	printf("\n1 - Inserir");
	printf("\n2 - Listar");
	printf("\n0 - Sair");
	printf("\nOpcao?: ");
	scanf("%i", &opcao);
	switch(opcao)
	{
		case 1 : inserir();
		         menu();
		case 2 : listar();
		         menu();
		case 0 : exit(0);
		default: 
		{
		    printf("\nOpcao Invalida!!!");
			system("pause");
			menu();				
		}		         
	}
}

//função inserir
void inserir()
{
	//ponteiro para o arquivo
	FILE *pontarq;
	
	//abertura do arquivo para gravação em modo texto
	pontarq=fopen("bd16112016.txt", "a");
	
	//estrutura de repetição para entrada de dados
	do
	{
		system("cls");
		//limpar as variáveis
		strcpy(agenda.nome,"                            ");
		strcpy(agenda.celular,"              ");
		strcpy(agenda.email,"                           ");		
		printf("Informe o nome do contato:");
		fflush(stdin);
		gets(agenda.nome);
		printf("\nInforme o celular do contato:");
		fflush(stdin);
		gets(agenda.celular);
		printf("\nInforme o e-mail do contato:");
		fflush(stdin);
		gets(agenda.email);
		
		//gravar as informações no arquivo
		fwrite(&agenda,sizeof(agenda),1,pontarq); 
		printf("Outro contato <S/N>?:");
		continua=getche();
	} while((toupper(continua))=='S');
	//fechar o arquivo
	fclose(pontarq);
}

//função contar registros
int contar()
{
	//ponteiro para o arquivo
	FILE *ponteiro;
	
	//declaração das variáveis
	int numreg=0;
	
	//abertura do arquivo para leitura
	if((ponteiro=fopen("bd16112016.txt","r"))==NULL)
	{
		printf("Erro ao abrir o arquivo");
		exit(0);
	}
	
	while((fread(&agenda,sizeof(agenda),1,ponteiro))==1)
	    numreg++;
	fclose(ponteiro);
	return numreg;    
}

//função listar
void listar()
{
	//declaração das variáveis
	int registro,i=0,j;
	registro = contar();
	
	//declaração da estrutura de dados para ordenação
	struct contato agendaordena[registro];
	struct contato auxiliar;
	
	//ponteiro para o arquivo
	FILE *ponteiro;
	
	//abertura do arquivo em modo texto para leitura
	if((ponteiro=fopen("bd16112016.txt","r"))==NULL)
	{
		printf("\nErro ao abrir o arquivo");
		exit(0);
	}
	
	while((fread(&agenda,sizeof(agenda),1,ponteiro))==1)
	{
		strcpy(agendaordena[i].nome,agenda.nome);
		strcpy(agendaordena[i].celular,agenda.celular);
		strcpy(agendaordena[i].email,agenda.email);
		i++;
	}
	
	//ordenar as informações
	for(i=0;i<registro;i++)
	{
		for(j=i+1; j<registro;j++)
		{
			if((strcmp(agendaordena[i].nome,agendaordena[j].nome)>0))
			{
				//colocar na variável temporária
				strcpy(auxiliar.nome,agendaordena[i].nome);
				strcpy(auxiliar.celular,agendaordena[i].celular);
				strcpy(auxiliar.email,agendaordena[i].email);
				
				//inverter de posição
				strcpy(agendaordena[i].nome,agendaordena[j].nome);
				strcpy(agendaordena[i].celular,agendaordena[j].celular);
				strcpy(agendaordena[i].email,agendaordena[j].email);
				
				strcpy(agendaordena[j].nome,auxiliar.nome);
				strcpy(agendaordena[j].celular,auxiliar.celular);
				strcpy(agendaordena[j].email,auxiliar.email);
				
			}
		}
	}
	
	
	//mostrar o que está na estrutura
	for(i=0; i<registro;i++)
	{
		printf("\nNome: %s" , agendaordena[i].nome);
		printf("\nCelular: %s" , agendaordena[i].celular);
		printf("\nE-mail: %s" , agendaordena[i].email);
	}
	//printf("Ha %i registros", registro);
	system("pause");
	
	//fechar o arquivo
	fclose(ponteiro);
}




//declaração da função principal
main()
{
	menu();
}





 
