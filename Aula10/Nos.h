#ifndef NOS_H_INCLUDED
#define NOS_H_INCLUDED

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

class NoArv
{
private:
    NoArv *esq;
    int info;
    NoArv *dir;
public:
    NoArv();
    ~NoArv();
    void setEsq(NoArv *p);
    void setInfo(int val);
    void setDir(NoArv *p);
    NoArv* getEsq();
    int getInfo();
    NoArv* getDir();
};

#endif // NOS_H_INCLUDED
