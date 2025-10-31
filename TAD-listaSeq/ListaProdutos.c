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
    ListaProdutos* ptr_l = (ListaProdutos*)malloc(sizeof(ListaProdutos));
    if(ptr_l != NULL){
        ptr_l->prods = (Produto**)malloc(capacidade * sizeof(Produto*));
        ptr_l->quantidade = 0;
        ptr_l->cap = capacidade;
        return ptr_l;
    }else{
        free(ptr_l);
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
int vazia(ListaProdutos* ptr_lista){
    if(ptr_lista == NULL){
        return 1;
    }else{
        return ptr_lista->quantidade == 0;
    }
}
int tamanho(ListaProdutos* ptr_lista){
    if(ptr_lista != NULL){
        return ptr_lista->quantidade;
    }
}
int capacidade(ListaProdutos* ptr_lista){
    if(ptr_lista != NULL){
        return ptr_lista->cap;
    }
}


int inserir(ListaProdutos* ptr_lista, Produto* ptr_p){
    if(cheia(ptr_lista)){
        return 0;
    }
    ptr_lista->prods[ptr_lista->quantidade++] = ptr_p;
    return 1;
}

void imprimir(ListaProdutos* ptr_lista){
    if (ptr_lista == NULL || ptr_lista->quantidade == 0) {
        printf("Lista vazia ou inválida.\n");
        return;
    }
    printf("Lista de Contas Bancárias:\n");
    for (int i = 0; i < ptr_lista->quantidade; i++) {
        Produto *ptr_p = (*ptr_lista).prods[i];
        printf("Conta [%d] ", i + 1);
        imprimirProduto(ptr_p);
    }
}

Produto* obter(ListaProdutos* ptr_lista, int codigo){
    if(ptr_lista == NULL || ptr_lista->quantidade ==0){
        return NULL;
    }

    for(int i=0;i<ptr_lista->quantidade;i++){
        Produto* ptr_p = ptr_lista->prods[i];
        if(getCodigo(ptr_p) == codigo){
            return ptr_p;
        }
    }
    return NULL;
}

int buscar(ListaProdutos* ptr_lista, int codigo){
    if(ptr_lista == NULL || ptr_lista->quantidade ==0){
        return -1;
    }

    for(int i=0;i<ptr_lista->quantidade;i++){
        Produto* ptr_p = ptr_lista->prods[i];
        if(getCodigo(ptr_p) == codigo){
            return i;
        }
    }
    return -1;
}

int remover(ListaProdutos* ptr_lista, int codigo){
    if(ptr_lista == NULL || ptr_lista->quantidade==0){
        return 0;
    }

    for(int i=0;i<ptr_lista->quantidade;i++){
        Produto* ptr_p = ptr_lista->prods[i];
        if(getCodigo(ptr_p) == codigo){
            for(int j=i;j<ptr_lista->quantidade - 1; j++){
                ptr_lista->prods[j] = ptr_lista->prods[j+1];
            }
            ptr_lista->quantidade--;
            return 1;
        }
    }
    return 0;
}


