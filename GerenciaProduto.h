#ifndef PRODUTO_H
#define PRODUTO_H


typedef struct produto Produto;

Produto* criarProduto(const char* nome, const char* categoria, int codigo, float preco);
void aplicarDesconto(Produto* ptr_p, float percentual);
void liberar_produto(Produto* p);
void imprimir_produto(const Produto* p);
int getCodigo(const Produto* ptr_p);
const char* getNome( const Produto* ptr_p);
const char* getCategoria(const Produto* ptr_p);
float getPreco( const Produto * ptr_p);
int get_quantidade(const Produto* p);

void set_quantidade(Produto* p, int novaQtd);
void set_preco(Produto* p, float novoPreco);

#endif 