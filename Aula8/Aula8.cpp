#include <iostream>
#include "Aula8.h"
using namespace std;
NoDuplo::NoDuplo() { }
NoDuplo::~NoDuplo() { }
void NoDuplo::setAnt(NoDuplo *p)
{
    ant = p;
}
void NoDuplo::setProx(NoDuplo *p)
{
    prox = p;
}
void NoDuplo::setInfo(int val)
{
    info = val;
}
NoDuplo* NoDuplo::getAnt()
{
    return ant;
}
NoDuplo* NoDuplo::getProx()
{
    return prox;
}
int NoDuplo::getInfo()
{
    return info;
}
//----------------------------------------------------------------------------------------------------------------------------------

ListaDupla::ListaDupla()
{
    primeiro = NULL;
    ultimo = NULL;
    n=0;
}
ListaDupla::~ListaDupla()
{
    for(NoDuplo *p=primeiro; p!=NULL; p=p)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p=t;
    }
}
void ListaDupla::insereInicio(int val)
{
    n++;

    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setAnt(NULL);
    if(primeiro == NULL)
    {
        p->setProx(NULL);
        primeiro = p;
        ultimo = p;
    }
    else
    {
        primeiro->setAnt(p);
        p->setProx(primeiro);
        primeiro = p;
    }
}
void ListaDupla::removeInicio()
{
    NoDuplo *p = primeiro;
    p = p->getProx();

    delete primeiro;
    p->setAnt(NULL);
    primeiro = p;

}
void ListaDupla::insereFinal(int val)
{
    n++;

    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(NULL);
    if(ultimo == NULL)
    {
        p->setAnt(NULL);
        ultimo = p;
        primeiro = p;
    }
    else
    {
        ultimo->setProx(p);
        p->setAnt(ultimo);
        ultimo = p;
    }
}
void ListaDupla::removeFinal()
{
    NoDuplo *p = ultimo;
    p = p->getAnt();

    delete ultimo;
    p->setProx(NULL);
    ultimo = p;
}
void ListaDupla::removeMaior()
{
    if(primeiro == NULL)
    {
        cout << "Lista Vazia" << endl;
    }
    else
    {
        if(primeiro == ultimo)
        {
            delete primeiro;
            primeiro = NULL;
            ultimo = NULL;
        }
        else
        {
            int i = primeiro->getInfo();
            NoDuplo *Maior;
            for(NoDuplo *p=primeiro; p!=NULL; p=p->getProx())
            {
                if(p->getInfo() > i)
                {
                    Maior = p;
                    i = p->getInfo();
                }
            }
            if(Maior == primeiro)
            {
                removeInicio();
            }
            else
            {
                if(Maior == ultimo)
                {
                    removeFinal();
                }
                else
                {
                    NoDuplo *prox, *Ant;
                    prox = Maior->getProx();
                    Ant = Maior->getAnt();
                    Ant->setProx(Maior->getProx());
                    prox->setAnt(Maior->getAnt());
                    delete Maior;
                }
            }
        }
    }
}
void ListaDupla::removePares()
{
    if(primeiro == NULL)
    {
        cout << "Lista Vazia" << endl;
    }
    else
    {
        NoDuplo *Par;
        for(NoDuplo *p=primeiro; p!=NULL; p=p->getProx())
        {
            if(p->getInfo()%2==0)
            {
                Par = p;
                if(Par == primeiro)
                {
                    removeInicio();
                }
                else
                {
                    if(Par == ultimo)
                    {
                        removeFinal();
                    }
                    else
                    {
                        NoDuplo *prox, *Ant;
                        prox = Par->getProx();
                        Ant = Par->getAnt();
                        Ant->setProx(Par->getProx());
                        prox->setAnt(Par->getAnt());
                        delete Par;
                    }
                }
            }
        }
    }
}
void ListaDupla::insereAntes(float val, float x)
{
    NoDuplo *Atual, *Ants, *Prox;
    for(NoDuplo *p=primeiro; p!=NULL; p=p->getProx())
    {
        if(p->getInfo() == x)
        {

            if(p == primeiro)
            {
                insereInicio(val);
            }
            else
            {
                Atual = new NoDuplo();
                Atual->setInfo(val);
                Prox = p;
                Ants = p->getAnt();
                Atual->setAnt(Ants);
                Ants->setProx(Atual);
                Atual->setProx(Prox);
                Prox->setAnt(Atual);
            }
        }
    }
}
void ListaDupla::imprime()
{
    for(NoDuplo *p=primeiro; p!=NULL; p=p->getProx())
    {
        cout << p->getInfo() << " ";
    }
    cout << endl;
}
void ListaDupla::imprimeReverso()
{
    for(NoDuplo *p=ultimo; p!=NULL; p=p->getAnt())
    {
        cout << p->getInfo() << " ";
    }
    cout << endl;
}
