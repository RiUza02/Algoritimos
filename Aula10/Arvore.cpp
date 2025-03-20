#include "Arvore.h"
#include "Fila.h"
#include "Pilha.h"
#include "math.h"
#include <iostream>
using namespace std;
ArvBin::ArvBin()
{
    raiz = NULL;
}
ArvBin::~ArvBin()
{
    deletaRaiz(raiz);
}
ArvBin *ArvBin::deletaRaiz(NoArv *p)
{
    if(p != NULL)
    {
        deletaRaiz(p->getEsq());
        deletaRaiz(p->getDir());
        delete p;
        p = NULL;
    }
    return NULL;
}
int ArvBin::getRaiz()
{
    if(raiz != NULL)
    {
        return raiz->getInfo();
    }
    else
    {
        cout << "arvore vazia" << endl;
        return -1;
    }
}
void ArvBin::cria(int val, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv;
    p->setDir(sad->raiz);
    p->setEsq(sae->raiz);
    p->setInfo(val);
    raiz = p;
}
bool ArvBin::vazia()
{
    if(raiz == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool ArvBin::ehFolha(NoArv *p)
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
void ArvBin::imprime()
{
    auxImprime(raiz);
}

void ArvBin::auxImprime(NoArv *p)
{
    if(p != NULL)
    {
        cout << p->getInfo() << endl;
        auxImprime(p->getEsq());
        auxImprime(p->getDir());
    }
}
void ArvBin::imprimeNivel(int k)
{
    auxImprimeNivel(raiz, k);
}
void ArvBin::auxImprimeNivel(NoArv *p, int k)
{
    if(p != NULL && k >= 0)
    {
        if(k == 0)
        {
            cout << p->getInfo() << endl;
        }
        auxImprimeNivel(p->getEsq(), k-1);
        auxImprimeNivel(p->getDir(), k-1);
    }
}
bool ArvBin::busca(int val)
{
    return auxBusca(val, raiz);
}
bool ArvBin::auxBusca(int val, NoArv *p)
{
    if(p != NULL)
    {
        if(p->getInfo() == val)
        {
            return true;
        }
        else
        {
            if(auxBusca(val, p->getDir()))
            {
                return true;
            }
            else
            {
                if(auxBusca(val, p->getEsq()))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

        }
    }
    return false;
}
int ArvBin::altura()
{
    return auxAltura(raiz);
}
int ArvBin::auxAltura(NoArv *p)
{
    int Ae, Ad;
    if(p == NULL)
    {
        return -1;
    }
    else
    {
        Ae = auxAltura(p->getEsq());
        Ad = auxAltura(p->getDir());
        if(Ae > Ad)
        {
            return Ae + 1;
        }
        else
        {
            return Ad + 1;
        }
    }
}
int ArvBin::QNos()
{
    return auxQnos(raiz);
}
int ArvBin::auxQnos(NoArv *p)
{
    if(p != NULL)
    {
        return 1 + auxQnos(p->getDir())+auxQnos(p->getEsq());
    }
    return 0;
}
int ArvBin::QNosNivel(int k)
{
    return auxQNosNivel(raiz, k);
}
int ArvBin::auxQNosNivel(NoArv *p, int k)
{
    if(p != NULL && k >= 0)
    {
        if(k == 0)
        {
            return 1 + auxQNosNivel(p->getEsq(), k-1) + auxQNosNivel(p->getDir(), k-1);
        }
        else
        {
            return auxQNosNivel(p->getEsq(), k-1) + auxQNosNivel(p->getDir(), k-1);
        }
    }
    else
    {
        return 0;
    }
}
int ArvBin::NFolhas()
{
    return auxNFolhas(raiz);
}
int ArvBin::auxNFolhas(NoArv *p)
{
    if(p != NULL)
    {
        if(ehFolha(p))
        {
            return 1 + auxNFolhas(p->getDir()) + auxNFolhas(p->getEsq());
        }
        else
        {
            return auxNFolhas(p->getDir()) + auxNFolhas(p->getEsq());
        }
    }
    return 0;
}
bool ArvBin::ehCheia()
{
    int Altura, *Qfolhas = new int;
    *Qfolhas = 0;
    Altura = auxEhCheia(raiz, Qfolhas);
    if(pow(2, Altura)== *Qfolhas)
    {
        delete Qfolhas;
        return true;
    }
    else
    {
        delete Qfolhas;
        return false;
    }
}
int  ArvBin::auxEhCheia(NoArv *p, int *Qfolhas)
{
    int Ae, Ad;
    if(p == NULL)
    {
        return -1;
    }
    else
    {
        if(ehFolha(p))
        {
            *Qfolhas = *Qfolhas + 1;
        }
        Ae = auxEhCheia(p->getEsq(), Qfolhas);
        Ad = auxEhCheia(p->getDir(), Qfolhas);
        if(Ae > Ad)
        {
            return Ae + 1;
        }
        else
        {
            return Ad + 1;
        }
    }
}
bool ArvBin::ehCompleta()
{
    int A, B, h;
    h = altura() - 1;
    A = auxEhCompleta1(raiz->getDir(), h);
    B = auxEhCompleta2(raiz->getEsq(), h);

    if(A == B)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int ArvBin::auxEhCompleta1(NoArv *p, int h)
{
    if(p != NULL)
    {
        if(h!=0)
        {
            return 0 + auxEhCompleta1(p->getDir(), h-1) + auxEhCompleta1(p->getEsq(), h-1);
        }
        else
        {
            return 1 + auxEhCompleta1(p->getDir(), h-1) + auxEhCompleta1(p->getEsq(), h-1);
        }
    }
    return 0;
}
int ArvBin::auxEhCompleta2(NoArv *p, int h)
{
    if(p != NULL)
    {
        if(h!=0)
        {
            return 0 + auxEhCompleta2(p->getDir(), h-1) + auxEhCompleta2(p->getEsq(), h-1);
        }
        else
        {
            return 1 + auxEhCompleta2(p->getDir(), h-1) + auxEhCompleta2(p->getEsq(), h-1);
        }
    }
    return 0;
}
void ArvBin::deletaFolhas()
{
    auxDeletaFolhas(raiz);
}
void ArvBin::auxDeletaFolhas(NoArv *p)
{
    if(p != NULL)
    {
        if(ehFolha(p->getDir()) && ehFolha(p->getEsq()))
        {
            p->setDir(NULL);
            p->setEsq(NULL);
        }
        auxDeletaFolhas(p->getDir());
        auxDeletaFolhas(p->getEsq());
    }
}
int ArvBin::contaImpar()
{
    return auxContaImpar(raiz);
}
int ArvBin::auxContaImpar(NoArv *p)
{
    if(p != NULL)
    {
        if(p->getInfo() % 2 == 0)
        {
            return auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());
        }
        else
        {
            return 1 + auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());
        }
    }
    return 0;
}
int ArvBin::contaFolhaImpar()
{
    return auxContaFolhaImpar(raiz);

}
int ArvBin::auxContaFolhaImpar(NoArv *p)
{
    if(p != NULL)
    {
        if(p->getInfo()%2 == 0)
        {
            return auxContaFolhaImpar(p->getEsq()) + auxContaFolhaImpar(p->getDir());
        }
        else
        {
            if(ehFolha(p))
            {
                return 1 + auxContaFolhaImpar(p->getEsq()) + auxContaFolhaImpar(p->getDir());
            }
            else
            {
                return auxContaFolhaImpar(p->getEsq()) + auxContaFolhaImpar(p->getDir());
            }
        }
    }
    return 0;
}
float ArvBin::media()
{
    return auxMedia(raiz)/QNos();
}
float ArvBin::auxMedia(NoArv *p)
{
    if(p != NULL)
    {
        return p->getInfo() + auxMedia(p->getEsq()) + auxMedia(p->getDir());
    }
    return 0;
}
float ArvBin::mediaNivel(int k)
{
    int x = QNosNivel(k);
    return auxMediaNivel(raiz, k)/x;
}
float ArvBin::auxMediaNivel(NoArv *p, int k)
{
    if(p != NULL && k >= 0)
    {
        if(k == 0)
        {
            return p->getInfo() + auxMediaNivel(p->getEsq(), k-1) + auxMediaNivel(p->getDir(), k-1);
        }
        else
        {
            return auxMediaNivel(p->getEsq(), k-1) + auxMediaNivel(p->getDir(), k-1);
        }
    }
    return 0;
}
int ArvBin::min()
{
    int *A = new int;
    *A = raiz->getInfo();
    auxMin(raiz, A);
    int a = *A;
    delete A;
    return a;
}
void ArvBin::auxMin(NoArv *p, int *A)
{
    if(p != NULL)
    {
        if(p->getInfo() < *A)
        {
            *A = p->getInfo();
        }
        auxMin(p->getEsq(), A);
        auxMin(p->getDir(), A);
    }
}
int ArvBin::max()
{
    int *A = new int;
    *A = raiz->getInfo();
    auxMax(raiz, A);
    int a = *A;
    delete A;
    return a;
}
void ArvBin::auxMax(NoArv *p, int *A)
{
    if(p != NULL)
    {
        if(p->getInfo() > *A)
        {
            *A = p->getInfo();
        }
        auxMax(p->getEsq(), A);
        auxMax(p->getDir(), A);
    }
}
void ArvBin::inverte()
{
    auxInverte(raiz);
}
void ArvBin::auxInverte(NoArv *p)
{
    if(p != NULL)
    {
        auxInverte(p->getEsq());
        auxInverte(p->getDir());
        NoArv *A;
        A = p->getDir();
        p->setDir(p->getEsq());
        p->setEsq(A);
    }
}
