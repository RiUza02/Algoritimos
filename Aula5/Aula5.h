#ifndef AULA5_H_INCLUDED
#define AULA5_H_INCLUDED
class lista
{
private:
    int max, n, *vet;
public:
    lista(int x);
    ~lista();

    int get(int k);
    void set(int k,int x);
    void insertF(int x);
    void RemoveF();
    void insertI(int x);
    void removeI();
    void insertk(int k,int x);
    void Removek(int k);
    void numNos();
    void insereValores(int tam, int vet[]);

    void AlocaMeio(lista a, lista b, lista c);


};

#endif // AULA5_H_INCLUDED
