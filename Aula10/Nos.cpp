#include "Nos.h"
using namespace std;
NoArv::NoArv()
{

}
NoArv::~NoArv()
{

}
void NoArv::setEsq(NoArv *p)
{
    esq = p;
}
void NoArv::setInfo(int val)
{
    info = val;
}
void NoArv::setDir(NoArv *p)
{
    dir = p;
}
NoArv* NoArv::getEsq()
{
    return esq;
}
int NoArv::getInfo()
{
    return info;
}
NoArv* NoArv::getDir()
{
    return dir;
}
//-------------------------------------------------------------------------------
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
