#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GerenciaProduto.h"

struct produto {
    int codigo;
    char nome[50];
    char categoria[30];
    int quantidade;
    float preco;
};

Produto* criar_produto(int codigo, const char* nome, const char* categoria, int quantidade, float preco) {
    Produto* ptr_p = malloc(sizeof(Produto));
    if (ptr_p != NULL) {
        ptr_p->codigo = codigo;
        strcpy(ptr_p->nome, nome);
        strcpy(ptr_p->categoria, categoria);
        ptr_p->quantidade = quantidade;
        ptr_p->preco = preco;
    }
    return ptr_p;
}

void liberar_produto(Produto* prt_p) {
    free(prt_p);
}

void imprimir_produto(const Produto* ptr_p) {
    if (ptr_p != NULL) {
        printf("Código: %d | Nome: %s | Categoria: %s | Quantidade: %d | Preço: R$ %.2f\n",
               ptr_p->codigo, ptr_p->nome, ptr_p->categoria, ptr_p->quantidade, ptr_p->preco);
    }
}

int get_codigo(const Produto* ptr_p) { return ptr_p->codigo; }
const char* get_nome(const Produto* ptr_p) { return ptr_p->nome; }
const char* get_categoria(const Produto* ptr_p) { return ptr_p->categoria; }
int get_quantidade(const Produto* ptr_p) { return ptr_p->quantidade; }
float get_preco(const Produto* ptr_p) { return ptr_p->preco; }

void set_quantidade(Produto* ptr_p, int novaQtd) { ptr_p->quantidade = novaQtd; }
void set_preco(Produto* ptr_p, float novoPreco) { ptr_p->preco = novoPreco; }
