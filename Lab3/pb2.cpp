#include<iostream>

using namespace std;

class mamifer
{
    string specie;
    int varsta;
    public:
    mamifer(string sp,int v)
    {
        mamifer::specie=sp;
        mamifer::varsta=v;
    }
    void afisare()
    {
        cout<<"Specia: "<<specie<<endl<<"Varsta: "<<varsta<<endl;
    }
};

class cangur:public mamifer
{
    string nume;
    public:
    cangur(string sp, int v, string n):mamifer(sp,v)
    {
        cangur::nume=n;
    }
    void afisare_c()
    {
        cout<<"Nume cangur: "<<nume<<endl;
        afisare();
    }

};

class urs:public mamifer
{
    string nume_u;
    public:
    urs(string sp, int v,string u):mamifer(sp,v)
    {
        urs::nume_u=u;
    }
    void afisare_urs()
    {
        cout<<"Nume urs: "<<nume_u<<endl;
        afisare();
    }
};

int main()
{
    cangur c("cangur",10,"Rocky");
    c.afisare_c();
    urs u("urs",20,"Bruno");
    u.afisare_urs();
    return 0;
}