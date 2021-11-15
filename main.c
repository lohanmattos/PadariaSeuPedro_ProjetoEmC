#include<stdio.h>

//Define a quantidade de produtos da loja
int itensLoja = 5; 

// Declaração das Funções
void Menu();
void CadastrarProduto();
void ListaProdutos();
void VenderProduto();
void AlterarEstoque();

// Cria uma STRUCT para armazenar os dados de um produto
    typedef struct{
        int codigo; 
        char nome[50];
        float quantidadeKg;
        float preco;
    } Produtos; // Define o nome do novo tipo criado

//Programa Principal
int main(){

    // Cria um vetor para armazenar os itens da loja
    Produtos vetorProdutos[itensLoja];
    Menu();

}

void Menu(){
    int opcao = 0; 

    printf("\n---------- Padaria do Seu Pedro -----------\n\n\n");
    printf("Escolha uma opcao: \n");
    printf("1) Cadastrar novo Produto. \n");
    printf("2) Listar Produto. \n");
    printf("3) Vender Produto. \n");
    printf("4) Alterar Estoque. \n\n");


    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        CadastrarProduto();
        break;
    case 2:
        ListaProdutos();
        break;  
    case 3:
        VenderProduto();
        break;
    case 4:
        AlterarEstoque();
        break;  
    
    default:
        break;
    }
}

void CadastrarProduto(){
    int opcao = 0;
    Produtos produto;
    Produtos vetorProdutos[itensLoja];

    do
    {
        printf("Codigo do Produto: ");
        scanf("%d", &produto.codigo);

        printf("Nome: ");
        scanf("%s", &produto.nome);

        printf("Informe a quantidade (kilos): ");
        scanf("%f", &produto.quantidadeKg);

        printf("Informe preco: ");
        scanf("%f", &produto.preco);

        vetorProdutos[0] = produto;

        printf("Deseja um NOVO produto ? (0=sim , 1=não)");
        itensLoja++;

        scanf("%d", &opcao);   
   
    } while (opcao == 0);
        //printf("Codigo: %d Nome: %s Quantidade: %.2f Preco: %.2f \n", produto.codigo, produto.nome,
        //produto.quantidadeKg, produto.preco);

        //printf("Codigo: %d Nome: %s Quantidade: %.2f Preco: %.2f \n", vetorProdutos[0].codigo, vetorProdutos[0].nome,
        //vetorProdutos[0].quantidadeKg, vetorProdutos[0].preco);

    Menu(); 
}

void ListaProdutos(){
    
}

void VenderProduto(){

}

void AlterarEstoque(){

}