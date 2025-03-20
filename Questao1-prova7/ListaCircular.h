#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include "NoDuplo.h"

class ListaCircular
{
    public:
    ListaCircular();
    void imprime();
    void insereInicio(int val);
    bool vazia(){return n==0;}
private:
    NoDuplo *primeiro;
    int n;
    NoDuplo *ultimo;
    NoDuplo* insereNoApos(NoDuplo *p, int val);
};

#endif // LISTACIRCULAR_H
