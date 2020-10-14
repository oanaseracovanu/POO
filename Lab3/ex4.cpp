#include<iostream>

using namespace std;

class forma
{
    protected:
    int latime,lungime;
    public:
    forma(int l,int ln)
    {
        latime=l;
        lungime=ln;
    }
};

class dreptunghi:public forma
{
    public:
    dreptunghi(int l,int ln):forma(l,ln)
    {

    };
    int aria()
    {
        return latime*lungime;
    }
};

class dimensiune_noua
{
    protected:
    int inaltime;
    dimensiune_noua(int h)
    {
        inaltime=h;
    }
};

class paralelipiped:public dreptunghi, public dimensiune_noua
{
    public:
    paralelipiped(int l,int ln,int h):dreptunghi(l,ln),dimensiune_noua(h)
    {

    };
    int volum()
    {
        return lungime*latime*inaltime;
    }
};

int main()
{
    dreptunghi d(1,2);
    cout<<"Aria dreptunghiului: "<<d.aria()<<endl;
    paralelipiped p(2,3,4);
    cout<<"Aria paralelipipedului: "<<p.aria()<<endl;
    cout<<"Volumul paralelipipedului: "<<p.volum()<<endl;
    return 0;
}