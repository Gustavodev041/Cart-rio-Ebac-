#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun�ao reponsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando infoma��es do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo, "w" significa escrever
	fprintf(file,"\nCPF: ");
	fprintf(file, cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//Abrindo o arquivo
	fprintf(file,",\nNOME: ");//Mostra o nome cadastrado pelo usu�rio
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Abrindo o arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");//abrindo o arquivo
	fprintf(file,",\nSOBRENOME: ");//Mostra o sobrenome cadastrado pelo usu�rio
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Abrindo o arquivo
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");//Abrindo o arquivo
	fprintf(file,",\nCARGO: ");//Mostra o cargo cadastrado pelo usu�rio
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Abrindo o arquivo
	fprintf(file,cargo);
	fprintf(file,".\n\n");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//coletando informa��es do usu�rio
	scanf("%s",cpf);
	
	FILE *file;//Criando um arquivo
	file = fopen(cpf,"r");//ler o arquivo
	
	if(file == NULL)//Se o usu�rio n�o existir, ira aparecer a mensagem abaixo
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");//Caso o arquivo n�o seja localizado
	}	
	
	printf("\nEssas s�o as informa��es do usu�rio: \n");//Resposta a pesquisa do usu�rio
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
		
	printf("Digite o CPF do usu�rio a ser deletado: ");//
	scanf("%s",cpf);
		
	remove(cpf);//Removendo o (cpf)
		
	FILE *file;
	file = fopen(cpf,"r");//Ler o arquivo
		
	if(file == NULL);//Se o usu�rio n�o existir, ira aparecer a mensagem abaixo
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");//Caso o cpf n�o esteja cadastrado ou tenha sido deletado
		system("pause");
	}
		
}



int main()
	{	
	
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{	
	
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("### C�rtorio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");//Fim do menu
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: ");
		scanf("%d", &opcao);//Armazenando a escolha do usu�rio
	
		system("cls");//reponsavel por limpar a tela
		
		
		switch(opcao)//inicio da sele��o do menu
		{
			case 1:
			registro();//chamada de fun��es
			break;
				
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
				
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;				
		}//fim da sele��o

	}	
}
