#include <iostream>
#include "Aula7.h"
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
    if(k>=0 && k<n)
    {
        cout << "Elemento Invalido" << endl;
        return -1;
    }
    else
    {
     return vet[k];
    }
}
void lista::set(int x)
{
    if(n==max)
    {
        cout << "lista cheia" << endl;
    }
    else
    {
        int i;
        cout << "indice n: "<< n << endl;
        cout << "valor x: "<< x << endl;
        for(i = n-1; i > 0 && vet[i]>=x; i--)
        {
            vet[i+1] = vet[i];
        }
        cout << "indice i: "<< i << endl;
        vet[i+1] = x;
        cout << "valor de i no vetor: "<< vet[i] << endl;
        cout << "valor de n no vetor: "<< vet[n] << endl;
        n++;
    }
}
void lista::remove(int x)
{
    if(buscaBinaria(x) == -1)
    {
        cout << "valor não encontrado" << endl;
    }
    else
    {
        for(int i=buscaBinaria(x); i<n; i++)
        {
            vet[i] = vet[i+1];
        }
        n--;
    }
}
void lista::imprime()
{
    for(int i = 0; i < n; i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;
}
int lista::buscaBinaria(int val)
{
    int esq = 0;
    int dir = n-1;
    while(esq <= dir)
    {
        int meio = (esq + dir) / 2;
        if(val > vet[meio]) // se existir, val esta na segunda metade
            esq = meio + 1;
        else if (val < vet[meio]) // se existir, val esta na primeira metade
            dir = meio - 1;
        else
            return meio; // val na posicao meio
    }
    return -1; // val nao encontrado
}
