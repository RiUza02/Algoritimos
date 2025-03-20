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
    ultimo = NULL;
    n=0;
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
int Lista::get(int k)
{
    if(k < n && k > 0)
    {
        No *p;

        p = primeiro;
        for(int i=1; i<k; i++)
        {
            p = p->getProx();
        }
        return p->getVal();
    }
    else
    {
        return -1;
        cout << endl << "item invalido ou lista vazia" << endl;
    }
}
void Lista::set(int val, int k)
{
    if(k < n && k > 0)
    {
        No *p;

        p = primeiro;
        for(int i=1; i<k; i++)
        {
            p = p->getProx();
        }
        p->setVal(val);
    }
    else
    {
        cout << endl << "item invalido ou lista vazia" << endl;
    }
}
void Lista::insereOrdenado(int val)
{
    if(n<=0)
    {
        insereFinal(val);
    }
    else
    {
        if(ultimo->getVal()<val)
        {
            insereFinal(val);
        }
        else
        {
            cout << "valor invalido" << endl;
        }
    }
}
void Lista::insereInicio(int val)
{
    n++;

    No* p = new No();
    p->setVal(val);
    p->setProx(primeiro);

    primeiro = p;
    if(n==1)
    {
        ultimo = primeiro;
    }
}
void Lista::insereFinal(int val)
{
    n++;

    No *p = new No();
    p->setVal(val);
    p->setProx(NULL);

    if(n == 1)
    {
        primeiro=p;
    }
    else
    {
        ultimo->setProx(p);
    }
    ultimo = p;
}
void Lista::insereK(int Val, int k)
{
    if(k==1)
    {
        cout << endl <<"para inserir no inicio da lista, por favor use o comando .insereInicio" << endl;
    }
    else
    {
        if(k==n+1)
        {
            cout << endl <<"para inserir no final da lista, por favor use o comando .insereFinal" << endl;
        }
        else
        {
            if(k > 0 && k < QNos()+1)
            {
                n++;

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
            else
            {
                cout << "Posição invalida" << endl;
            }
        }
    }

}
void Lista::removeInicio()
{
    if(n>0)
    {
        n--;

        No *t = primeiro;
        primeiro = primeiro->getProx();

        if(n==0)
        {
            ultimo == NULL;
        }
        delete t;
    }
    else
    {
        cout << "Lista vazia" << endl;
    }

}
void Lista::removeFinal()
{
    if(n>0)
    {
        n--;

        No *pNult;
        for(No *p=primeiro; p->getProx()!=NULL; p=p->getProx())
        {
            pNult = p;
        }

        pNult->setProx(NULL);
        delete ultimo;
        ultimo = pNult;
    }
    else
    {
        cout << "Lista vazia" << endl;
    }


}
void Lista::removek(int k)
{
    if(k==1)
    {
        cout << endl <<"para remover no inicio da lista, por favor use o comando .removeInicio" << endl;
    }
    else
    {
        if(k==n)
        {
            cout << endl <<"para remover no final da lista, por favor use o comando .removeFinal" << endl;
        }
        else
        {
            if(k > 0 && k < QNos())
            {
                n--;

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
            else
            {
                cout << "Posição invalida" << endl;
            }
        }
    }
}
int Lista::QNos()
{
    return n;
}
void Lista::imprime()
{
    for(No *p=primeiro; p!=NULL; p=p->getProx())
    {
        cout << p->getVal() << " ";
    }
    cout << endl;
}


int Lista::buscaMaior(int val)
{
    int n=0;
    for(No *p=primeiro; p!=NULL; p=p->getProx(), n++)
    {
        if(p->getVal()>val)
        {
            return n;
        }
    }
    return -1;
}
void Lista::limpar()
{
    for(No *p=primeiro; p!=NULL; p=p)
    {
        No *t = p->getProx();
        delete p;
        p=t;
    }
    primeiro = NULL;
    ultimo = NULL;
    n=0;
}
float Lista::calculaMedia()
{
    float media=0;
    for(No *p=primeiro; p!=NULL; p=p->getProx())
    {
        media = media + p->getVal();
    }
    return media/n;
}
void Lista::concatena(Lista *l2)
{
    for(int i=0; i<l2->QNos(); i++)
    {
        insereFinal(l2->get(i+1));
    }
}
Lista* Lista::partir(int k)
{
    No *p = primeiro;
    for(int i=1; i<k; i++)
    {
        p = p->getProx();
    }

    Lista *L = new Lista;
    for(int i=0; i<(n-k)+1; i++)
    {
        L->insereFinal(p->getVal());
        p = p->getProx();
    }
    return L;
}
