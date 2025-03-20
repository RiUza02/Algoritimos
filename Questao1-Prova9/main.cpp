#include <iostream>
#include "ArvBin.h"
using namespace std;

int main()
{
    ArvBin *a1 = new ArvBin(), *a2 = new ArvBin(), *a3 = new ArvBin(), *a4 = new ArvBin(), *vazia = new ArvBin();
    a1->cria(6, vazia, vazia);
    a2->cria(-9, vazia, vazia);
    a1->cria(-8, a1, a2);

    a2->cria(4, vazia, vazia);
    a3->cria(18, vazia, vazia);
    a2->cria(22, a2, a3);

    a1->cria(15, a1, a2);

    a3->cria(25, vazia, vazia);
    a4->cria(0, vazia, vazia);
    a3->cria(3, a3, a4);

    a1->cria(2, a1, a3);

    a2 = NULL;
    a3 = NULL;
    a4 = NULL;
    delete a2;
    delete a3;
    delete a4;
    delete vazia;
    a1->preOrdem();

    a1->contagens(4);
    return 0;

}
