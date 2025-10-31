#include <stdio.h>
#include <stdlib.h>
#include "ListaDesejos.h"
#include "TAD-produtos/GerenciaProduto.c"

struct lista_desejos
{
    Produto** produtos;
    int tamanho;
    int cap;
    
};

ListaDesejos* inicializaListaDesejos(int capacidade){
    ListaDesejos* ptr_ld = malloc(sizeof(ListaDesejos));
    ptr_ld->produtos = malloc(capacidade * sizeof(Produto*));
    if (ptr_ld->produtos == NULL) {
        free(ptr_ld);
        return NULL;
    }
    ptr_ld->tamanho = 0;
    ptr_ld->cap = capacidade;
    
    return ptr_ld;
}

void adicionarProdutoListaDesejos(ListaDesejos* ptr_ld, Produto* ptr_p) {
    if (ptr_ld->tamanho == ptr_ld->cap) {
        ptr_ld->cap *= 2;
        ptr_ld->produtos = realloc(ptr_ld->produtos, ptr_ld->cap * sizeof(Produto*));
    }

    ptr_ld->produtos[ptr_ld->tamanho] = ptr_p;
    ptr_ld->tamanho++;
}

void liberarListaDesejos(ListaDesejos* ptr_ld) {
    free(ptr_ld->produtos);
    free(ptr_ld);
}

void imprimir(const ListaDesejos* ptr_ld){
    if (!ptr_ld || ptr_ld->tamanho == 0) {
        printf("Lista de desejos vazia.\n");
        return;
    }

    for (int i = 0; i < ptr_ld->tamanho; i++){
        printf("%d - %s (R$%.2f)\n", i + 1, ptr_ld->produtos[i]->nome, ptr_ld->produtos[i]->preco);
    }
}



