#include <stdlib.h>
#include <stdio.h>
#include "ListaDesejos.h"

int ler_arquivo_produtos(const char* nome_arquivo, ListaDesejos* lista);
int teste_inserir();
int teste_arquivo();

int main(int argc, char *argv[])
{
    printf("Iniciando testes da Lista de Produtos...\n\n");

    printf("Teste de inserção de produtos na lista:\n");
    if (!teste_inserir()) {
        printf("❌ Teste de inserção falhou.\n");
        return 1;
    }
    printf("✅ Teste de inserção passou.\n\n");  

    printf("Teste de leitura de produtos de arquivo:\n");
    if (!teste_arquivo()) {
        printf("❌ Teste de leitura de arquivo falhou.\n");
        return 1;
    }
    printf("✅ Teste de leitura de arquivo passou.\n");

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

    printf("Lista de Desejos:\n");
    // Correção: verificar se conseguiu ler 5 itens por linha
    while (fscanf(arquivo, "%49s %29s %d %f %d", nome, categoria, &codigo, &preco, &quantidade) == 5)   {
        Produto* produto = criarProduto(nome, categoria, codigo, preco, quantidade);
        printf("Lido: %s %s %d %.2f %d\n", nome, categoria, codigo, preco, quantidade);
        if (produto == NULL || !inserir(lista, produto)) {
            fclose(arquivo);
            printf("Erro ao criar ou inserir produto.\n");
            return 0;
        }
    }

    fclose(arquivo);
    return 1; // Sucesso
}   

int teste_inserir() {
    ListaDesejos* ptr_lista = inicializaListaDesejos(2);
    if (ptr_lista == NULL) {
        printf("Erro: não foi possível criar a lista.\n");
        return 0;
    }

    Produto* produto1 = criarProduto("Macarrao", "Cereais", 1, 3.20, 50);
    Produto* produto2 = criarProduto("Feijao", "Cereais", 2, 6.29, 40);
    Produto* produto3 = criarProduto("Queijo", "Frios", 3, 10.90, 60);

    if (!inserir(ptr_lista, produto1) || !inserir(ptr_lista, produto2)) {
        printf("Falha na inserção inicial.\n");
        liberarListaDesejos(ptr_lista);
        return 0;
    }

    imprimir(ptr_lista);

    // Tentativa de inserir além da capacidade
    if (inserir(ptr_lista, produto3)) {
        printf("Falha: inseriu além da capacidade.\n");
        liberarListaDesejos(ptr_lista);
        return 0;
    }

    liberarListaDesejos(ptr_lista);
    return 1;
}


int teste_arquivo() {
    ListaDesejos* ptr_lista = inicializaListaDesejos(10);
    if (ptr_lista == NULL) {
        printf("Erro: não foi possível criar a lista.\n");
        return 0;
    }

    if (!ler_arquivo_produtos("TAD-listaDesejos/produtos.txt", ptr_lista)) {
        liberarListaDesejos(ptr_lista);
        return 0;
    }

    imprimir(ptr_lista);
    liberarListaDesejos(ptr_lista);
    return 1;
}