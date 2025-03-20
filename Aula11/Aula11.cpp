#include <iostream>
#include <stdlib.h>
#include <tgmath.h>
#include "Aula11.h"
using namespace std;
ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca()
{
    libera(raiz);
    raiz = NULL;
}

void ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        libera(p->getEsq());
        libera(p->getDir());
        delete p;
    }
}
bool ArvBinBusca::ehFolha(NoArv *p)
{
    if(p->getDir()==NULL && p->getEsq()==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int ArvBinBusca::contaNos()
{
    int n;
    auxContaNos(raiz, &n);
    return n;
}
void ArvBinBusca::auxContaNos(NoArv *p, int *n)
{
    if(p != NULL)
    {
        auxContaNos(p->getEsq(), n);
        auxContaNos(p->getDir(), n);
        *n = *n + 1;
    }
}
int ArvBinBusca::getRaiz()
{
    if(raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Arvore vazia!" << endl;
    }
    return -1;
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

void ArvBinBusca::imprime()
{
    imprimePorNivel(raiz, 0);
}

void ArvBinBusca::imprimePorNivel(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "-----";
        cout << p->getInfo() << endl;
        imprimePorNivel(p->getEsq(), nivel+1);
        imprimePorNivel(p->getDir(), nivel+1);
    }
}
void ArvBinBusca::imprimeMaior(int x)
{
    auxImprimeMaior(raiz, x);
    cout << endl;
}
void ArvBinBusca::auxImprimeMaior(NoArv *p, int x)
{
    if(p != NULL)
    {
        if(p->getInfo() > x)
        {
            auxImprimeMaior(p->getEsq(), x);
            cout << p->getInfo() << " ";
            auxImprimeMaior(p->getDir(), x);
        }
        else
        {
            auxImprimeMaior(p->getDir(), x);
        }
    }
}
void ArvBinBusca::imprimeMenor(int x)
{
    auxImprimeMenor(raiz, x);
    cout << endl;
}
void ArvBinBusca::auxImprimeMenor(NoArv *p, int x)
{
    if(p != NULL)
    {
        if(p->getInfo() < x)
        {
            auxImprimeMenor(p->getEsq(), x);
            cout << p->getInfo() << " ";
            auxImprimeMenor(p->getDir(), x);
        }
        else
        {
            auxImprimeMenor(p->getEsq(), x);
        }
    }
}
bool ArvBinBusca::buscaIt(int val)
{
    NoArv *p = raiz;
    while(p != NULL)
    {
        if(p->getInfo() == val)
            return true;
        else if(val < p->getInfo())
            p = p->getEsq();
        else
            p = p->getDir();
    }
    return false;
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}

NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}

int ArvBinBusca::minimo()
{
    if(raiz == NULL)
    {
        cout << "ERRO: Arvore vazia" << endl;
        exit(1);
    }
    return auxMin(raiz);
}

int ArvBinBusca::auxMin(NoArv *p)
{
    if(p != NULL)
    {
        if(p->getEsq() == NULL)
            return p->getInfo();
        else
            return auxMin(p->getEsq());
    }
    return -1;
}
int ArvBinBusca::maximo()
{
    return auxMax(raiz);
}
int ArvBinBusca::auxMax(NoArv *p)
{
    if(p != NULL)
    {
        if(p->getDir() == NULL)
            return p->getInfo();
        else
            return auxMax(p->getDir());
    }
    return -1;
}
void ArvBinBusca::remove(int x)
{
    auxRemove(raiz, x);
}
NoArv* ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}
NoArv* ArvBinBusca::removeNo1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir(); //filho único é da direita
    else
        aux = p->getEsq(); //filho único é da esquerda
    delete p;
    return aux;
}
NoArv* ArvBinBusca::MenorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir(); //nó à direita de p
    while(aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}
NoArv* ArvBinBusca::MaiorSubArvEsquerda(NoArv *p)
{
    NoArv *aux = p->getEsq(); //nó à direita de p
    while(aux->getDir() != NULL)
        aux = aux->getDir();
    return aux;
}

