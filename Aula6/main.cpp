#include <iostream>
#include "Aula6.h"
using namespace std;

int main()
{
    Lista L;
    L.insereInicio(1);
    L.insereInicio(2);
    L.insereInicio(3);
    L.insereInicio(4);
    L.insereInicio(5);
    L.insereInicio(6);
    L.imprime();
    L.removek(2);
    L.imprime();
    cout << endl << "Quantidade dos nós: " << L.QNos() << endl;

    return 0;
}
