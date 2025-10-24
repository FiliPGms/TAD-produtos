#ifndef LISTA_PRODUTOS_H
#define LISTA_PRODUTOS_H
#include "GerenciaProduto.h"

typedef struct lista_produtos ListaProdutos;

ListaProdutos* criaLista(int capacidade);
void liberarLista(ListaProdutos* ptr_lista);

int inserir(ListaProdutos* ptr_lista, Produto* ptr_p);
int remover(ListaProdutos* ptr_lista, int codigo);
int buscar(ListaProdutos* ptr_lista, int codigo);
Produto* obter(ListaProdutos* ptr_lista, int codigo);

int cheia(ListaProdutos* ptr_lista);
int vazia(ListaProdutos* ptr_lista);
int tamanho(ListaProdutos* ptr_lista);
int capacidade(ListaProdutos* ptr_lista);

void imprimir(ListaProdutos* ptr_lista);


#endif


