#ifndef LISTA_DESEJOS_H
#define LISTA_DESEJOS_H
#include "../TAD-GerenciaProd/GerenciaProduto.h"

typedef struct lista_desejos ListaDesejos;

ListaDesejos* inicializaListaDesejos(int capacidade);
void liberarListaDesejos(ListaDesejos* ptr_ld);
void adicionarProdutoListaDesejos(ListaDesejos* ptr_ld, Produto* ptr_p);
void imprimir(const ListaDesejos* ptr_ld);


#endif