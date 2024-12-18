#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel pelo cadastro de usu�rios no sistema 
 {
 	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o
	
	printf("Digite o CPF a ser cadastrado: "); //Coleta de informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a srting
	
	strcpy(arquivo, cpf); // 
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da vari�vel/string
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL,"portuguese"); //Definir liguaguem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Arquivo n�o localizado, tente novamente! \n\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usur�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPf que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf ("Usu�rio n�o encontrado! \n");
		system("pause");
	}
		
}

int main()
{
	int opcao=0; //Definir variavel
	int x=1;
	
	for(x=1;x=1;) //opera��o de repeti��o
	{

		system("cls"); //responsavel por limpar a  tela
		
		setlocale(LC_ALL,"portuguese"); //Definir liguaguem
	
		printf("        *** Cart�tio EBAC ***\n\n"); //Menu inicial
		printf("   Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("digite a op��o desejada:");
	
		scanf("%d", &opcao); //Armazenamento da escolha de usur�rios
	
		system("cls"); //responsavel por limpar a  tela
		
		switch(opcao) //inicio da sele��o do menu
 		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("obrigado e at� logo!\n");
			return 0;
			break;
			
			
			default:
			printf("op��o indispon�vel!\n");
			system("pause");
			break;
				
		}
	}
} 
