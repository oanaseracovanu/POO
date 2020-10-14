#include<iostream>

using namespace std;

class carte
{
    string titlu;
    float const cost2=2;
    protected:
    void afisare_cost()
    {
        cout<<"Pret: "<<cost2<<endl;
    }
    public:
    carte(string titlu)
    {
        carte::titlu=titlu;
        cout<<"Constructorul clasei de baza"<<endl;
    }
    void afisare_carte()
    {
        cout<<"Titlu: "<<titlu<<endl; 
    }
    ~carte()
    {
        cout<<"Destructorul clasei de baza"<<endl;
    }
    protected:
    float cost;
    void afisare_pret()
    {
    cout<<"Pretul: "<<cost<<endl;
    }
};

class pagini
{
    protected:
    int linii;
    public:
    pagini(int linii)
    {
        pagini::linii=linii;
        cout<<"Constructor clasa de baza2"<<endl;
    }
    void afisare_pagini()
    {
        cout<<"Nr de pagini: "<<linii<<endl;
    }
    ~pagini()
    {
        cout<<"Destructorul clasei de baza2"<<endl;
    }

};

class fisa:carte, pagini 
{
    string autor,editura;
    public:
    fisa(string autor,string editura,string titlu):carte(titlu),pagini(50)
    {
        fisa::autor=autor;
        fisa::editura=editura;
        cost=20;
        cout<<"Constructorul clasei derivate"<<endl;
    }
    void afisare_biblio()
    {
        afisare_carte();
        afisare_cost();
        afisare_pret();
        cout<<"Autor: "<<autor<<endl<<"Editura: "<<editura<<endl;
        afisare_pagini();
    }
    ~fisa()
    {
        cout<<"Destructorul clasei derivate"<<endl;
    }
};

int main()
{
    fisa fis("Programare Orientata pe Obiecte", "Vasile STOICU-TIVADAR", "Politehnica");
    fis.afisare_biblio();
    return 0;
}
