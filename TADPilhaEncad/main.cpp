#include <iostream>
#include "PilhaEncad.h"

using namespace std;

PilhaEncad* copia(PilhaEncad *p)
{
    PilhaEncad *nova = new PilhaEncad();
    PilhaEncad *aux = new PilhaEncad();

    while(!p->vazia())
        aux->empilha(p->desempilha());

    while(!aux->vazia())
    {
        int val = aux->desempilha();
        p->empilha(val);
        nova->empilha(val);
    }
    delete aux;
    return nova;
}

void concatena(PilhaEncad *p1, PilhaEncad *p2)
{
    PilhaEncad *aux = new PilhaEncad();
    while(!p2->vazia())
        aux->empilha(p2->desempilha());
    while(!aux->vazia())
        p1->empilha(aux->desempilha());
    delete aux;
}

int main()
{
    PilhaEncad p1, p2, *p3;
    p1.empilha(1);
    p1.empilha(2);
    p1.empilha(3);
    p1.empilha(4);
    p1.imprime();

    p2.empilha(5);
    p2.empilha(6);
    p2.empilha(7);
    p2.imprime();

    concatena(&p1, &p2);
    p1.imprime();
    p2.imprime();

    p3 = copia(&p1);
    p1.imprime();
    p3->imprime();
    delete p3;

    return 0;
}
