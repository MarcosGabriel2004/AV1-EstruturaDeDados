#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 31
#define MAX_QTD 50

void setup(float prec[MAX_QTD], int* qtd, int car[MAX_QTD], int qtdCar[MAX_QTD]){
	int i;
	
	for(i=0; i<50; i++){
		*qtd = 0;
		prec[i] = 0;
		car[i] = 0;
		qtdCar[i] = 0;
	}
}

// Função para o menu
void menu(int* opt, char lojaNome[MAX_STRING]){
	system("cls");
	printf("Bem-vindo a/ao %s\n\n", lojaNome);
	printf("(1) Cadastrar produtos\n");
	printf("(2) Exibir produtos cadastrados\n");
	printf("(3) Excluir produto\n");
	printf("(4) Selecionar produto para o carrinho\n");
	printf("(5) Exibir carrinho e valor total\n");
	printf("(6) Remover produto do carrinho\n");
	printf("(0) Sair\n\n");
	printf("Digite uma opcao: ");
	scanf("%d", opt);
}

void cadastroProduto(char prod[MAX_QTD][MAX_STRING], float prec[MAX_QTD], int* qtd, int car[MAX_QTD], int qtdCar[MAX_QTD]){
	int i;
	
	do{
		system("cls");
		printf("Quantos produtos serao cadastrados em sua loja?\n");
		scanf("%d", qtd);
		
		if(*qtd < 1 || *qtd > 50){
			printf("\nERRO: A quantidade de produtos deve estar entre 1 e 50.\n");
			printf("\nPressione qualquer tecla para digitar novamente...\n\n");
			getch();
		}
	}while(*qtd < 1 || *qtd > 50);
	
	for(i = 0; i < *qtd; i++){
		do{
			system("cls");
			printf("\nNome do produto %d: ", i+1);
			scanf(" %30[^\n]%*c", prod[i]);
			
			if(strlen(prod[i]) > 30){
				printf("\nUtilize no maximo 30 caracteres.");
				getch();
			}
		}while(strlen(prod[i]) > 30);
		
		do{
			printf("\nValor de %s: R$", prod[i]);
			scanf("%f", &prec[i]);
			
			if(prec[i] < 0){
				printf("\nO valor de um produto nao pode ser negativo.\n");
				getch();
			}
		}while(prec[i] < 0);
	}
}

void exibirProduto(char prod[MAX_QTD][MAX_STRING], float prec[MAX_QTD], int qtd){
	system("cls");
	
	int i;
	
	if(qtd > 0){
		for(i = 0; i < qtd; i++){
			if(strcmp(prod[i], "")){
				printf("(%d) %s \t\t| R$%.2f\n", i+1, prod[i], prec[i]);
			}
		}
	}else{
		printf("ERRO: Nao ha produtos cadastrados. Selecione a opcao 1 do menu.");
	}
}

void excluirProduto(char prod[MAX_QTD][MAX_STRING], float prec[MAX_QTD], int qtd, int car[MAX_QTD], int qtdCar[MAX_QTD]){
	system("cls");
	
	int e, p;
	
	if(qtd > 0){
		do{
			exibirProduto(prod, prec, qtd);
			
			printf("\n\nDigite o indice do produto a ser excluido: ");
			scanf("%d", &p);
			
			if(p < 1 || p > qtd){
				printf("\nOpcao invalida\n");
				printf("\nPressione qualquer tecla para digitar novamente...\n\n");
				getch();
			}
		}while(p < 1 || p > qtd);
		
		p -= 1;
		
		do{
			system("cls");
			printf("\nTem certeza que deseja excluir %s? (1) Sim | (2) Nao\n", prod[p]);
			scanf("%d", &e);
			
			if(e == 1){
				strcpy(prod[p], "\0");
				prec[p] = 0;
				car[p] = 0;
				qtdCar[p] = 0;
				printf("Produto excluido");
			}else if(e == 2){
				printf("\n\nExclusao cancelada");
			}else{
				printf("\nOpcao invalida\n");
				printf("\nPressione qualquer tecla para digitar novamente...\n\n");
			}
			
			getch();
		}while(e != 1 && e != 2);
	}else{
		printf("ERRO: Nao ha produtos cadastrados. Selecione a opcao 1 do menu.");
	}
}

