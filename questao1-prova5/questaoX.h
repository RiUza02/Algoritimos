#ifndef QUESTAOX_H_INCLUDED
#define QUESTAOX_H_INCLUDED
#include <cmath>
class ListaCont
{
private:
    int max;
    int n;
    int *vet;

public:
    ListaCont(int tam);
    ~ListaCont();

    int get(int k);
    void set(int k, int val);
    void insereFinal(int val);
    void insereK(int k, int val);
    void insereInicio(int val);
    void removeFinal();
    void removeK(int k);
    void removeInicio();
    void imprime();
    int quatNos();
    int quantMax();

     void inserirVet(int tam, int v[]);
};
using namespace std;

class Ponto
{
private:
    float x, y;
public:
    Ponto() {};
    Ponto(float xx, float yy) { x = xx; y = yy; };
    ~Ponto() {};
    float getX() { return x; };
    float getY() { return y; };
    void setX(float xx) { x = xx; };
    void setY(float yy) { y = yy; };
    float distancia(Ponto *p2) { return sqrt(pow(x - p2->x, 2) + pow(y - p2->y, 2)); };
};


#endif // QUESTAOX_H_INCLUDED
