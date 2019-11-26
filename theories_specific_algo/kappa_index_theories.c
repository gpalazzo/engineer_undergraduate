//Exercício Teste Kappa
//declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
//declaração das variáveis globais
int i;
float observada, esperada, kappa;

//função para calcular a concordância observada
float cobservada(int valor1, int valor2)
{
	float total=6, resultado;
	resultado = (valor1+valor2)/total;
	return resultado;
}

//função para calcular a concordância esperada
float cesperada(int total1,int total2)
{
	float total=36, resultado;
	resultado = (total1+total2)/total;
	return resultado;
}

//função para calcular a concordância de kappa
float ckappa(float obs, float esp)
{
    float resultado;
	if (obs == 1)
	    resultado = 1;
	else
	    resultado = (obs-esp)/(1-esp);
	return resultado;ns
}

//declaração da função principal
main()
{
	//declaração das variáveis locais
	int SS=0, SN=0, NS=0, NN=0;
	int A1, A2, B1, B2;
	char juiz1, juiz2;
	
	//estrutura de repetição para entrada de dados
	for(i=1;i<=6;i++)
	{
		printf("\nInforme resposta Juiz1");
		juiz1=getche();
		juiz1=toupper(juiz1);
		printf("\nInforme resposta Juiz2");
		juiz2=getche();
		juiz2=toupper(juiz2);
		
		if(juiz1=='S' && juiz2=='S')
		    SS++;
		else if(juiz1=='S' && juiz2=='N')
		    SN++;
		else if(juiz1=='N' && juiz2=='S')
		    NS++;
		else if(juiz1=='N' && juiz2=='N')
		    NN++;
		else
		{
			printf("resposta incorreta");
			i--;
		}
	}
	A1 = SS+NS;
	A2 = SN+NN;
	B1 = SS+SN;
	B2 = NS+NN;
	observada = cobservada(SS,NN);
	printf("\nconcordancia observada = %.2f", observada);
	esperada = cesperada(A1*B1,A2*B2);
	printf("\nconcordancia esperada = %.2f", esperada);
	kappa=ckappa(observada,esperada);
	printf("\nconcordancia de kappa = %.2f", kappa);		
}
