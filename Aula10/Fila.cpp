#include "Fila.h"
#include <iostream>
using namespace std;
Fila::Fila()
{
    inicio = NULL;
    fim = NULL;
}
Fila::~Fila()
{
    for(No *p=inicio; p!=NULL; p=p)
    {
        No *aux = p->getProx();
        delete p;
        p = aux;
    }
}
int Fila::getInicio()
{
    if(inicio != NULL)
    {
        return inicio->getVal();
    }
    else
    {
        cout << "fila vazia!" << endl;
        return -1;
    }
}
void Fila::enfileira(int val)
{
    No *p = new No;
    p->setVal(val);
    p->setProx(NULL);
    if(fim == NULL)
    {
        inicio = p;
    }
    else
    {
        fim->setProx(p);
    }
    fim = p;
}
int Fila::desenfileira()
{
    No* p;
    if(inicio != NULL)
    {
        p = inicio;
        inicio = p->getProx();
        if(inicio == NULL)
            fim = NULL;
        int val = p->getVal();
        delete p;
        return val;
    }
    else
    {
        cout << "ERRO: Fila Vazia!" << endl;
        exit(1);
    }
}
void Fila::concatenaInicio(Fila *f)
{
    if(!f->vazia())
    {
        f->fim->setProx(inicio);
        inicio = f->inicio;
        f->inicio = NULL;
        f->fim = NULL;
    }
}
void Fila::imprime()
{
    for(No *p=inicio; p!=NULL; p=p->getProx())
    {
        cout << p->getVal() << " ";
    }
    cout << endl;
}
bool Fila::vazia()
{
    return inicio == NULL;
}
