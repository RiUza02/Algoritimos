#ifndef AULA7_H_INCLUDED
#define AULA7_H_INCLUDED
class lista
{
private:
    int max, n, *vet;
    int buscaBinaria(int val);
public:
    lista(int x);
    ~lista();

    int get(int k);
    void set(int x);
    void remove(int x);
    void imprime();



};
#endif // AULA7_H_INCLUDED
