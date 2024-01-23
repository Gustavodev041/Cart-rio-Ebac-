#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Funçao reponsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando infomações do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo, "w" significa escrever
	fprintf(file,"\nCPF: ");
	fprintf(file, cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//Abrindo o arquivo
	fprintf(file,",\nNOME: ");//Mostra o nome cadastrado pelo usuário
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");//coletando informações do usuário
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Abrindo o arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");//abrindo o arquivo
	fprintf(file,",\nSOBRENOME: ");//Mostra o sobrenome cadastrado pelo usuário
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informações do usuário
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Abrindo o arquivo
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");//Abrindo o arquivo
	fprintf(file,",\nCARGO: ");//Mostra o cargo cadastrado pelo usuário
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informações do usuário
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
	
	printf("Digite o CPF a ser consultado: ");//coletando informações do usuário
	scanf("%s",cpf);
	
	FILE *file;//Criando um arquivo
	file = fopen(cpf,"r");//ler o arquivo
	
	if(file == NULL)//Se o usuário não existir, ira aparecer a mensagem abaixo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");//Caso o arquivo não seja localizado
	}	
	
	printf("\nEssas são as informações do usuário: \n");//Resposta a pesquisa do usuário
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
		
	printf("Digite o CPF do usuário a ser deletado: ");//
	scanf("%s",cpf);
		
	remove(cpf);//Removendo o (cpf)
		
	FILE *file;
	file = fopen(cpf,"r");//Ler o arquivo
		
	if(file == NULL);//Se o usuário não existir, ira aparecer a mensagem abaixo
	{
		printf("O usuário não se encontra no sistema!.\n");//Caso o cpf não esteja cadastrado ou tenha sido deletado
		system("pause");
	}
		
}



int main()
	{	
	
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{	
	
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("### Cártorio da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");//Fim do menu

		scanf("%d", &opcao);//Armazenando a escolha do usuário
	
		system("cls");//reponsavel por limpar a tela
		
		
		switch(opcao)//inicio da seleção do menu
		{
			case 1:
			registro();//chamada de funções
			break;
				
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
				
			default:
			printf("Essa opção não está disponível\n");
			system("pause");
			break;				
		}//fim da seleção

	}	
}
