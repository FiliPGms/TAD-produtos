#ifndef LISTA_DESEJOS_H
#define LISTA_DESEJOS_H

#include "../TAD-GerenciaProd/GerenciaProduto.h"

typedef struct lista_desejos ListaDesejos;

ListaDesejos* inicializaListaDesejos(int capacidade);
void adicionarProdutoListaDesejos(ListaDesejos* ptr_ld, Produto* ptr_p);
int removerProdutoListaDesejos(ListaDesejos* ptr_ld, int codigo);
void imprimirListaDesejos(const ListaDesejos* ptr_ld);
int tamanhoListaDesejos(const ListaDesejos* ptr_ld);
void liberarListaDesejos(ListaDesejos* ptr_ld);

#endif
