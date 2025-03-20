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
    int get(int k);
    void set(int val, int k);
    void insereOrdenado(int val);
    void insereInicio(int val);
    void insereFinal(int val);
    void insereK(int Val, int k);
    void removeInicio();
    void removeFinal();
    void removek(int k);

    int QNos();
    void imprime();
    int buscaMaior(int val);
    void limpar();
    float calculaMedia();
    void concatena(Lista *l2);
    Lista* partir(int k);

private:
    No* primeiro;
    No* ultimo;
    int n;
};

#endif // AULA6_H_INCLUDED
