#ifndef AULA6_H_INCLUDED
#define AULA6_H_INCLUDED

class No
{
public:
    No();
    ~No();
    int getVal();
    No* getProx();
    void setVal(int x);
    void setProx(No *p);
private:
    int val;
    No *prox;
};
//---------------------------------------------------------------------------------------
class Lista
{
public:
    Lista();
    ~Lista();
    void insereInicio(int val);
    void insereFinal(int val);
    void insereK(int Val, int k);
    void removeInicio();
    void removeFinal();
    void removek(int k);
    int QNos();
    void imprime();
private:
    No* primeiro;
};

#endif // AULA6_H_INCLUDED
