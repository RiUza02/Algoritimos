#include <iostream>
#include "Aula9.h"
using namespace std;
int* inverte(int *vet, int n)
{
    int *nvet = new int [n];
    for(int x=0, y=n-1; x<n; x++, y--)
    {
        nvet[y] = vet[x];
    }
    return nvet;
}
void inverteFila(Fila *f)
{
    Pilha *aux = new Pilha;
    int x;
    while(!f->vazia())
    {
        x++;
        aux->empilha(f->desenfileira());
    }
    while(x>0)
    {
        f->enfileira(aux->desempilha());
        x--;
    }
    delete aux;
}
Fila* concatena(Fila *f1, Fila *f2)
{
    Fila *nf = new Fila;
    while(!f1->vazia())
    {
        nf->enfileira(f1->desenfileira());
    }
    while(!f2->vazia())
    {
        nf->enfileira(f2->desenfileira());
    }
    return nf;
}
void removeDaPilha(Pilha *p, int x)
{
    Pilha *pAux = new Pilha;
    int n;
    while(!p->vazia())
    {
        n = p->desempilha();
        if(n != x)
        {
            pAux->empilha(n);
        }
    }
    while(!pAux->vazia())
        p->empilha(pAux->desempilha());
    delete pAux;
}
int main()
{
    return 0;
}
