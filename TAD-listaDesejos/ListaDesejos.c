#include <stdio.h>
#include <stdlib.h>
#include "../TAD-GerenciaProd/GerenciaProduto.h"
#include "../TAD-listaSeq/ListaProdutos.h"
#include "ListaDesejos.h"

struct lista_desejos {
    ListaProdutos* produtos;
};

ListaDesejos* inicializaListaDesejos(int capacidade) {
    ListaDesejos* ptr_ld = malloc(sizeof(ListaDesejos));
    if (ptr_ld == NULL) {
        return NULL;
    }

    ptr_ld->produtos = criaLista(capacidade);
    if (ptr_ld->produtos == NULL) {
        free(ptr_ld);
        return NULL;
    }

    return ptr_ld;
}

void adicionarProdutoListaDesejos(ListaDesejos* ptr_ld, Produto* ptr_p) {
    if (ptr_ld == NULL || ptr_p == NULL) return;

    if (!inserir(ptr_ld->produtos, ptr_p)) {
        printf("Não foi possível adicionar: lista de desejos cheia.\n");
    }
}

int removerProdutoListaDesejos(ListaDesejos* ptr_ld, int codigo) {
    if (ptr_ld == NULL) return 0;
    return remover(ptr_ld->produtos, codigo);
}

void imprimirListaDesejos(const ListaDesejos* ptr_ld) {
    if (ptr_ld == NULL || vazia(ptr_ld->produtos)) {
        printf("Lista de desejos vazia.\n");
        return;
    }

    printf("==== LISTA DE DESEJOS ====\n");
    imprimir(ptr_ld->produtos);
    printf("==========================\n");
}

int tamanhoListaDesejos(const ListaDesejos* ptr_ld) {
    if (ptr_ld == NULL) return 0;
    return tamanho(ptr_ld->produtos);
}

void liberarListaDesejos(ListaDesejos* ptr_ld) {
    if (ptr_ld == NULL) return;

    liberarLista(ptr_ld->produtos);
    free(ptr_ld);
}
