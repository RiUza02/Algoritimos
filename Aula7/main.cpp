#include <iostream>
#include "Aula7.h"

using namespace std;

int main()
{
    lista l(20);

    l.set(15);
    l.imprime();
    l.set(10);
    l.imprime();
    l.set(5);
    l.imprime();
    l.set(8);
    l.imprime();
    l.set(25);
    l.imprime();
    l.set(55);
    l.imprime();
    l.set(-1);
    l.imprime();
    l.remove(0);
    l.imprime();
    l.remove(10);
    l.imprime();
    l.remove(-1);
    l.imprime();
    l.remove(55);
    l.imprime();

    return 0;
}
