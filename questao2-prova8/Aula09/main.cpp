#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"

using namespace std;
int novoCubo()
{
    return rand() % 4;
}
void cubos()
{
    PilhaEncad Pilha;
    int chances = 100;
    int cor, ultimoCubo, Qcubos=5;
    int cuboAdd=1;

    for(int i=0; i<5; i++)
        Pilha.empilha(novoCubo());
    cout << "Iniciando jogo: Cubos" << endl << "boa sorte!" << endl;

    while(chances > 0 && !Pilha.vazia())
    {
        cout << "total atual de cubos:" << Qcubos << endl;
        ultimoCubo = Pilha.getTopo();
        cin >> cor;
        if(cor>=0 && cor<=3)
        {
            if(cor==ultimoCubo)
            {
                Pilha.desempilha();
                Qcubos--;
            }
            else
            {
                Pilha.empilha(cor);
                Qcubos++;
            }
        }
        else
        {
            Pilha.empilha(novoCubo());
            Qcubos++;
        }

        if(cuboAdd==5)
        {
            Pilha.empilha(novoCubo());
            Qcubos++;
            cuboAdd=0;
        }
        cuboAdd++;
        chances--;
    }
    if(Pilha.vazia())
    {
        cout << "voce ganhou, parabens!!" << endl;
    }
    else
    {
        cout << "quantidade de tentativas esgotadas, mais sorte na proxima vez..." << endl;
    }
}
int main()
{
    cubos();
    return 0;
}
