#include <iostream>
#include "Aula9.h"
Pilha::Pilha()
{
    topo = NULL;
}
Pilha::~Pilha()
{
    for(No *p=topo; p!=NULL; p=p)
    {
        No *aux = p->getProx();
        delete p;
        p = aux;
    }
}
int Pilha::getTopo()
{
    if(topo != NULL)
    {
        return topo->getVal();
    }
    else
    {
        cout << "lista vazia!" << endl;
        return -1;
    }
}
void Pilha::empilha(int val)
{
   No *p = new No(); // cria No apontado por p
    p->setVal(val); // preenche informacao
    p->setProx(topo); // preenche proximo
    topo = p;
}
int Pilha::desempilha()
{
     if(topo != NULL)
    {
        No *p = topo; // p aponta para o No a ser excluido
        topo = p->getProx(); // topo passa a apontar p/ atual segundo
        int val = p->getVal(); // auxiliar
        delete p;
        return val;
    }
    else
    {
        cout << "ERRO: Pilha Vazia!" << endl;
        exit(6);
    }

}
void Pilha::imprime()
{
    for(No *p=topo; p!=NULL; p=p->getProx())
    {
        cout << p->getVal() << " ";
    }
    cout << endl;
}
bool Pilha::vazia()
{
    return topo == NULL;
}
int Pilha::tamanho()
{
    int x;
    for(No *p=topo; p!=NULL; p=p->getProx())
    {
        x++;
    }
    return x;
}



//-----------------------------------------------------------------------------------------------------------------------



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