void adicionarCarrinho(char prod[MAX_QTD][MAX_STRING], float prec[MAX_QTD], int qtd, int car[MAX_QTD], int qtdCar[MAX_QTD]){
	system("cls");
	
	int e, p;
	
	if(qtd > 0){
		do{
			exibirProduto(prod, prec, qtd);
			
			printf("\n\nDigite o indice do produto para ser armazenado no carrinho: ");
			scanf("%d", &p);
			
			if(p < 1 || p > qtd){
				printf("\nOpcao invalida\n");
				printf("\nPressione qualquer tecla para digitar novamente...\n\n");
				getch();
			}
		}while(p < 1 || p > qtd);
		
		p -= 1;
		
		system("cls");
		
		printf("%s \t\t\t| R$%.2f\n\n", prod[p], prec[p]);
		
		car[p] = 1;
		
		do{
			printf("Quantidade: ");
			scanf("%d", &qtdCar[p]);
			
			if(qtdCar[p] <= 0){
				printf("\nA quantidade nao pode ser negativa ou nula.\n\n");
				getch();
			}
		}while(qtdCar[p] <= 0);
		
		printf("%s (%d unidade(s)) adicionado(a) ao carrinho!", prod[p], qtdCar[p]);
	}else{
		printf("ERRO: Nao ha produtos cadastrados. Selecione a opcao 1 do menu.");
	}
}

exibirCarrinho(char prod[MAX_QTD][MAX_STRING], float prec[MAX_QTD], int qtd, int car[MAX_QTD], int qtdCar[MAX_QTD]){
	system("cls");
	
	int i;
	float total = 0;
	
	printf("CARRINHO\n\n");
	
	for(i = 0; i < qtd; i++){
		if(qtdCar[i] > 0){
			if(car[i]){
				printf("(%d) ", i+1);
				printf("%s \t\t| R$%.2f \t| %d unidade(s)\n", prod[i], prec[i], qtdCar[i]);
				
				total += prec[i] * qtdCar[i];
			}
		}
	}
	
	if(total == 0){
		printf("O carrinho se encontra vazio. Compre atraves da opcao 4.");
	}
	printf("\n\nTOTAL: R$%.2f", total);
}

excluirCarrinho(char prod[MAX_QTD][MAX_STRING], float prec[MAX_QTD], int qtd, int car[MAX_QTD], int qtdCar[MAX_QTD]){
	int e, p;
	
	do{
		system("cls");
		
		exibirCarrinho(prod, prec, qtd, car, qtdCar);
		
		printf("\n\nDigite o indice do produto a ser excluido do carrinho: ");
		scanf("%d", &p);
		
		p -= 1;
		
		if(qtdCar[p] < 1){
			if(!car[p]){
				printf("\nOpcao invalida\n");
				printf("\nPressione qualquer tecla para digitar novamente...\n\n");
				getch();
			}
		}
		
	}while(!car[p] || qtdCar[p] < 1);
	
	do{
		system("cls");
		printf("\nTem certeza que deseja remover %s do carrinho? (1) Sim | (2) Nao\n", prod[p]);
		scanf("%d", &e);
		
		if(e == 1){
			car[p] = 0;
			qtdCar[p] = 0;
			printf("Produto removido do carrinho");
		}else if(e == 2){
			printf("\n\nRemocao cancelada");
		}else{
			printf("\nOpcao invalida\n");
			printf("\nPressione qualquer tecla para digitar novamente...\n\n");
		}
		
		getch();
	}while(e != 1 && e != 2);
	
}

int main(int argc, char *argv[]) {
	
	// Declaração de variáveis
	int opt, qtdProdutos, carrinho[MAX_QTD], qtdCarrinho[MAX_QTD];
	float preco[MAX_QTD];
	char lojaNome[MAX_STRING], produto[MAX_QTD][MAX_STRING];
	
	// Setup
	setup(preco, &qtdProdutos, carrinho, qtdCarrinho);
	
	// Nome da loja
	do{
		system("cls");
		printf("Qual o nome de sua loja?\n");
		gets(lojaNome);
		
		if(strlen(lojaNome) > 30){
			printf("\nUtilize no maximo 30 caracteres.");
			getch();
		}
	}while(strlen(lojaNome) > 30);
	
	// Repetição do programa/menu
	do{
		menu(&opt, lojaNome);
		
		switch (opt){
			
			case 0:
				exit(1);
				break;
			
			case 1:
				cadastroProduto(produto, preco, &qtdProdutos, carrinho, qtdCarrinho);
				break;
			
			case 2:
				exibirProduto(produto, preco, qtdProdutos);
				break;
			
			case 3:
				excluirProduto(produto, preco, qtdProdutos, carrinho, qtdCarrinho);
				break;
			
			case 4:
				adicionarCarrinho(produto, preco, qtdProdutos, carrinho, qtdCarrinho);
				break;
				
			case 5:
				exibirCarrinho(produto, preco, qtdProdutos, carrinho, qtdCarrinho);
				break;
				
			case 6:
				excluirCarrinho(produto, preco, qtdProdutos, carrinho, qtdCarrinho);
				break;
			
			default:
				system("cls");
				printf("Opcao invalida");
				printf("\nPressione qualquer tecla para retornar ao menu...");
				break;
		}
		getch();
	}while(opt != 0);
	
	return 0;
}
