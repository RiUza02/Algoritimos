#include <iostream>
#include "questaoy.h"
using namespace std;

int main()
{
    ListaEncad l;

    l.insereFinal(8);
    l.insereFinal(3);
    l.insereFinal(5);
    l.insereFinal(10);
    l.insereFinal(4);
    l.insereFinal(10);

    l.imprime();
    l.removeDepoisMaior();
    l.imprime();
    return 0;
}
