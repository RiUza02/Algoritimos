#include <iostream>
#include "ListaCircular.h"
using namespace std;

int main()
{
    ListaCircular lista;

    for(int i=1; i<=10; i++)
        lista.insereInicio(i);

    lista.imprime();
    return 0;
}
