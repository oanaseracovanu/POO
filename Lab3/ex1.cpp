#include<iostream>

using namespace std;

class carte
{
    string titlu;
    public:
    carte(string tit)
    {
        carte::titlu=tit;
    }
    void afisare_carte()
    {
        cout<<"Titlul: "<<titlu<<endl;
    }
    protected:
    float cost;
    void afisare_cost()
    {
        cout<<"Pretul: "<<cost<<endl;
    }
};

class fisa_biblioteca:public carte
{
    string autor,editura;
    public:
    fisa_biblioteca(string tit,string aut,string ed):carte(tit)
    {
        autor=aut;
        editura=ed;
        cost=10.02;
    }
    void afisare_biblio()
    {
        afisare_carte();
        afisare_cost();
        cout<<"Autor: "<<autor<<endl<<"Editura: "<<editura<<endl;
    }
};

int main()
{
    fisa_biblioteca fis("Ion","Liviu Rebreanu","Delfin");
    fis.afisare_biblio();
    return 0;
}