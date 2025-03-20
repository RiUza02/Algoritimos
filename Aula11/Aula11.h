#ifndef AULA11_H_INCLUDED
#define AULA11_H_INCLUDED
#include "No.h"
class ArvBinBusca
{
private:
    NoArv *raiz; //ponteiro para o nó raiz da árvore

    void libera(NoArv *p);
    void imprimePorNivel(NoArv *p, int nivel);
    void auxContaNos(NoArv *p, int *n);

    void auxImprimeMaior(NoArv *p, int x);
    void auxImprimeMenor(NoArv *p, int x);
    bool ehFolha(NoArv *p);
    NoArv* auxInsere(NoArv *p, int val);
    int auxMin(NoArv *p);
    int auxMax(NoArv *p);

    NoArv *auxRemove(NoArv *p, int x);
    NoArv *removeFolha(NoArv *p);
    NoArv *removeNo1Filho(NoArv *p);
    NoArv *MenorSubArvDireita(NoArv *p);
    NoArv *MaiorSubArvEsquerda(NoArv *p);

    bool auxEhBalanceada(NoArv *p, int *n, int *h);
    void auxEhABB1(NoArv *p, int *n);
    void auxEhABB2(NoArv *p, int *n);
    void auxPreencheVetor(NoArv *p, int vet[], int *i);
    void auxContaParesImpares(NoArv *p, int *imp, int *par, int x);
public:
    ArvBinBusca();
    ~ArvBinBusca();
    int getRaiz();
    bool vazia(); //verifica se a árvore está vazia
    void imprime();
    int contaNos();

    void imprimeMaior(int x);
    void imprimeMenor(int x);
    void remove(int x);
    bool buscaIt(int val);
    void insere(int val);
    int minimo();
    int maximo();
    void removeMinimo();
    void removeMaximo();
    bool ehBalanceada();
    bool ehABB();
    int contaParesCaminho(int x);
    int *preencheVetor();
    void contaParesImpares(int x);
};
#endif
