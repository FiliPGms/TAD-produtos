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

struct lista_desejos
{
    listaDesejos** lista;
    
};


Produto* criarProduto(int codigo, const char* nome, const char* categoria, int quantidade, float preco) {
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



float aplicarDesconto(Produto* ptr_p, float percentual){
    ptr_p->preco-=ptr_p->preco*percentual;
    return ptr_p->preco;
}

int listaDes(listaDesejos* ptr_l,Produto* ptr_p){
    

}



void imprimirProduto(const Produto* ptr_p) {
    if (ptr_p != NULL) {
        printf("Código: %d | Nome: %s | Categoria: %s | Quantidade: %d | Preço: R$ %.2f\n",
               ptr_p->codigo, ptr_p->nome, ptr_p->categoria, ptr_p->quantidade, ptr_p->preco);
    }
}

int getCodigo(const Produto* ptr_p) { return ptr_p->codigo; }
const char* getNome(const Produto* ptr_p) { return ptr_p->nome; }
const char* getCategoria(const Produto* ptr_p) { return ptr_p->categoria; }
int getQuantidade(const Produto* ptr_p) { return ptr_p->quantidade; }
float getPreco(const Produto* ptr_p) { return ptr_p->preco; }

void setQuantidade(Produto* ptr_p, int novaQtd) { ptr_p->quantidade = novaQtd; }
void setPreco(Produto* ptr_p, float novoPreco) { ptr_p->preco = novoPreco; }
