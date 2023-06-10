#include <stdio.h>
#include <stdlib.h>

#define MAX_DESC 50


typedef struct produto { 
        int codigo;
        char descricao[MAX_DESC];
        int qtd_estoque;
        float preco;
} Produto, *PProduto,**PPProduto;
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Descartar caractere
    }
}
void incluir_produto_estoque(PPProduto* lista,int* indice_ult_produto){
   int novo_codigo = -1;
   //int ultimo_indice = -1;
   //printf("--->tamanho (%d)",sizeof(*lista));
   if (*indice_ult_produto < 0){
            novo_codigo = 1;
            *lista = (PPProduto) malloc(sizeof(PProduto)); 
             
            } 
   else{
    
        novo_codigo = (*lista)[*indice_ult_produto]->codigo + 1;
       //ultimo_indice = (*lista)[*qtd_itens_estoque]->codigo + 1;
      // ultimo_indice
       //*qtd_itens_estoque += 1;
       printf("Novo tamanho %d",(*indice_ult_produto+2)*sizeof(PProduto));
       *lista = (PPProduto) realloc(*lista, (*indice_ult_produto+2)*sizeof(PProduto));
        }
       
        
   if(!lista){ 
		printf("PROBLEMA NA ALOCAÇÃO DA LISTA\n\n");
		system("PAUSE");
		}
		
   PProduto produto = (PProduto) malloc(sizeof(Produto));
   if(!produto){ 
    	printf("PROBLEMA NA ALOCAÇÃO DO PRODUTO\n\n");
    	system("PAUSE");
	}
	
   
   
   printf("Cadastrando produto cod(%d)\n\n",novo_codigo);
   produto->codigo = novo_codigo;
   printf("Informe a Descricao do Produto: "); 
   scanf(" %[^\n]",produto->descricao);
   printf("Informe a Quantidade em estoque: "); 
   scanf("%d",&(produto->qtd_estoque));
   printf("Informe a Valor do produto: "); 
   scanf("%f",&(produto->preco));
   
   *indice_ult_produto = *indice_ult_produto + 1;
  (*lista)[*indice_ult_produto] = produto;  
                 
   
   
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
   printf("\n Produto incluido com sucesso!!!");
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
   
   printf("\n\nIncluir novo Produto?\nDigite: S -> ");
   char again = 'n';
   scanf(" %c",&again);
   limparBuffer();

   if (again == 'S' || again == 's' ){
 
      incluir_produto_estoque(lista,indice_ult_produto);
   } 	
                      
  
  
}

int codigo_existe(PPProduto lista,int indice_ult_produto, int codigo_para_verificar){
    int i;
    for(i=0; i <= indice_ult_produto; i++){
             if(lista[i]->codigo == codigo_para_verificar){
                                 return 1;
                                 }
             }
    printf("\n ---------------------------------------------");
    printf("\n NENHUM ITEM NO ESTOQUE COM O CODIGO '%d'...",codigo_para_verificar);
    printf("\n ---------------------------------------------");
    return 0;
    }

void alterar_item(PPProduto* lista,int indice_ult_produto,int cod_item){
   int i;
   PProduto produto;  
   for(i=0;i<=indice_ult_produto; i++){
                                if ((*lista)[i]->codigo == cod_item){
                                produto = (*lista)[i];
                                }
   }
   printf("\n\nDados atuais do produto cod(%d)\n",cod_item);
   printf("     Descricao: %s\n",produto->descricao);
   printf("     Quantidade em estoque: %d\n",produto->qtd_estoque);
   printf("     Valor untario: %.2f\n",produto->preco);
   
   printf("\n\n -----------------------\n");
   
   printf("\n\n Inserindo novos dados para o produto cod(%d)\n\n",cod_item);
   printf("Informe a nova Descricao do Produto: "); 
   scanf(" %[^\n]",produto->descricao);
   printf("Informe a nova Quantidade em estoque: "); 
   scanf("%d",&(produto->qtd_estoque));
   printf("Informe o novo Valor do produto: "); 
   scanf("%f",&(produto->preco));
     
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
   printf("\n Produto alterado com sucesso!!!");
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");   
     }
void consultar_item(PPProduto lista,int indice_ult_produto,int cod_item){
   int i;
   PProduto produto;  
   
   for(i=0;i<=indice_ult_produto; i++){
                                if (lista[i]->codigo == cod_item){
                                produto = lista[i];
                                }
   }
   printf("\n\nExibindo dados do produto cod(%d)\n",cod_item);
   printf("     Descricao: %s\n",produto->descricao);
   printf("     Quantidade em estoque: %d\n",produto->qtd_estoque);
   printf("     Valor untario: %.2f\n",produto->preco);
   printf("     Valor Total do estoque: %.2f\n",produto->preco*produto->qtd_estoque);
   printf("\n     Pedidos:\n");//IMPLEMENTAR INFORMAÇÕES DOS PEDIDOS DO ITEM
   printf("     - Nenhum pedido finalizado com este item.\n");    
   
     }

int menu_escolha_item(PPProduto lista,int indice_ult_produto, char msgm[]){
     if(indice_ult_produto < 0 ){
     return 0;
     }
     int cod = 0;
     do{
        printf("\n\n ");
        printf(msgm);
        scanf("%d",&cod);
        limparBuffer();          
     }while(!codigo_existe(lista,indice_ult_produto,cod));
     return cod;
}

