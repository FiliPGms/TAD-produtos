
typedef struct produto Produto;
typedef struct lista_desejos listaDesejos;


Produto* criarProduto(const char* nome, const char* categoria, int codigo, float preco);
float aplicarDesconto(Produto* ptr_p, float percentual);
void imprimirProduto(const Produto* ptr_p);
int listaDes(listaDesejos* ptr_l,Produto* ptr_p);

int getCodigo(const Produto* ptr_p);
const char* getNome( const Produto* ptr_p);
const char* getCategoria(const Produto* ptr_p);
float getPreco( const Produto * ptr_p);
int getQuantidade(const Produto* ptr_p);

void setQuantidade(Produto* p, int novaQtd);
void setPreco(Produto* p, float novoPreco);
 