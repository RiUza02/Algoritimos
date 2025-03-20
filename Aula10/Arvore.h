#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#include "Nos.h"
class ArvBin
{
private:
    NoArv *raiz;

    ArvBin *deletaRaiz(NoArv *raiz);
    bool ehFolha(NoArv *p);
    int auxEhCheia(NoArv *raiz, int *B);
    int auxEhCompleta1(NoArv *raiz, int h);
    int auxEhCompleta2(NoArv *raiz, int h);
    void auxImprime(NoArv *raiz);
    void auxImprimeNivel(NoArv *raiz, int k);
    bool auxBusca(int val, NoArv *raiz);
    int auxAltura(NoArv *raiz);
    int auxQnos(NoArv *raiz);
    int auxQNosNivel(NoArv *raiz, int k);
    int auxNFolhas(NoArv *raiz);
    void auxDeletaFolhas(NoArv *raiz);
    int auxContaImpar(NoArv *raiz);
    int auxContaFolhaImpar(NoArv *raiz);
    float auxMedia(NoArv *raiz);
    float auxMediaNivel(NoArv *raiz, int k);
    void auxMin(NoArv *raiz, int *A);
    void auxMax(NoArv *raiz, int *A);
     void auxInverte(NoArv *raiz);
public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int val, ArvBin *sae, ArvBin *sad);
    bool vazia();
    bool ehCheia();
    bool ehCompleta();
    void imprime();
    void imprimeNivel(int k);
    bool busca(int val);
    int altura();
    int QNos();
    int QNosNivel(int k);
    int NFolhas();
    void deletaFolhas();
    int contaImpar();
    int contaFolhaImpar();
    float media();
    float mediaNivel(int k);
    int min();
    int max();
    void inverte();
};

#endif // ARVORE_H_INCLUDED
