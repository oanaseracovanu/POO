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
        return lungime*latime;
    }
};

class paralelipiped:public dreptunghi
{
    int inaltime;
    public:
    paralelipiped(int h,int l,int ln):dreptunghi(l,ln)
    {
        inaltime=h;
    }
    int volum()
    {
        return lungime*latime*inaltime;
    }
};

int main()
{
    dreptunghi d(3,4);
    cout<<"Aria dreptunghiului: "<<d.aria()<<endl;
    paralelipiped par(3,4,5);
    cout<<"Arie paralelipiped: "<<par.aria()<<endl;
    cout<<"Volumul paralelipipedului: "<<par.volum()<<endl;
    return 0;
}