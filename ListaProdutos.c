#include <stdio.h>
#include <stdlib.h>
#include "ListaProdutos.h"

struct lista_produtos
{
    Produto** prods;
    int cap;
    int quantidade;
};

ListaProdutos* criaLista(int capacidade){
    ListaProdutos* ptr_l = malloc(sizeof(ListaProdutos));
    if(ptr_l != NULL){
        ptr_l->prods = malloc(capacidade * sizeof(Produto*));
        ptr_l->quantidade = 0;
        ptr_l->cap = capacidade;
    }else{
        return NULL;
    }
}

void liberarLista(ListaProdutos* ptr_lista){
    if(ptr_lista != NULL){
        free(ptr_lista->prods);
        free(ptr_lista);
    }
}

int cheia(ListaProdutos* ptr_lista){
    if(ptr_lista == NULL){
        return 0;
    }
    return ptr_lista->quantidade >= ptr_lista->cap;
}
int vazia(ListaProdutos* ptr_lista);
int tamanho(ListaProdutos* ptr_lista);
int capacidade(ListaProdutos* ptr_lista);


int inserir(ListaProdutos* ptr_lista, Produto* ptr_p){
    if(cheia(ptr_lista)){
        return 0;
    }
    ptr_lista->prods[ptr_lista->quantidade++] = ptr_p;
    return 1;
}