NoArv* ArvBinBusca::auxRemove(NoArv *p, int x)
{
    if(p == NULL)
        return NULL;
    else if(x < p->getInfo())//remove na sub. esquerda
        p->setEsq(auxRemove(p->getEsq(), x));
    else if(x > p->getInfo())// remove na sub. direita
        p->setDir(auxRemove(p->getDir(), x));
    else
    {
        // achou o nó a ser removido, p->getInfo() == x
        if((p->getEsq() == NULL)&&(p->getDir() == NULL))
            p = removeFolha(p);// p aponta para uma folha

        else if((p->getEsq() == NULL)||(p->getDir() == NULL))
            p = removeNo1Filho(p); //p tem só um filho

        else
        {
            //p tem dois filhos
            NoArv *aux = MenorSubArvDireita (p);

            // troca as informações
            int auxInt = aux->getInfo();
            p->setInfo(auxInt);
            aux->setInfo(x);

            // recursão: para a subarv. direita
            p->setDir(auxRemove(p->getDir(), x));
        }
    }
    return p;
}
void ArvBinBusca::removeMinimo()
{
    remove(minimo());
}
void ArvBinBusca::removeMaximo()
{
    remove(maximo());
}
bool ArvBinBusca::ehBalanceada()
{
    int n, h;
    auxEhBalanceada(raiz, &n, &h);
    if(h < log2(n) + 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool ArvBinBusca::auxEhBalanceada(NoArv *p, int *n, int *h)
{
    if(p == NULL)
    {
        *n = 0;
        *h = 0;
    }
    else
    {
        int ne, he;
        auxEhBalanceada(p->getEsq(),&ne,&he);

        int nd, hd;
        auxEhBalanceada(p->getDir(),&nd,&hd);

        *n = ne + nd + 1;
        *h = ((he > hd? he : hd) + 1);
    }
    return -1;
}
bool ArvBinBusca::ehABB()
{
    int a, b;
    a = raiz->getEsq()->getInfo();
    b = raiz->getDir()->getInfo();
    auxEhABB1(raiz->getEsq(), &a);
    auxEhABB2(raiz->getDir(), &b);
    if(a < raiz->getInfo() && b > raiz->getInfo())
    {
        return true;
    }
    else
    {
        return false;
    }
}
void ArvBinBusca::auxEhABB1(NoArv *p, int *n)
{
    if(p != NULL)
    {
        if(p->getInfo() > *n)
        {
            *n = p->getInfo();
        }
        auxEhABB1(p->getEsq(), n);
        auxEhABB1(p->getDir(), n);
    }
}
void ArvBinBusca::auxEhABB2(NoArv *p, int *n)
{
    if(p != NULL)
    {
        if(p->getInfo() < *n)
        {
            *n = p->getInfo();
        }
        auxEhABB2(p->getEsq(), n);
        auxEhABB2(p->getDir(), n);
    }
}
int ArvBinBusca::contaParesCaminho(int x)
{
    NoArv *p = raiz;
    int i=0;
    while(p != NULL)
    {
        if(p->getInfo() == x)
        {
            break;
        }
        else
        {
            if(x < p->getInfo())
            {
                p = p->getEsq();
            }
            else
            {
                p = p->getDir();
            }
        }
        if(p->getInfo()%2 == 0)
        {
            i++;
        }
    }
    return i;
}
int *ArvBinBusca::preencheVetor()
{
    int Nnos = contaNos(), i = 0, *vet = new int [Nnos];
    auxPreencheVetor(raiz, vet, &i);
    return vet;
}
void ArvBinBusca::auxPreencheVetor(NoArv *p, int vet[], int *i)
{
    if(p != NULL)
    {

        auxPreencheVetor(p->getEsq(), vet, i);
        vet[*i] = p->getInfo();
        *i = *i + 1;
        auxPreencheVetor(p->getDir(), vet, i);
    }
}
void ArvBinBusca::contaParesImpares(int x)
{
    int par = 0, impar = 0;
    auxContaParesImpares(raiz, &impar, &par, x);
    cout << "Pares: " << par << endl;
    cout << "Impares: " << impar << endl;
}
void ArvBinBusca::auxContaParesImpares(NoArv *p, int *imp, int *par, int x)
{
    while(p != NULL)
    {
        if(p->getInfo() == x)
        {
            break;
        }
        else
        {
            if(x < p->getInfo())
            {
                p = p->getEsq();
            }
            else
            {
                p = p->getDir();
            }
        }
        if(p->getInfo()%2 == 0)
        {
            *par = *par + 1;
        }
        else
        {
            *imp = *imp + 1;
        }
    }
}
