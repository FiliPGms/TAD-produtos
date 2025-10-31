#include <stdlib.h>
#include <stdio.h>
#include "ListaProdutos.h"

int ler_arquivo_produtos(const char* nome_arquivo, ListaProdutos* lista);
int teste_busca_e_remocao(const char* nome_arquivo, ListaProdutos* lista);
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

int ler_arquivo_produtos(const char* nome_arquivo, ListaProdutos* lista) {
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
    ListaProdutos* ptr_lista = criaLista(2);
    if (ptr_lista == NULL) {
        printf("Erro: não foi possível criar a lista.\n");
        return 0;
    }

    Produto* produto1 = criarProduto("Arroz", "Cereais", 1, 5.49, 50);
    Produto* produto2 = criarProduto("Feijao", "Cereais", 2, 6.29, 40);
    Produto* produto3 = criarProduto("Acucar", "Mercearia", 3, 4.99, 60);

    if (!inserir(ptr_lista, produto1) || !inserir(ptr_lista, produto2)) {
        printf("Falha na inserção inicial.\n");
        liberarLista(ptr_lista);
        return 0;
    }

    imprimir(ptr_lista);

    // Tentativa de inserir além da capacidade
    if (inserir(ptr_lista, produto3)) {
        printf("Falha: inseriu além da capacidade.\n");
        liberarLista(ptr_lista);
        return 0;
    }

    liberarLista(ptr_lista);
    return 1;
}


int teste_arquivo() {
    ListaProdutos* ptr_lista = criaLista(10);
    if (ptr_lista == NULL) {
        printf("Erro: não foi possível criar a lista.\n");
        return 0;
    }

    if (!ler_arquivo_produtos("TAD-listaSeq/produtos.txt", ptr_lista)) {
        liberarLista(ptr_lista);
        return 0;
    }

    imprimir(ptr_lista);
    liberarLista(ptr_lista);
    return 1;
}

int teste_busca_e_remocao(const char* nome_arquivo, ListaProdutos* lista) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    ListaProdutos* ptr_lista = criaLista(5);
    if (ptr_lista == NULL) {
        printf("Erro: não foi possível criar a lista.\n");
        return 0;
    }

    Produto* produto1 = criarProduto("Arroz", "Cereais", 1, 5.49, 50);
    Produto* produto2 = criarProduto("Feijao", "Cereais", 2, 6.29, 40);
    Produto* produto3 = criarProduto("Acucar", "Mercearia", 3, 4.99, 60);
    
    inserir(ptr_lista, produto1);
    inserir(ptr_lista, produto2);
    inserir(ptr_lista, produto3);

    printf("--- Estado Inicial da Lista ---\n");
    imprimir(ptr_lista);

    printf("\n[Busca] Tentando buscar o produto com código 2...\n");
    int pos_buscada = buscar(ptr_lista, 2);
    if (pos_buscada == -1) {
        printf("Falha na busca: Código 2 não encontrado.\n");

        liberarLista(ptr_lista);
        return 0;
    }
    printf("Sucesso na busca: Código 2 encontrado na posição %d.\n", pos_buscada);

    printf("[Busca] Tentando buscar produto inexistente (código 3)...\n");
    if (buscar(ptr_lista, 3) != -1) {
        printf("Falha na busca: Encontrou um código que não existe (3).\n");
        liberarLista(ptr_lista);
        return 0;
    }
    printf("Sucesso na busca: Código 3 não encontrado (retornou -1).\n");

    printf("\n[Remoção 1] Removendo produto do meio (Código 1 - Arroz)...\n");
    if (!remover(ptr_lista, 1)) {
        printf("Falha na remoção: Código 1 não removido.\n");
        liberarLista(ptr_lista);
        return 0;
    }
    printf("Sucesso na remoção: Código 1 removido. Nova lista:\n");
    imprimir(ptr_lista); 

    printf("\n[Remoção 2] Removendo último produto (Código 2 - Ovos)...\n");
    if (!remover(ptr_lista, 40)) {
        printf("Falha na remoção: Código 40 não removido.\n");
        liberarLista(ptr_lista);
        return 0;
    }
    printf("Sucesso na remoção: Código 40 removido. Nova lista:\n");
    imprimir(ptr_lista); 
    
    printf("\n[Remoção 3] Tentando remover produto inexistente (código 99)...\n");
    if (remover(ptr_lista, 99)) {
        printf("Falha na remoção: Removeu um código que não existe (99).\n");
        liberarLista(ptr_lista);
        return 0;
    }
    printf("Sucesso na remoção: Código 99 não removido (retornou 0).\n");
    
    liberarLista(ptr_lista);
    fclose(arquivo);
    return 1;
}