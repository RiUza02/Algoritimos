#ifndef AULA9_H_INCLUDED
#define AULA9_H_INCLUDED

class No
{
public:
    No();
    ~No();
    int getVal();
    No* getProx();
    void setVal(int x);
    void setProx(No *p);
private:
    int val;
    No *prox;
};
//--------------------------------------------------------------------------------------------------------------------------------------

class Pilha
{
private:
    No *topo;
public:
    Pilha();
    ~Pilha();
    int getTopo();
    void empilha(int val);
    int desempilha();
    void imprime();
    bool vazia();
    int tamanho();
};

class Fila
{
private:
    No *inicio;
    No *fim;
public:
    Fila();
    ~Fila();
    int getInicio();
    void enfileira(int val);
    int desenfileira();
    void concatenaInicio(Fila *f);
    void imprime();
    bool vazia();
};
#endif // AULA9_H_INCLUDED
