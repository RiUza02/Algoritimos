#include <iostream>
#include "Aula11.h"
using namespace std;

int main()
{
    ArvBinBusca arv;
    //int *vet;
    arv.insere(1);
    arv.insere(2);
    arv.insere(3);
    arv.insere(4);
    arv.insere(5);

    arv.insere(6);
    arv.insere(7);
    arv.insere(8);
    arv.insere(9);
    arv.insere(10);
    arv.insere(11);
    arv.insere(12);
    arv.insere(13);
    arv.imprime();
    arv.imprimeMaior(10);
    arv.imprimeMenor(10);
    cout<<endl;

    cout << "maior valor: " << arv.maximo() << endl;
    cout << "menor valor: " << arv.minimo() << endl;
    cout << "é balanceado?: " << arv.ehBalanceada() << endl;
    cout << "Pares caminho: " << arv.contaParesCaminho(10) << endl;
    arv.contaParesImpares(10);
    /*vet = arv.preencheVetor();
    for(int i=0; i<13; i++)
    {
        cout << vet[i] << " ";
    }*/
    return 0;
}
