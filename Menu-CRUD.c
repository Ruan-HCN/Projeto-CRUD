#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>


struct Funcionario
{
	char nome[50];
	int idade;
	char cpf[11];
	char matricula[15];
	char email[50];
	char cargo[25];
	char departamento[5];
	float salario;
} funcionario;
//função listar funcionário
void read_funcionario()
{
	FILE *arquivo;
	arquivo = fopen("funcionarios.txt", "rb");

	if(arquivo == NULL)
	{
		printf("algo deu errado");
	}
	else
	{
		while( fread( &funcionario, sizeof(funcionario), 1, arquivo) == 1)
		{
			printf("Nome: %s\n", funcionario.nome);
			printf("Idade: %d\n", funcionario.idade);
			printf("CPF: %s\n", funcionario.cpf);
			printf("Matrícula: %s\n", funcionario.matricula);
			printf("Email: %s\n", funcionario.email);
			printf("Cargo: %s\n", funcionario.cargo);
			printf("Departamento: %s\n", funcionario.departamento);
			printf("Salário: R$%2f\n", funcionario.salario);
			printf("---------------------\n\n");
		}
	}
	fclose(arquivo);
	getch();
}
//função criar funcionário
void create_funcionario()
{

	FILE *arquivo;
	arquivo = fopen("funcionarios.txt", "ab");

	if(arquivo == NULL)
	{
		printf("algo deu errado");
	}
	else
	{
		do
		{
			fflush(stdin);
			printf("Digite seu Nome:");
			gets(funcionario.nome);

			fflush(stdin);
			printf("\nDigite sua Idade:");
			scanf("%d", &funcionario.idade);

			fflush(stdin);
			printf("\nDigite seu CPF:");
			gets(funcionario.cpf);

			fflush(stdin);
			printf("\nDigite sua Matricula:");
			gets(funcionario.matricula);

			fflush(stdin);
			printf("\nDigite seu E-mail:");
			gets(funcionario.email);

			fflush(stdin);
			printf("\nDigite seu Cargo:");
			gets(funcionario.cargo);

			fflush(stdin);
			printf("\nDigite seu Departamento:");
			gets(funcionario.departamento);

			fflush(stdin);
			printf("\nDigite seu Salário:");
			scanf("%f", &funcionario.salario);

			fwrite(&funcionario, sizeof(funcionario), 1, arquivo);

			int i;

			printf("Os dados serão limpos da tela em...\n");
			for (i = 10; i > 0; i--)
			{
				printf("%d\n", i);
				Sleep(1000);
			}

			system("cls || clear");
			printf("deseja continuar [s/n]");
			getchar();
		}
		while(getche() == 's');
	}
	fclose(arquivo);
}
//função deletar duncionário
void delete_funcionario()
{
	FILE *originfile;
	FILE *newfile;
	char matricula[15];

	originfile = fopen("funcionarios.txt", "rb");
	newfile = fopen("newfuncionarios.txt", "ab");

	if(originfile == NULL || newfile == NULL)
	{
		printf("Algo deu errado");
	}
	else
	{
		fflush(stdin);
		printf("Digite a matricula do funcionario a ser exluido: ");
		gets(matricula);

		while( fread (&funcionario, sizeof(funcionario), 1, originfile) == 1)
		{
			if (strcmp(matricula, funcionario.matricula) != 0)
			{
				fwrite (&funcionario, sizeof(funcionario), 1, newfile);

			}
		}

	}
	fclose(originfile);
	fclose(newfile);
	remove("funcionarios.txt");
	rename("newfuncionarios.txt", "funcionarios.txt");
	printf("Funcionário removido!");
	getch();
}
//função pesquisar funcionário
void search()
{
	FILE *arquivo;
	char matricula [15];

	arquivo = fopen("funcionarios.txt", "rb");
	if(arquivo == NULL)
	{
		printf("Algo deu errado\n");
	}
	else
	{
		fflush(stdin);
		printf("Digite a matrícula do funcionário: ");
		gets(matricula);
		while( fread( &funcionario, sizeof(funcionario), 1, arquivo) == 1)
		{
			if( strcmp(matricula, funcionario.matricula ) == 0)
			{
				printf("Nome: %s\n", funcionario.nome);
				printf("Idade: %d\n", funcionario.idade);
				printf("CPF: %s\n", funcionario.cpf);
				printf("Matrícula: %s\n", funcionario.matricula);
				printf("Email: %s\n", funcionario.email);
				printf("Cargo: %s\n", funcionario.cargo);
				printf("Departamento: %s\n", funcionario.departamento);
				printf("Salário: R$%.2f\n", funcionario.salario);
				printf("---------------------\n\n");
			}

		}
	}
	fclose(arquivo);
	getche();
}
//função atualizar funcionário
void update_funcionario()
{
	char matricula[15];
	char email[50];
	char cargo[25];
	char departamento[5];
	float salario;
	int choose;

	search();
	cabecalho();
	printf("1.Matrícula");
	printf("2.Email");
	printf("3.Cargo\n");
	printf("3.Departamento\n");
	printf("4.Salário\n\n");

	fflush(stdin);
	printf("Qual dado a ser alterado:");
	gets(choose);

	switch(choose){
		case 1:
			
			printf("informe a nova matricula: ");
			gets(matricula);
			break;
	}

}
/* Outras Funções*/
void cabecalho()
{
	system("cls||clear");
	printf("====== Escolha uma das opções abaixo: ======\n\n");
}
void sair()
{
	printf("Saiu!\n");
}

//Menu main
int main()
{

	setlocale(LC_ALL, "Portuguese");

	int continuar = 1;

	do
	{
		cabecalho();
		printf("1. Criar Funcionário\n");
		printf("2. Ler Todos os Funcionário\n");
		printf("3. Atualizar Funcionário\n");
		printf("4. Deletar Funcionário\n");
		printf("5. Buscar Funcionário por matrícula\n");
		printf("0. Sair\n\n");
		printf("Escolha: ");
		scanf("%d", &continuar);
		printf("=============================================================\n");
		system("cls || clear");

		switch(continuar)
		{
		case 1:
			create_funcionario();
			break;

		case 2:
			read_funcionario();
			break;

		case 3:
			update_funcionario();
			break;

		case 4:
			delete_funcionario();
			break;

		case 5:
			search();
			break;

		case 0:
			sair();
			break;

		default:
			printf("Digite uma opção válida!\n\n");
		}

	}
	while(continuar);

	return 0;
}
