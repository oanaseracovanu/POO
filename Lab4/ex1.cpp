#include<iostream>

using namespace std;
class A 
{
    private:
    int m; 
    public:
    friend class B;
    friend void g_afiseaza_m();
};

class B 
{ 
    public:
    void afiseaza_m() 
    {
    A a;
    a.m = 255;
    cout << "clasa B este prietena cu clasa A" << endl<< " poate accesa membrul privat A::m" << endl 
    << a.m << endl;
    }

    void g_afiseaza_m() 
    {
    A a;
    a.m = 300;
    cout << "functia g_afiseaza_m nu este un membru a clasei A dar este prieten"
    << endl << "poate accesa membrul privat A::m " << endl << a.m << endl;
    } 
};

int main() 
{
    B b;
    b.afiseaza_m();
    b.g_afiseaza_m(); 
    return 0;
}