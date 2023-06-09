#include <stdio.h>
#include <stdlib.h>

#define MAX_DESC 50


typedef struct produto { 
        int codigo;
        char descricao[MAX_DESC];
        int qtd_estoque;
        float preco;
} Produto, *PProduto,**PPProduto;


void inicializa_lista_produtos(PPProduto lista){
    lista = (PPProduto) malloc(1*sizeof(PProduto));
    PProduto produto = (PProduto) malloc(1*sizeof(Produto));
    produto = NULL; 
    lista[0] = produto;             
                     
}

//Limpa o buffer do teclado
void limparBuffer(){
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

void incluir_produto_estoque(PPProduto lista,int* ultimo_item_indice){
    

   int novo_indice = *ultimo_item_indice+1;
    
   PProduto produto = lista[*ultimo_item_indice];
   printf("Cadastrando produto cod(%d)\n\n",novo_indice);
   produto[*ultimo_item_indice].codigo = novo_indice;
   printf("Informe a Descricao do Produto: "); 
   scanf(" %[^\n]",produto[*ultimo_item_indice].descricao);
   printf("Informe a Quantidade em estoque: "); 
   scanf("%d",&produto[*ultimo_item_indice].qtd_estoque);
   printf("Informe a Valor do produto: "); 
   scanf("%f",&produto[*ultimo_item_indice].preco);
    printf("\nxxxxxxxxantgesxxxxxxxxxxxxxxxxxxxxx"); 
   getch();
   PPProduto nova_lista = (PPProduto) realloc(lista,novo_indice*sizeof(PProduto));
    printf("\nxxxxxxxxdepoisxxxxxxxxxxxxxxxxxxxxx"); 
   getch(); 
   lista = nova_lista;
   *ultimo_item_indice = novo_indice; 
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
   printf("\n Produto incluido com sucesso!!!");
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
   
   printf("\n\nIncluir novo Produto?\nDigite: S -> ");
   char again = 'n';
   scanf(" %c",&again);
   //limparBuffer();
   printf("\n-->%c<---\n",again);
  
   if (again == 'S' || again == 's' ){
      incluir_produto_estoque(lista,ultimo_item_indice);
   } 	
                      
            
  
}


int menu_principal_opcoes(){
	int opcao;
	system("cls");		
	printf("\n(1) Gerenciar Produto");
	printf("\n(2) Gerenciar Pedido");
	printf("\n(3) Sair");
	printf("\n\nDigite uma opcao: ");
	scanf("%d",&opcao);	
	return opcao;
}

int menu_gerenciar_produto_opcoes(){
	int opcao;
	system("cls");	
	printf("\n######################");
	printf("\nGerenciar Produto");
	printf("\n######################\n");
	printf("\n(1) Incluir");
	printf("\n(2) Alterar");
	printf("\n(3) Listar");
	printf("\n(4) Consultar");
	printf("\n(5) Excluir");
	printf("\n(6) Voltar");
	printf("\n\nDigite uma opcao: ");
	scanf("%d",&opcao);	
	return opcao;

}

int menu_gerenciar_pedido_opcoes(){
	int opcao;
	system("cls");	
	printf("\n######################");
	printf("\nGerenciar Pedido");
	printf("\n######################\n");	
	printf("\n(1) Adicionar produto no carrinho");
	printf("\n(2) Consultar carrinho de compras");
	printf("\n(3) Excluir produto do carrinho");
	printf("\n(4) Alterar quantidade do produto do carrinho");	
	printf("\n(5) Finalizar Pedido");	
	printf("\n(6) Esvaziar carrinho de compras");
	printf("\n(7) Voltar");
	printf("\n\nDigite uma opcao: ");
	scanf("%d",&opcao);	
	return opcao;
}

void gerenciar_menu_produto(PPProduto estoque,int* ind_estoque){
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_gerenciar_produto_opcoes();		
		switch(opcao){
			case 1:
                system("CLS");
				printf("Incluindo Produto\n\n");
                incluir_produto_estoque(estoque,ind_estoque);
                sair = 1;  
				getch();
				break;
			case 2:
				printf("Alterar Produto");
				getch();
				break;								
			case 3:
				printf("Listar produtos");
				sair = 1;
				break;
			case 4:
				printf("Consultar Produto");				
				getch();
				break;
			case 5:
				printf("Excluir Produto");
				getch();
				break;								
			case 6:
				printf("Voltar");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
	
}

void gerenciar_menu_pedido(){
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_gerenciar_pedido_opcoes();		
		switch(opcao){
			case 1:
				printf("Adicionar produto no carrinho");				
				getch();
				break;
			case 2:
				printf("Consultar carrinho de compras");
				getch();
				break;								
			case 3:
				printf("Excluir produto do carrinho");
				sair = 1;
				break;
			case 4:
				printf("Alterar quantidade do produto do carrinho");				
				getch();
				break;
			case 5:
				printf("Finalizar Pedido");
				getch();
				break;								
			case 6:
				printf("Esvaziar carrinho de compras");
				getch();
				break;								
			case 7:
				printf("Voltar");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
	
}

void gerenciar_menu_principal(PPProduto estoque,int* ind_estoque){
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_principal_opcoes();		
		switch(opcao){
			case 1:				
				gerenciar_menu_produto(estoque,ind_estoque);
				getch();
				break;
			case 2:			
				gerenciar_menu_pedido();
				getch();
				break;								
			case 3:
				printf("Sair");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
	
}

int main(int argc, char *argv[]) {
    printf("oi!");
    PProduto estoque;
    inicializa_lista_produtos(&estoque);
    int ultimo_item_indice_estoque = 0;
	gerenciar_menu_principal(&estoque,&ultimo_item_indice_estoque);	
	return 0;
}
