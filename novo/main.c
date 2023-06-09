#include <stdio.h>
#include <stdlib.h>

#define MAX_DESC 50


typedef struct produto { 
        int codigo;
        char descricao[MAX_DESC];
        int qtd_estoque;
        float preco;
} Produto, *PProduto,**PPProduto;


void incluir_produto_estoque(PPProduto* lista,int* qtd_itens_estoque){
   int novo_indice = -1;
  
   
   if (*qtd_itens_estoque == 0){
            novo_indice = 1;
            *lista = (PPProduto) malloc(sizeof(PProduto)); 
             
            } 
   else{
        novo_indice = *qtd_itens_estoque+1;
        *lista = (PPProduto) realloc(*lista, novo_indice*sizeof(PProduto));
        }
       
        
   if(!lista){ 
		printf("PROBLEMA NA ALOCAÇÃO DA LSITA\n\n");
		system("PAUSE");
		}
		
   PProduto produto = (PProduto) malloc(sizeof(Produto));
   if(!produto){ 
    	printf("PROBLEMA NA ALOCAÇÃO DO PRODUTO\n\n");
    	system("PAUSE");
	}
	
   
   
   printf("Cadastrando produto cod(%d)\n\n",novo_indice);
   produto->codigo = novo_indice;
   printf("Informe a Descricao do Produto: "); 
   scanf(" %[^\n]",produto->descricao);
   printf("Informe a Quantidade em estoque: "); 
   scanf("%d",&(produto->qtd_estoque));
   printf("Informe a Valor do produto: "); 
   scanf("%f",&(produto->preco));
   
   
  (*lista)[*qtd_itens_estoque] = produto;  
   *qtd_itens_estoque = novo_indice;
   
   
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
   printf("\n Produto incluido com sucesso!!!");
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
   
   printf("\n\nIncluir novo Produto?\nDigite: S -> ");
   char again = 'n';
   scanf(" %c",&again);
  
   if (again == 'S' || again == 's' ){
      incluir_produto_estoque(lista,qtd_itens_estoque);
   } 	
                      
            
  
}
void exibir_produtos_estoque(PPProduto lista,int qtd_itens_estoque){
     printf("\n\n");
     float total_geral = 0.0;
     int i;
     for(i=0; i < qtd_itens_estoque; i++){
             PProduto prod = lista[i];
             float total_prod = prod->qtd_estoque * prod->preco;
             total_geral += total_prod;
             printf("COD: %d - %s - Qtd em estoque: %d, ",prod->codigo, prod->descricao, prod->qtd_estoque);
             printf("Valor unitario R$ %.2f Total R$ %.2f\n",prod->preco,total_prod);
             }
          
     printf("\n\n VALORT TOTAL DO ESTOQUE R$ %.2f EM %d ITENS\n",total_geral,qtd_itens_estoque);
     
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

void gerenciar_menu_produto(PPProduto* estoque,int* qtd_itens_estoque){
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_gerenciar_produto_opcoes();		
		switch(opcao){
			case 1:
                system("CLS");
                printf("\n######################");
				printf("\nIncluindo Produto\n\n");
				printf("\n######################\n");
                incluir_produto_estoque(estoque,qtd_itens_estoque);
                sair = 0;  
				//getch();
				break;
			case 2:
                printf("\n######################");
				printf("\nAlterar Produto");
				printf("\n######################\n");
				exibir_produtos_estoque(*estoque,*qtd_itens_estoque);
				printf("\n\n ");
				getch();
				break;								
			case 3:
                system("CLS");
                printf("\n######################");
				printf("\nRelacao de produtos no estoque");
				printf("\n######################\n");
				exibir_produtos_estoque(*estoque,*qtd_itens_estoque);
                sair = 0;
                getch();
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

void gerenciar_menu_principal(PPProduto* estoque,int* qtd_itens_estoque){
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_principal_opcoes();		
		switch(opcao){
			case 1:				
				gerenciar_menu_produto(estoque,qtd_itens_estoque);
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
    PPProduto estoque;
    int qtd_itens_estoque = 0;
	gerenciar_menu_principal(&estoque,&qtd_itens_estoque);	
	return 0;
}
