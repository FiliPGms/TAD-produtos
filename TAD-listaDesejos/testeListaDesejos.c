#include <stdio.h>
#include <stdlib.h>
#include "../TAD-GerenciaProd/GerenciaProduto.h"
#include "../TAD-listaDesejos/ListaDesejos.h"
#include <locale.h>

int ler_arquivo_produtos(const char* nome_arquivo, ListaDesejos* lista);
int teste_inserir();
int teste_arquivo();

int main(void) {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    printf("Iniciando testes da Lista de Desejos...\n\n");

    printf("Teste de inserção de produtos na lista:\n");
    if (!teste_inserir()) {
        printf("Teste de inserção falhou.\n");
        return 1;
    }
    printf("Teste de inserção passou.\n\n");

    printf("Teste de leitura de produtos de arquivo:\n");
    if (!teste_arquivo()) {
        printf("Teste de leitura de arquivo falhou.\n");
        return 1;
    }
    printf("Teste de leitura de arquivo passou.\n");

    return 0;
}

int ler_arquivo_produtos(const char* nome_arquivo, ListaDesejos* lista) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro: não foi possível abrir o arquivo %s\n", nome_arquivo);
        return 0;
    }

    char nome[50];
    char categoria[30];
    int codigo;
    float preco;
    int quantidade;

    printf("Lendo produtos do arquivo:\n");
    while (fscanf(arquivo, "%49s %29s %d %f %d", nome, categoria, &codigo, &preco, &quantidade) == 5) {
        Produto* produto = criarProduto(nome, categoria, codigo, preco, quantidade);
        if (produto == NULL) {
            printf("Erro ao criar produto.\n");
            fclose(arquivo);
            return 0;
        }

        adicionarProdutoListaDesejos(lista, produto);
        printf("✔ Produto adicionado: %s (%s) - Código %d - R$%.2f - Qtd: %d\n",
               nome, categoria, codigo, preco, quantidade);
    }

    fclose(arquivo);
    return 1;
}

int teste_inserir() {
    ListaDesejos* ptr_lista = inicializaListaDesejos(2);
    if (ptr_lista == NULL) {
        printf("Erro: não foi possível criar a lista de desejos.\n");
        return 0;
    }

    Produto* p1 = criarProduto("Macarrao", "Cereais", 1, 3.20, 50);
    Produto* p2 = criarProduto("Feijao", "Cereais", 2, 6.29, 40);
    Produto* p3 = criarProduto("Queijo", "Frios", 3, 10.90, 60);

    adicionarProdutoListaDesejos(ptr_lista, p1);
    adicionarProdutoListaDesejos(ptr_lista, p2);
    adicionarProdutoListaDesejos(ptr_lista, p3);

    imprimirListaDesejos(ptr_lista);

    printf("Removendo produto código 2 (Feijao)...\n");
    removerProdutoListaDesejos(ptr_lista, 2);
    imprimirListaDesejos(ptr_lista);

    printf("Tamanho atual da lista: %d\n", tamanhoListaDesejos(ptr_lista));

    liberarListaDesejos(ptr_lista);
    return 1;
}

int teste_arquivo() {
    ListaDesejos* ptr_lista = inicializaListaDesejos(10);
    if (ptr_lista == NULL) {
        printf("Erro: não foi possível criar a lista de desejos.\n");
        return 0;
    }

    if (!ler_arquivo_produtos("TAD-listaDesejos/produtos.txt", ptr_lista)) {
        liberarListaDesejos(ptr_lista);
        return 0;
    }

    imprimirListaDesejos(ptr_lista);
    liberarListaDesejos(ptr_lista);
    return 1;
}
