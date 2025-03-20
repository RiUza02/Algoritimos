#ifndef AULA8_H_INCLUDED
#define AULA8_H_INCLUDED

class NoDuplo
{
public:
    NoDuplo();
    ~NoDuplo();
    void setAnt(NoDuplo *p);
    void setProx(NoDuplo *p);
    void setInfo(int val);
    NoDuplo* getAnt();
    NoDuplo* getProx();
    int getInfo();
private:
    NoDuplo *ant; // ponteiro para anterior
    int info; // informacao
    NoDuplo *prox; // ponteiro para proximo
};
//----------------------------------------------------------------------------------------------------------------------------------
class ListaDupla
{
public:
    ListaDupla();
    ~ListaDupla();
    bool busca(int val);
    void insereInicio(int val);
    void removeInicio();
    void insereFinal(int val);
    void removeFinal();
    void removeMaior();
    void removePares();
    void insereAntes(float val, float x);
    void imprime();
    void imprimeReverso();
private:
    NoDuplo *primeiro;
    int n;
    NoDuplo *ultimo;
};
#endif // AULA8_H_INCLUDED
