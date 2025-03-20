#include <iostream>
#include "PilhaEncad.h"

using namespace std;

PilhaEncad::PilhaEncad()
{
    topo = NULL;
}

PilhaEncad::~PilhaEncad()
{
    No *p = topo;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

int PilhaEncad::getTopo()
{
    if(topo != NULL)
        return topo->getInfo();
    else
    {
        cout << "ERRO: Pilha vazia." << endl;
        exit(1);
    }
}

void PilhaEncad::empilha(int val)
{
    No *p = new No(); // cria No apontado por p
    p->setInfo(val); // preenche informacao
    p->setProx(topo); // preenche proximo
    topo = p; // no apontado por p passa a ser o topo da pilha
}

int PilhaEncad::desempilha()
{
    if(topo != NULL)
    {
        No *p = topo; // p aponta para o No a ser excluido
        topo = p->getProx(); // topo passa a apontar p/ atual segundo
        int val = p->getInfo(); // auxiliar
        delete p;
        return val;
    }
    else
    {
        cout << "ERRO: Pilha Vazia!" << endl;
        exit(6);
    }
}

bool PilhaEncad::vazia()
{
    return topo == NULL;
}

void PilhaEncad::imprime()
{
    cout << "Pilha: ";
    for(No *p = topo; p != NULL; p = p->getProx())
        cout << p->getInfo() << " ";
    cout << endl;
}
