#include <iostream>
#include "ListaCircular.h"

ListaCircular::ListaCircular()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

NoDuplo* ListaCircular::insereNoApos(NoDuplo *p, int val)
{
    NoDuplo *Atual = new NoDuplo;
    Atual->setInfo(val);

    if(primeiro == NULL || ultimo == NULL)
    {
        Atual->setAnt(Atual);
        Atual->setProx(Atual);
        primeiro = Atual;
        ultimo = Atual;
    }
    else
    {
        if(p == ultimo)
        {
            primeiro->setAnt(Atual);
            Atual->setProx(primeiro);
            ultimo->setProx(Atual);
            Atual->setAnt(ultimo);
            ultimo = Atual;
        }
        else
        {
            NoDuplo *Prox = p->getProx();

            Atual->setProx(Prox);
            Prox->setAnt(Atual);
            Atual->setAnt(p);
            p->setProx(Atual);
        }
    }
    n++;
    return Atual;
}
void ListaCircular::insereInicio(int val)
{
    primeiro = insereNoApos(ultimo, val);
    ultimo = primeiro->getAnt();
}

void ListaCircular::imprime()
{
    std::cout << "Lista: ";
    int i=0;
    NoDuplo *p = primeiro;
    while(i<n)
    {
        std::cout << p->getInfo() << " ";
        p = p->getProx();
        i++;
    }
    std::cout << std::endl;
}
