#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema
{
		// inicio da cria��o de vari�veis/strings
	char arquivo[40]; 
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo [40];
	
	// final da cria��o de vari�veis
	
	printf (" Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a strings 
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo w= escrever (write)
	fprintf(file , cpf); // salvo o valor da vari�vel
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
		printf("\nN�o foi possivel abrir o arquivo, n�o localizado.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
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
		printf(" Usu�rio n�o encontrado\n\n");
		system("pause");
	}
	
}
	

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### CART�RIO DA EBAC ###\n\n"); // In�cio do menu
		printf(" ### SEJA BEM VINDO ###\n\n");
		printf("  Selecione a op��o desejada:\n\n\n");
		printf("\t 1- Registrar nome\n");
		printf("\t 2- Consultar nome\n");
		printf("\t 3- Deletar nome\n");
		printf("\t 4- Sair\n\n\n");
		printf("  Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
		system("cls"); // limpar a tela
	
		switch(opcao) // inicio da sele��o do menu
		{
			case 1:
			registro();  // chamada de fun��es
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
			printf("**Op��o inv�lida**\n\n"); 
			system("pause");
			break;
				// fim da sele��o
		}
	
	}
}
