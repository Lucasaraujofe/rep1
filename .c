#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int referencia;
    char descricao[100];
    int quantidade;
    char tamanho[3]; // Exemplo: P, M, G
    char categoria[30]; // Exemplo: "Camisetas", "Calcas"
} Vestuario;

// Função para adicionar um item ao sistema
void adicionarItem(Vestuario* roupas, int* totalItens);

// Função para atualizar a quantidade em estoque de um item
void atualizarEstoque(Vestuario* roupas, int totalItens);

// Função para listar os itens por categoria
void listarPorCategoria(Vestuario* roupas, int totalItens, char* categoria);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int totalItens = 0, opcao;
    char categoria[30];
    Vestuario* roupas = (Vestuario*)malloc(sizeof(Vestuario));

    do {
        // Menu principal
        printf("\t Sistema de Controle de Estoque de uma Loja de Roupas\n\n");
        printf("1. Adicionar item.\n");
        printf("2. Atualizar estoque.\n");
        printf("3. Listar por categoria.\n");
        printf("4. Sair do sistema.\n");
        printf("\nEscolha uma opcao (1 a 4): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Limpa a tela e chama a função para adicionar item
                system("cls || clear");
                adicionarItem(roupas, &totalItens);
                break;
            case 2:
                // Limpa a tela e chama a função para atualizar o estoque
                system("cls || clear");
                atualizarEstoque(roupas, totalItens);
                break;
            case 3:
                // Limpa a tela e chama a função para listar por categoria
                system("cls || clear");
                listarPorCategoria(roupas, totalItens, categoria);
                break;
            default:
                if(opcao == 4){
                    // Limpa a tela e exibe mensagem de saída
                    system("cls || clear");
                    printf("\nSaindo do programa!\n\n");
                } else{
                    // Limpa a tela e exibe mensagem de valor inválido
                    system("cls || clear");
                    printf("\nValor invalido, tente de 1 a 4!\n\n\n");
                    system("pause");
                    system("cls || clear");
                }
                break;
        }
    } while (opcao != 4);

    // Libera a memória alocada para a estrutura Vestuario
    free(roupas);
    return 0;
}

void adicionarItem(Vestuario* roupas, int* totalItens) {

    printf("--------------ADICIONAR ITEM--------------\n\n");
    // Solicita e armazena os dados do novo item
    printf("Referencia: ");
    scanf("%d", &roupas[*totalItens].referencia);
    while(getchar() != '\n');  // Limpa o buffer do teclado
    printf("Descricao: ");
    fgets(roupas[*totalItens].descricao, sizeof(roupas[*totalItens].descricao), stdin);
    roupas[*totalItens].descricao[strcspn(roupas[*totalItens].descricao, "\n")] = '\0';  // Remove o \n do final
    printf("Quantidade: ");
    scanf("%d", &roupas[*totalItens].quantidade);
    printf("Tamanho: ");
    scanf("%s", &roupas[*totalItens].tamanho);
    printf("Categoria: ");
    scanf("%s", &roupas[*totalItens].categoria);

    (*totalItens)++;
    // Limpa a tela
    system("cls || clear");
}

void atualizarEstoque(Vestuario* roupas, int totalItens) {
    int referencia;
    printf("--------------ATUALIZAR ESTOQUE--------------\n\n");
    // Solicita a referência do item a ser atualizado
    printf("Referencia: ");
    scanf("%d", &referencia);

    // Procura o item pelo número de referência
    for (int i = 0; i < totalItens; i++) {

        if (roupas[i].referencia == referencia) {
            // Solicita e atualiza a nova quantidade em estoque
            printf("\nDigite a nova quantidade: ");
            scanf("%d", &roupas[i].quantidade);
            printf("\n\n");
            system("pause");
            // Limpa a tela
            system("cls || clear");
            return;
        }
    }

    printf("\n\nItem nao encontrado.\n");
    system("pause");
    // Limpa a tela
    system("cls || clear");
}

void listarPorCategoria(Vestuario* roupas, int totalItens, char* categoria) {
    printf("Digite a categoria: ");
    scanf("%29s", categoria);
    // Limpa a tela
    system("cls || clear");

    if (strcmp(categoria, "") == 0) {
        printf("\n\nCategoria invalida.\n");
        system("pause");
    }

    for (int i = 0; i < totalItens; i++) {
        // Compara a categoria do item com a categoria informada
        if (strcmp(roupas[i].categoria, categoria) == 0) {
            // Exibe os detalhes do item
            printf("--------------LISTA DE PRODUTO--------------\n\n");
            printf("Referencia: %d", roupas[i].referencia);
            printf("\nDescricao: %s", roupas[i].descricao);
            printf("\nQuantidade: %d", roupas[i].quantidade);
            printf("\nTamanho: %s", roupas[i].tamanho);
            printf("\nCategoria: %s\n\n", roupas[i].categoria);
            system("pause");
            // Limpa a tela
            system("cls || clear");
        } else {
            // Mensagem quando a categoria não é encontrada
            printf("\nCategoria nao encontrada!\n\n\n");
            system("pause");
            // Limpa a tela
            system("cls || clear");
        }
    }
}
