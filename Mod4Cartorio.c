#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // função responsável por cadastrar os usuários no sistema
{
		// inicio da criação de variáveis/strings
	char arquivo[40]; 
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo [40];
	
	// final da criação de variáveis
	
	printf (" Digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a strings 
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo w= escrever (write)
	fprintf(file , cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf(" Digite o nome da ser cadastrado: ");
	scanf("%s" , nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fprintf(file, ", ");
	fclose(file);
	
	printf(" Digite o sobrenome da ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fprintf(file, ", ");
	fclose(file);
	
	printf(" Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file, ".");
	fclose(file);
	
	system("pause");

}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file==NULL)
	
	{
		printf("\nNão foi possivel abrir o arquivo, não localizado.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: \n\n");
		printf("%s", conteudo );
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	}

int deletar()
{
	char cpf[40];
	
	printf(" Digite o CPF a ser deletado: ");
	scanf("%s",cpf);

	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf(" Usuário não encontrado\n\n");
		system("pause");
	}
	
}
	

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### CARTÓRIO DA EBAC ###\n\n"); // Início do menu
		printf(" ### SEJA BEM VINDO ###\n\n");
		printf("  Selecione a opção desejada:\n\n\n");
		printf("\t 1- Registrar nome\n");
		printf("\t 2- Consultar nome\n");
		printf("\t 3- Deletar nome\n");
		printf("\t 4- Sair\n\n\n");
		printf("  Opção: "); //Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usuário
	
		system("cls"); // limpar a tela
	
		switch(opcao) // inicio da seleção do menu
		{
			case 1:
			registro();  // chamada de funções
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("\n\n	***OBRIGADO***\n\n");
			return 0;
			break;
			
			default:
			printf("**Opção inválida**\n\n"); 
			system("pause");
			break;
				// fim da seleção
		}
	
	}
}
