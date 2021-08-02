/*
Exercício para armazenar dados de pessoa física e jurídica.
O mais interessante aqui é a ideia de utilizar-se de uma struct genérica e depois "herdar" os atributos dela para outra struct.
*/

#include <stdio.h>
#include <stdlib.h>

// Criação da estrutura genérica
struct pessoa{
    int codigo;
    char nome[40];
    char telefone[11];
};

// Criação da estrutura específica de pessoa física
struct pessoa_fisica{
    
    // Declaração da estrutura pessoa genérica
    struct pessoa pessoaf;
    char rg[13];
    char cpf[15];
};

// Criação da estrutura específica de pessoa jurídica
struct pessoa_juridica{
    
    // Declaração da estrutura pessoa genérica
    struct pessoa pessoaj;
    char cnpj[19];
    char ie[19];
};

// Declaração das estruturas específicas
struct pessoa_juridica pjuridica;
struct pessoa_fisica pfisica;

// Declaração das varíaveis
char resp;
int tipo;

main (){
    
    // Estrutura de repetição para gerenciar o cadastro
    do{
    	system("cls");
        printf("Informe o tipo da pessoa: \n(1) - Física\n(2) - Jurídica\n\n");
        scanf("%d", &tipo);
        
        switch (tipo){
            case 1:{
            
                printf("Informe o código: \n");
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
                printf("Informe o código: \n");
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
                
                default: printf("Opção inválida. \n");
		}
    
        printf("Deseja cadastrar outra pessoa? Responda com S ou N: \n");
        resp = getchar();
        } while (resp == 's'|| resp == 'S');
}
