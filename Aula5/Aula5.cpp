#include <iostream>
#include "Aula5.h"
using namespace std;

lista::lista(int x)
{
    vet = new int [x];
    max = x;
    n=0;
}
lista::~lista()
{
    delete [] vet;
}
int lista::get(int k)
{
    if(n<=0)
    {
        cout << "lista vazia" << endl;
        return -1;
    }
    else
    {
     return vet[k];
    }
}
void lista::set(int k,int x)
{
    if(k>=0 && k<n)
    {
        vet[k] = x;
    }
    else
    {
        cout << "elemento da lista ainda invalido para modificação" << endl;
    }
}
void lista::insertF(int x)
{
    if(n>=max)
    {
        cout << "Lista cheia" << endl;

    }
    else
    {
        n++;
        vet[n] = x;
    }
}
void lista::RemoveF()
{
    if(n<0)
    {
        cout << "lista vazia" << endl;

    }
    else
    {
        n--;
    }

}
void lista::insertI(int x)
{
    if(n>=max)
        {
            cout << "lista cheia" << endl;
        }
        else
        {
            for(int i=n; i>=0; i--)
            {
                vet[i+1] = vet[i];
            }
            vet[1] = x;
            n++;
        }
}
void lista::removeI()
{
    if(n<=0)
        {
            cout << "lista vazia" << endl;
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                vet[i] = vet[i+1];
            }
            n--;
        }
}
void lista::insertk(int k,int x)
{
    if(n >= max)
    {
        cout << "lista cheia" << endl;
    }
    else
    {
        if(k>=0 && k<n)
        {
            for(int i=n; i>k; i--)
            {
                vet[i] = vet[i-1];
            }
            vet[k] = x;
            n++;
        }
        else
        {
            cout << "elemento da lista invalido" << endl;
        }
    }
}
void lista::Removek(int k)
{
        if(k>=0 && k<n)
        {
            for(int i=k; i>=n; i++)
            {
                vet[i] = vet[i+1];
            }
            n--;
        }
        else
        {
            cout << "elemento da lista invalido" << endl;
        }
}

void lista::numNos()
{
    cout << n << endl;
}

void lista::insereValores(int tam, int vet[])
{
}

void lista::AlocaMeio(lista a, lista b, lista c)
{
    int i;
    i = n/2;
    for(int x=0; x<i; x++)
    {
        b.insertF(a.get(x+1));
        cout << b.get(x+1) << " ";

    }
    cout << endl;
    for(int x=i, y=0; x<n; x++, y++)
    {
        c.insertF(a.get(x+1));
        cout << c.get(y+1) << " ";
    }
}
