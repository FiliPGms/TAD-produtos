#include <stdlib.h>
#include <stdio.h>
#include "ListaProdutos.h"

int ler_arquivo_produtos(const char* nome_arquivo, ListaProdutos* lista);
int teste_inserir();
int teste_arquivo();

int main(int argc, char *argv[])
{
   printf("Iniciando testes da Lista de Produtos...\n");

   printf("Teste de insercao de produtos na lista:\n");
    if (!teste_inserir()) {
        printf("Teste de insercao falhou.\n");
        return 1;
    }
    printf("Teste de insercao passou.\n");  

    printf("Teste de leitura de produtos de arquivo:\n");

    if (!teste_arquivo()) {
        printf("Teste de leitura de arquivo falhou.\n");
        return 1;
    }
    printf("Teste de leitura de arquivo passou.\n");

    return 0;
}   

int ler_arquivo_produtos(const char* nome_arquivo, ListaProdutos* lista) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        return 0; // Falha ao abrir o arquivo
    }

    char nome[50];
    char categoria[30];
    int codigo;
    double preco;
    int quantidade;
    while (fscanf(arquivo, "%d %lf", &nome, &categoria, &codigo, &preco, &quantidade) == 2) {
        ListaProdutos* produto = Criar(nome, categoria, codigo, preco, quantidade);
        if (produto == NULL || !inserir(lista, produto)) {
            fclose(arquivo);
            return 0; // Falha ao criar ou inserir a produto
        }
    }

    fclose(arquivo);
    return 1; // Sucesso
}   


int teste_inserir() {
    ListaProdutos* lista = criar(2);
    if (lista == NULL) {
        return 0; // Falha na criação da lista
    }

    ListaProdutos* produto1 = Criar("Arroz", "Cereais",001, 50, 5.49);
    ListaProdutos* produto2 = Criar("Feijão","Cereais", 002, 40, 6.29);
    ListaProdutos* produto3 = Criar("Açúcar", "Mercearia", 003, 60, 4.99);

    if (!inserir(lista, produto1) || !inserir(lista, produto2)) {
  
        return 0; // Falha na inserção
    }
    imprimir(lista);
    
    // Tentativa de inserir além da capacidade
    if (inserir(lista, produto3)) {
        liberar(lista);
        return 0; // Inserção deve falhar
    }

    liberar(lista);
    return 1; // Sucesso
}

int teste_arquivo() {
    ListaProdutos* lista = criar(10);
    if (lista == NULL) {
        return 0; // Falha na criação da lista
    }

    ler_arquivo_produtos("produtos.txt", lista);
    imprimir(lista);
    liberar(lista);

    return 1; // Sucesso
}   