void exibir_produtos_estoque(PPProduto lista,int indice_ult_produto){
     printf("\n\n");
     
     if(indice_ult_produto < 0){
             printf("\n ---------------------------------------------");
             printf("\nNENHUM ITEM NO ESTOQUE CADASTRE ALGUM ITEM.");
             printf("\n ---------------------------------------------");
             return;             
     }
     float total_geral = 0.0;
     int i;
     
     for(i=0; i <= indice_ult_produto; i++){
             PProduto prod = lista[i];
             float total_prod = prod->qtd_estoque * prod->preco;
             total_geral += total_prod;
             printf("COD: %d - %s - Qtd em estoque: %d - Preco R$ %.2f\n",prod->codigo, prod->descricao, prod->qtd_estoque,prod->preco);
             //printf("Preco R$ %.2f Total R$ %.2f\n",prod->preco,total_prod);
             }
          
     //printf("\n\n VALOR TOTAL DO ESTOQUE R$ %.2f EM %d ITENS\n",total_geral,qtd_itens_estoque);
     
     }
void excluir_item(PPProduto* lista,int* indice_ult_produto, int cod_excluir){
     int i,j;
       PProduto produto_para_excluir;  
       for(i=0;i<=*indice_ult_produto; i++){
                                    if ((*lista)[i]->codigo == cod_excluir){
                                        produto_para_excluir = (*lista)[i];
                                        for (j=i+1;j<=*indice_ult_produto; j++){
                                            (*lista)[i] = (*lista)[j];
                                            i++;
                                            }
                                    }
       }
       (*lista)[*indice_ult_produto] = produto_para_excluir;
       if(*indice_ult_produto == 0){
        free((*lista));
       }else{
           *lista = (PPProduto) realloc(*lista,*indice_ult_produto*sizeof(PProduto));  
       }
       *indice_ult_produto -=1;
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
   printf("\n Produto excluido com sucesso!!!");
   printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); 
   printf("\n\nProduto cod.'%d' - ",cod_excluir);
   printf("%s\n",produto_para_excluir->descricao);

     }

int menu_principal_opcoes(){
	int opcao;
	system("cls");		
	printf("\n(1) Gerenciar Produto");
	printf("\n(2) Gerenciar Pedido");
	printf("\n(3) Sair");
	printf("\n\nDigite uma opcao: ");
	scanf("%d",&opcao);
    limparBuffer();	
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
    limparBuffer();	
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
    limparBuffer();	
	return opcao;
}

void gerenciar_menu_produto(PPProduto* estoque,int* indice_ult_produto){
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
                incluir_produto_estoque(estoque,indice_ult_produto);
                sair = 0;  
				//getch();
				break;
			case 2:
                system("CLS");
                printf("\n#################################");
				printf("\nEscolhendo Produto para alterar");
				printf("\n#################################\n");
				exibir_produtos_estoque(*estoque,*indice_ult_produto);
				int cod_alterar = menu_escolha_item(*estoque,*indice_ult_produto,"DIGITAR CODIGO QUE DESEJA ALTERAR: ");
				if (cod_alterar){ 
    				system("CLS");
                    printf("\n###################################");
    				printf("\nRealizando a alteracao do Produto");
    				printf("\n###################################\n");
    				alterar_item(estoque,*indice_ult_produto,cod_alterar);
                }
				sair = 0;
				getch();
				break;								
			case 3:
                system("CLS");
                printf("\n##################################");
				printf("\nRelacao de produtos no estoque");
				printf("\n#################################\n");
				exibir_produtos_estoque(*estoque,*indice_ult_produto);
                sair = 0;
                getch();
				break;
			case 4:
                system("CLS");
                printf("\n######################");
				printf("\nConsultar Produto");
				printf("\n######################\n");
				
				if(*indice_ult_produto < 0){
                 printf("\n ---------------------------------------------");
                 printf("\nNENHUM ITEM NO ESTOQUE CADASTRE ALGUM ITEM.");
                 printf("\n ---------------------------------------------");
                }else{
                int cod_consultar = menu_escolha_item(*estoque,*indice_ult_produto,"DIGITAR CODIGO QUE DESEJA CONSULTAR: ");
                    if (cod_consultar){
                       system("CLS");
                       consultar_item(*estoque,*indice_ult_produto,cod_consultar);
                    }
                }
                getch();
				break;
			case 5:
				system("CLS");
                printf("\n#################################");
				printf("\nEscolhendo Produto para Excluir");
				printf("\n#################################\n");
				exibir_produtos_estoque(*estoque,*indice_ult_produto);
				int cod_excluir = menu_escolha_item(*estoque,*indice_ult_produto,"DIGITAR CODIGO QUE DESEJA EXCLUIR: ");
                if (cod_excluir){
                   system("CLS");
                   printf("\n#################################");
    			   printf("\nExcluindo Produto cod:'%d'",cod_excluir);
    			   printf("\n#################################\n");
                   
                   excluir_item(estoque,indice_ult_produto,cod_excluir);
                }
                sair = 0;
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
				//printf("Voltar");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
	
}

void gerenciar_menu_principal(PPProduto* estoque,int* indice_ult_produto){
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_principal_opcoes();		
		switch(opcao){
			case 1:				
				gerenciar_menu_produto(estoque,indice_ult_produto);
				//getch();
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
    int indice_ult_produto = -1;
	gerenciar_menu_principal(&estoque,&indice_ult_produto);	
	return 0;
}
