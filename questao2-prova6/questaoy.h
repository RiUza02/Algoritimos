#ifndef QUESTAOY_H_INCLUDED
#define QUESTAOY_H_INCLUDED
class No
{
private:
    int info; /// valor armazenado no No
    No *prox; /// ponteiro para o proximo No
public:
    No()                  { };
    ~No()                 { };
    int getInfo()         { return info; };
    No* getProx()         { return prox; };
    void setInfo(int val) { info = val; };
    void setProx(No *p)   { prox = p; };
};
class ListaEncad
{
public:
    ListaEncad();
    ~ListaEncad();
    bool busca(int val);        /// retorna true caso val esteja na lista e false caso contrario
    int get(int k);             /// retorna o valor do k-ésimo elemento
    void set(int k, int val);   /// altera o valor do k-ésimo elemento
    void insereInicio(int val); /// insere um novo No contendo val no início da lista
    void insereFinal(int val);  /// insere um novo No contendo val no final da lista
    void removeInicio();        /// remove o primeiro No da lista
    void removeFinal();         /// remove o último No da lista
    void removeDepoisMaior();
    void imprime();

private:
    No *primeiro;  /// ponteiro para o primeiro No da lista
    No *ultimo;    /// ponteiro para o ultimo No da lista
    int n;         /// numero de nos na lista
};

#endif // QUESTAOY_H_INCLUDED
