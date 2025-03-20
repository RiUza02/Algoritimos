#include <iostream>
#include "questaoX.h"
using namespace std;

int main()
{
    ListaCont l(40);
    int vet[40];
    for(int i=0; i<6; i++)
    {
        l.insereFinal(i+1);
        vet[i] = -i;
    }

    l.imprime();
    for(int i=0; i<5; i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;


    l.inserirVet(5, vet);
    l.imprime();
    cout << endl << "quantidade de espaços depois: " << l.quantMax() << endl;
    cout << endl << "quantidade de elementos depois: " << l.quatNos() << endl;
    return 0;
}
