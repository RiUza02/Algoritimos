#include <iostream>
#include "Aula6.h"
using namespace std;

int main()
{
    Lista L;
    L.insereOrdenado(1);
    L.insereOrdenado(2);
    L.insereOrdenado(3);
    L.imprime();
    //cout << endl << "Media dos valores: " << L.calculaMedia() << endl;
    //cout << endl << "Quantidade dos nós: " << L.QNos() << endl;

    return 0;
}
