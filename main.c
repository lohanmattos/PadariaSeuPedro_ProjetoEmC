#include<stdio.h>
#include<locale.h>
#include <string.h>

//Define a quantidade de produtos da loja
const int itensLoja = 5; 

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
    //localização pt-br
    setlocale(LC_ALL, "Portuguese");

    // Cria um vetor para armazenar os itens da loja
    Produtos vetorProdutos[itensLoja];

    //Chama o menu inicial 
    Menu(vetorProdutos);

}

void Menu(Produtos vetor[]){

    int opcao = 0; 

    printf("\n---------- Padaria do Seu Pedro -----------\n\n\n");
    printf("Escolha uma opcao: \n");
    printf("1) Cadastrar novo Produto. \n");
    printf("2) Listar Produto. \n");
    printf("3) Vender Produto. \n");
    printf("4) Alterar Estoque. \n\n");
    printf("0) Sair. \n\n");


    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        CadastrarProduto(vetor);
        break;
    case 2:
        ListaProdutos(vetor);
        break;  
    case 3:
        VenderProduto(vetor);
        break;
    case 4:
        AlterarEstoque(vetor);
        break;  
    
    default:
        break;
    }
}

//Quantidade de produtos adicionados no vetor 
int quantidadeItens = 0;

void CadastrarProduto(Produtos vetor[]){
    int opcao = 0;
    Produtos produto;
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

        vetor[quantidadeItens] = produto;

        printf("Deseja um NOVO produto ? (0=Sim , 1=Nao)");
        //itensLoja++;
        quantidadeItens++;
        scanf("%d", &opcao);   
   
    } while (opcao == 0);
    Menu(vetor); 
}

void ListaProdutos(Produtos vetor[]){

    int opcao = 0;

    while (opcao == 0)
    {
        for (int i = 0; i < quantidadeItens; i++)
        {
        printf("Codigo: %d | Nome: %s | Quantidade: %.2f | Preco: %.2f \n", vetor[i].codigo, vetor[i].nome,
            vetor[i].quantidadeKg, vetor[i].preco);
        }

        printf("Deseja voltar ao menu inicial: (0= Nao , 1=Sim)");
        scanf("%d", &opcao);

    }

    Menu(vetor);

}

void VenderProduto(Produtos vetor[]){
    
    int opcao = 0; 

    while (opcao == 0)
    {
        int existe = 1;
        int codigoProduto;
        float quantidadeVendida = 0.0;

        printf("Digite o nome do Produto a ser vendido: ");
        scanf("%d", &codigoProduto);

        //Procura o produto dentro do vetor de produtos 
        for (int i = 0; i < quantidadeItens; i++)
        {
            //Verifica se o produto existe, retornando 0 caso exista.  
            //existe = strcmp(nomeProduto, vetor[i].nome);   
            if (vetor[i].codigo == codigoProduto)
            {   
                float qtdEstoque =  vetor[i].quantidadeKg; 
                printf("Nome do Produto: %s | qtd Em Estoque: %.2f \n", vetor[i].nome, qtdEstoque);
                printf("Quantidade a ser vendida ? ");
                scanf("%f", &quantidadeVendida);

                vetor[i].quantidadeKg =  vetor[i].quantidadeKg - quantidadeVendida; 

                printf("Produto vendido com sucesso\n");
                printf("Estoque atual: %.2f\n",vetor[i].quantidadeKg);

            }else{
                printf("Produto nao encontrado. Por Favor, verifique o item digitado.\n");
            }
            
        }
      
      printf("Deseja vender outro produto: (0=Sim , 1=Nao) ");
      scanf("%d", &opcao);

    }
    Menu(vetor);
}

void AlterarEstoque(Produtos vetor[]){

int opcao = 0; 

    while (opcao == 0)
    {
        int existe = 1;
        int codigoProduto;
        float quantidadeFabricada = 0.0;

        printf("Digite o nome do Produto a ser estocado: ");
        scanf("%d", &codigoProduto);

        //Procura o produto dentro do vetor de produtos 
        for (int i = 0; i < quantidadeItens; i++)
        {
            //Verifica se o produto existe  
            if (vetor[i].codigo == codigoProduto)
            {    
                printf("Codigo do Produto: %s \n", vetor[i].nome);
                printf("Quantidade a ser estocada ? ");
                scanf("%f", &quantidadeFabricada);
                float qtdAnterior = vetor[i].quantidadeKg;

                vetor[i].quantidadeKg =  vetor[i].quantidadeKg + quantidadeFabricada; 

                printf("Produto Atualizado com sucesso. \n");
                printf("Qtd Anterior: %.2f | qtd Atual: %.2f\n", qtdAnterior,vetor[i].quantidadeKg);

            }else{
                printf("Produto nao encontrado. Por Favor, verifique o item digitado.\n");
            }
            
        }
      
      printf("Deseja estocar outro produto: (0=Sim , 1=Nao) ");
      scanf("%d", &opcao);

    }
    Menu(vetor);


}