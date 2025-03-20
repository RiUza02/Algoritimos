#include <iostream>
#include "Aula6.h"
using namespace std;

No::No()
{

}
No::~No()
{

}
int No::getVal()
{
    return val;
}
No* No::getProx()
{
    return prox;
}
void No::setVal(int x)
{
    val = x;
}
void No::setProx(No *p)
{
    prox = p;
}
//-----------------------------------------------------------------------------------------------------------------
Lista::Lista()
{
    primeiro = NULL;
}
Lista::~Lista()
{
    for(No *p=primeiro; p!=NULL; p=p)
    {
        No *t = p->getProx();
        delete p;
        p=t;
    }
}
void Lista::insereInicio(int val)
{
    No* p = new No();
    p->setVal(val);
    p->setProx(primeiro);
    primeiro = p;
}
void Lista::insereFinal(int val)
{
    No* t = new No();
    t->setVal(val);

    No *p2;
    for(No *p=primeiro; p!=NULL; p=p->getProx())
    {
        p2 = p;
    }
    p2->setProx(t);
    t->setProx(NULL);
}
void Lista::insereK(int Val, int k)
{
    if(k > 0 && k < QNos())
    {
        No *p = new No;
        No *pAnts, *pDeps;

        pDeps = primeiro;
        pAnts = primeiro;

       for(int i=1; i<k; i++)
       {
           if(i==k-1)
            pAnts=pDeps;
           pDeps = pDeps->getProx();
       }

       pAnts->setProx(p);
       p->setProx(pDeps);
       p->setVal(Val);
    }
}
void Lista::removeInicio()
{
    No *t = primeiro;
    primeiro = primeiro->getProx();
    delete t;
}
void Lista::removeFinal()
{
    No *pNult;
    No *pUlt;

    for(No *p=primeiro; p->getProx()!=NULL; p=p->getProx())
    {
        pNult = p;
    }
    for(No *p=primeiro; p!=NULL; p=p->getProx())
    {
        pUlt = p;
    }
    pNult->setProx(NULL);
    delete pUlt;
}
void Lista::removek(int k)
{
    if(k > 0 && k < QNos())
    {
        No *pAnts, *p;
        p = primeiro;

       for(int i=1; i<k; i++)
       {
           if(i==k-1)
            pAnts=p;
           p = p->getProx();
       }
       pAnts->setProx(p->getProx());
       delete p;
    }
}
int Lista::QNos()
{
    int x;
    for(No *p=primeiro; p!=NULL; p=p->getProx())
    {
        x++;
    }
    return x;
}
void Lista::imprime()
{
    for(No *p=primeiro; p!=NULL; p=p->getProx())
    {
        cout << p->getVal() << " ";
    }
    cout << endl;
}
