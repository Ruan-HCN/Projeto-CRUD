#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>


typedef struct {
	char nome[50];
	int idade;
	char cpf[11];
	char matricula[15];
	char email[50];
	char cargo[25];
	char departamento[5];
	float salario;
}Funcionario;

#define max 20

Funcionario cadastro[max];
int contador = 0;	


void Criar_Funcionario(){
	
	if(contador < max){
		
		getchar();
	
		printf("Digite seu Nome: ");
    		fgets(Funcionario[contador].nome, 50, stdin);
    		Funcionario[contador].nome[strcspn(Funcionario[contador].nome, "\n")] = '\0'; 

    		printf("Digite sua Idade: ");
    		scanf("%d", &Funcionario[contador].idade);
    		getchar();
    	
	    	printf("Digite seu CPF: ");
	    	fgets(Funcionario[contador].cpf, 11, stdin);
	    	Funcionario[contador].cpf[strcspn(Funcionario[contador].cpf, "\n")] = '\0';
	    	
	    	printf("Digite sua Matrícula: ");
	    	fgets(Funcionario[contador].matricula, 15, stdin);
	    	Funcionario[contador].matricula[strcspn(Funcionario[contador].matricula, "\n")] = '\0';
	    
	    	printf("Digite seu E-mail: ");
	    	fgets(Funcionario[contador].email, 50, stdin);
	    	Funcionario[contador].email[strcspn(Funcionario[contador].email, "\n")] = '\0';
	    
	    	printf("Digite seu Cargo: ");
	    	fgets(Funcionario[contador].cargo, 25, stdin);
	    	Funcionario[contador].cargo[strcspn(Funcionario[contador].cargo, "\n")] = '\0';
	    
	    	printf("Digite seu Departamento: ");
	    	fgets(Funcionario[contador].departamento, 5, stdin);
	    	Funcionario[contador].departamento[strcspn(Funcionario[contador].departamento, "\n")] = '\0';
	    	
	    	printf("Digite seu Salário: ");
	    	scanf("%f", &Funcionario[contador].salario);
	    	getchar();
			contador++;    
	
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
		
		else{
			printf("Limte de Cadastros atingido! Não há como adicionar novos Funcionários!\n\n");
		}
}

/* Outras Funções*/

void sair(){
	printf("Saiu!\n");
}


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int continuar = 1;
	
	do{
	   	printf("====== Escolha uma das opções abaixo: ======\n\n");
	   	printf("1. Criar Funcionário\n");
	   	printf("2. Ler Todos os Funcionários\n");
	   	printf("3. Atualizar Funcionário\n");
	   	printf("4. Deletar Funcionário\n");
	   	printf("5. Buscar Funcionário por Nome\n");
	   	printf("6. Buscar Funcionário por CPF\n");
	   	printf("0. Sair\n\n");
	   	printf("Escolha: "); 
		scanf("%d", &continuar);
	   	printf("=============================================================\n");
        system("cls || clear");
        
        switch(continuar){
			case 1:
				Criar_Funcionario();
				break;
			
			case 2:
				Ler_Funcionario();
				break;
			
			case 3:
				Atualizar_Funcionario();
				break;
			
			case 4:
				Deletar_Funcionario();
				break;
			
			case 5:
				Buscar_Nome();
				break;
			
			case 6:
				Buscar_CPF();
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
