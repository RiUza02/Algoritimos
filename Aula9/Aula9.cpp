#include <iostream>
#include "Aula9.h"
using namespace std;
No::No()
{

}
No::~No()
{

}
int No::getVal()
{
    return val;
}
No* No::getProx()
{
    return prox;
}
void No::setVal(int x)
{
    val = x;
}
void No::setProx(No *p)
{
    prox = p;
}
//-----------------------------------------------------------------------------------------------------------------------------------
