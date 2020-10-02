#include<iostream>

using namespace std;

class carte
{
    string titlu,autor,editura;
    int an;
    public:
    carte(string t,string au,string e,int a);
    void afisare();
};

carte::carte(string t,string au,string e,int a)
{
    titlu=t;
    autor=au;
    editura=e;
    an=a;
}

void carte::afisare()
{
    cout<<"Titlu: "<<titlu<<endl;
    cout<<"Autor: "<<autor<<endl;
    cout<<"Editura: "<<editura<<endl;
    cout<<"Anul: "<<an<<endl;
}

int main()
{
    string ti,aut,edit; int an_pb;

    carte c1("Ion","Rebreanu","Delfin",1980);
    carte c2("Morometii","Preda","Humanitas",1990);
    cout<<"Titlul cartii: "; cin>>ti;
    cout<<"Autorul: "; cin>>aut;
    cout<<"Editura: "; cin>>edit;
    cout<<"Anul publicarii: "; cin>>an_pb;
    carte c(ti,aut,edit,an_pb);

    c1.afisare();
    c2.afisare();
    c.afisare();
    return 0;

}