#include <iostream>
#include "Aula7.1.h"
using namespace std;

Lista::Lista()
{
    primeiro = NULL;
}
Lista::~Lista()
{
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}
void Lista::insere(int val)
{
    No *p = new No();
    p->setInfo(val);

    No *ants, *atual;
    for(ants=primeiro; ants != NULL, ants->getInfo(ants->getProx()) <= val; ants=ants->getProx())
    {

    }

}
/*
No *ant = NULL, *atual = primeiro;
    No *p = new No();
    p->setInfo(val);
    while(atual != NULL && val >= atual->getInfo())
    {
        ant = atual;
        atual = atual->getProx();
    }
    if(ant == NULL)
    {
        p->setProx(primeiro);
        primeiro = p;
    }
    else
    {
        ant->setProx(p);
        p->setProx(atual);
    }
     */
bool Lista::busca(int val)
{
    for(No *p = primeiro; p != NULL; p = p->getProx())
    {
        if(p->getInfo() == val)
           {
               return true;
           }
    }
    return false;
}
void Lista::imprime()
{
   for(No *p = primeiro; p != NULL; p = p->getProx())
    {
        cout << p->getInfo() << " ";
    }
    cout << endl;
}
