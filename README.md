Aluno: Lucas Araujo Ferreira
Link do vídeo:  https://youtu.be/dvFaBkfElO0

Detalhamento do Código: Controle de Estoque de uma Loja de Roupas

Estrutura de Dados:
c
Copy code
typedef struct {
    int referencia;
    char descricao[100];
    int quantidade;
    char tamanho[3]; // Exemplo: P, M, G
    char categoria[30]; // Exemplo: "Camisetas", "Calcas"
} Vestuario;
A estrutura Vestuario representa um item de vestuário e possui campos como referência, descrição, quantidade em estoque, tamanho e categoria.

Função Principal (main):
c
Copy code
int main() {
    // Inicialização de variáveis e alocação dinâmica da estrutura Vestuario
    // ...
    do {
        // Exibição do menu principal e interação com o usuário
        // ...
        switch (opcao) {
            case 1:
                adicionarItem(roupas, &totalItens);
                break;
            case 2:
                atualizarEstoque(roupas, totalItens);
                break;
            case 3:
                listarPorCategoria(roupas, totalItens, categoria);
                break;
            default:
                // Tratamento para opções inválidas ou saída do programa
                break;
        }
    } while (opcao != 4);
    // Liberação da memória alocada
    // ...
    return 0;
}
A função principal contém um loop que exibe um menu interativo para o usuário, permitindo a escolha entre adicionar item, atualizar estoque, listar por categoria ou sair do programa.

Função adicionarItem:
c
Copy code
void adicionarItem(Vestuario* roupas, int* totalItens) {
    // Solicita e armazena os dados de um novo item
    // ...
}
Esta função permite ao usuário adicionar um novo item ao sistema, inserindo dados como referência, descrição, quantidade, tamanho e categoria.

Função atualizarEstoque:
c
Copy code
void atualizarEstoque(Vestuario* roupas, int totalItens) {
    // Solicita a referência do item e atualiza a quantidade em estoque
    // ...
}
Permite ao usuário atualizar a quantidade em estoque de um item existente, informando a referência do item desejado.

Função listarPorCategoria:
c
Copy code
void listarPorCategoria(Vestuario* roupas, int totalItens, char* categoria) {
    // Lista os itens de acordo com a categoria informada
    // ...
}
Essa função permite ao usuário listar os itens do estoque filtrados por uma categoria específica.
