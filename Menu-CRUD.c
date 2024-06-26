#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>


struct registro{
	char nome[50];
	int idade;
	char email[50];
	char cargo[25];
	char departamento[5];
};
	

void registrar(){
	struct registro dados;
	
	getchar();
	
	printf("Digite seu Nome: ");
    fgets(dados.nome, 50, stdin);
    dados.nome[strcspn(dados.nome, "\n")] = '\0'; 

    printf("Digite sua Idade: ");
    scanf("%d", &dados.idade);
    getchar();
    
    printf("Digite seu E-mail: ");
    fgets(dados.email, 50, stdin);
    dados.email[strcspn(dados.email, "\n")] = '\0';
    
    printf("Digite seu Cargo: ");
    fgets(dados.cargo, 25, stdin);
    dados.cargo[strcspn(dados.cargo, "\n")] = '\0';
    
    printf("Digite seu Departamento: ");
    fgets(dados.departamento, 5, stdin);
    dados.departamento[strcspn(dados.departamento, "\n")] = '\0';
    

    printf("\n\nNome: %s", dados.nome);
    printf("\nIdade: %d", dados.idade);
    printf("\nE-mail: %s", dados.email);
    printf("\nCargo: %s", dados.cargo);
    printf("\nDepartamento: %s\n\n", dados.departamento);
    printf("Registrado!\n\n\n");
    
    int i;
    
    printf("Os dados serão limpados da tela em...\n");
    for (i = 10; i > 0; i--) {
        printf("%d\n", i);
        Sleep(1000); 
    }
    
    system("cls || clear");
}

void logar(){
	printf("Logou!\n\n");
}

void sair(){
	printf("Saiu!\n\n");
}


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int continuar = 1;
	
	do{
		printf("====================================================================\n");
	   	printf("Escolha uma das opções abaixo:\n\n");
	   	printf("1. Registrar\n");
	   	printf("2. Logar\n");
	   	printf("0. Sair\n\n");
	   	
	   	printf("Escolha: "); scanf("%d", &continuar);
        system("cls || clear");
        
        switch(continuar){
			case 1:
				registrar();
				break;
			
			case 2:
				logar();
				break;
			
			case 0:
				sair();
				break;
			
			default:
				printf("Digite uma opção valida!\n\n");
		}
		
	} while(continuar);
	
	return 0;
}