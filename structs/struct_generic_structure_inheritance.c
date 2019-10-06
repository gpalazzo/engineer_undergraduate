/*
Exerc�cio para armazenar dados de pessoa f�sica e jur�dica.
O mais interessante aqui � a ideia de utilizar-se de uma struct gen�rica e depois "herdar" os atributos dela para outra struct.
*/

#include <stdio.h>
#include <stdlib.h>

// Cria��o da estrutura gen�rica
struct pessoa{
    int codigo;
    char nome[40];
    char telefone[11];
};

// Cria��o da estrutura espec�fica de pessoa f�sica
struct pessoa_fisica{
    
    // Declara��o da estrutura pessoa gen�rica
    struct pessoa pessoaf;
    char rg[13];
    char cpf[15];
};

// Cria��o da estrutura espec�fica de pessoa jur�dica
struct pessoa_juridica{
    
    // Declara��o da estrutura pessoa gen�rica
    struct pessoa pessoaj;
    char cnpj[19];
    char ie[19];
};

// Declara��o das estruturas espec�ficas
struct pessoa_juridica pjuridica;
struct pessoa_fisica pfisica;

// Declara��o das var�aveis
char resp;
int tipo;

main (){
    
    // Estrutura de repeti��o para gerenciar o cadastro
    do{
    	system("cls");
        printf("Informe o tipo da pessoa: \n(1) - F�sica\n(2) - Jur�dica\n\n");
        scanf("%d", &tipo);
        
        switch (tipo){
            case 1:{
            
                printf("Informe o c�digo: \n");
                scanf("%d", &pfisica.pessoaf.codigo);
            
                printf("Informe o nome: \n");
            	fflush(stdin);
                gets (pfisica.pessoaf.nome);
            	
   	        	printf("Informe o telefone: \n");
            	fflush(stdin);
            	gets (pfisica.pessoaf.telefone);
            
                printf("Informe o RG: \n");
                fflush(stdin);
                gets (pfisica.rg);
            
                printf("Informe o CPF: \n");
                fflush(stdin);
                gets (pfisica.cpf);
            
                break;
				}
        
            case 2:{
                printf("Informe o c�digo: \n");
                scanf("%d", &pjuridica.pessoaj.codigo);
                
                printf("Informe o nome: \n");
                fflush(stdin);
                gets (pjuridica.pessoaj.nome);
                    
                printf("Informe o telefone: \n");
                fflush(stdin);
                gets (pjuridica.pessoaj.telefone);
                    
                printf("Informe o CNPJ: \n");
                fflush(stdin);
                gets (pjuridica.cnpj);
                    
                printf("Informe a IE: \n");
                fflush(stdin);
                gets (pjuridica.ie);
                    
                break;
                }
                
                default: printf("Op��o inv�lida. \n");
		}
    
        printf("Deseja cadastrar outra pessoa? Responda com S ou N: \n");
        resp = getchar();
        } while (resp == 's'|| resp == 'S');
}
