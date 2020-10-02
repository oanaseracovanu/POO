#include<iostream>

using namespace std;

class persoana
{
    string nume,prenume;
    int varsta;
    public:
    persoana(string n,string p,int v);
    void afisare()
    {
        cout<<"Nume: "<<nume<<endl<<"Prenume: "<<prenume<<endl<<"Varsta: "<<varsta<<endl;
    }
};

persoana::persoana(string n,string p,int v)
{
    nume=n;
    prenume=p;
    varsta=v;
}

int main()
{
    string nm,pr;
    int vr;
    
    persoana p1("Ionescu","Maria",18);
    persoana p2("Popescu","Ion",30);
    p1.afisare();
    p2.afisare();

    cout<<"Numele persoanei: "; cin>>nm;
    cout<<"Prenumele persoanei: "; cin>>pr;
    cout<<"Varsta persoanei: "; cin>>vr;

    persoana p(nm,pr,vr);
    p.afisare();
    return 0;
}
