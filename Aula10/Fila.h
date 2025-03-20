#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "Nos.h"
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
#endif // FILA_H_INCLUDED
