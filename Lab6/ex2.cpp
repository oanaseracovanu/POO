#include<iostream>

using namespace std;

class carte
{
    string titlu,autor,editura;
    int an;
    public:
    carte(string t,string aut,string ed,int a)
    {
        titlu=t;
        autor=aut;
        editura=ed;
        an=a;
    }
    friend ostream &operator<<(ostream &iesire,carte ct);
};

ostream &operator<<(ostream &iesire, carte ct)
{
    iesire<<"Titlu: "<<ct.titlu<<endl;
    iesire<<"Aturo: "<<ct.autor<<endl;
    iesire<<"Editura: "<<ct.editura<<endl;
    iesire<<"Anul publicarii: "<<ct.an<<endl<<endl;
    return iesire;
}

int main()
{
    carte ct1("Ion","Liviu Rebreanu","Delfin",2000);
    carte ct2("Enigma Otiliei","George Calinescu","Teora",2001);
    cout<<ct1<<ct2;
    return 0;
}