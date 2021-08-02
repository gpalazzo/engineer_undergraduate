/*Exemplo de ordena��o bubble sort. Ordenar os valor de 
um vetor de 10 posi��es */

//declara��o das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declara��o das vari�veis
int vetor[10], i, j, opcao;

//prot�tipo das fun��es
void inserir();
void ordenar();
void mostrar();
void menu();

//declara��o da fun��o principal
main()
{
	menu();
}

void menu()
{
	system("cls");
	printf("1 - Inserir dados no vetor");
	printf("\n2 - Ordenar dados do vetor");
	printf("\n3 - Mostrar dados do vetor");
	printf("\n0 - Sair");
	scanf("%i", &opcao);
	switch(opcao)
	{
		case 1 : inserir();
		        menu();
		case 2 : ordenar();
		        menu();
		case 3 : mostrar();
		        menu();
		case 0 : exit(0);
		default:
			{
				printf("\nOpcao invalida");
				system("pause");
				menu();
			}
	}
}

//fun��o inserir()
void inserir()
{
	//estrutura de repeti��o para entrada de dados
	for(i=0; i<10; i++)
	{
		system("cls");
		printf("Informe um numero inteiro: ");
		scanf("%i", &vetor[i]);
	}
}

//fun��o ordenar()
void ordenar()
{
	int aux;
	//estruturas de repeti��es para ordena��o
	for(i=0; i<10; i++)
	{
		for(j=i+1; j<10; j++)
		{
			if(vetor[i]>vetor[j])
			{
				aux=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=aux;
			}	
		}			
	}
}

//fun��o mostrar()
void mostrar()
{
	for(i=0; i<10; i++)
	{
		printf("%i ", vetor[i]);
	}
	system("pause");
}

