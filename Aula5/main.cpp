#include <iostream>
#include "aula5.h"
using namespace std;


int main()
{
    int x=10;
    lista lis(x), a(x/2), b(x/2);
    for(int i=0; i<x; i++)
    {
        lis.insertF(i);
        cout << lis.get(i+1) << " ";
    }
    cout << endl;

    lis.AlocaMeio(lis, a, b);

    return 0;
}
