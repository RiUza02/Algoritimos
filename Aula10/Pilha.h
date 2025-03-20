#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "Nos.h"
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


#endif // PILHA_H_INCLUDED
