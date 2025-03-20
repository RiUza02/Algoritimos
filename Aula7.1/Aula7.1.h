#ifndef AULA7_1_H_INCLUDED
#define AULA7_1_H_INCLUDED
class No
{
  public:
    No() { };
    ~No() { };
    int getInfo() { return info; };
    No* getProx() { return prox; };
    void setInfo(int val) { info = val; };
    void setProx(No *p) {prox = p;};

  private:
    int info; // informacao
    No *prox; // ponteiro para o proximo
};
//------------------------------------------------------------------------------------------

class Lista
{
  public:
    Lista();
    ~Lista();
    void insere(int val);
    bool busca(int val);
    void imprime();

  private:
    No *primeiro; // ponteiro para o primeiro
};
#endif // AULA7_1_H_INCLUDED
