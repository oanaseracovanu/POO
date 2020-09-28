#include<iostream>

using namespace std;

typedef struct
{
    char nume[20],prenume[20],adresa[20],nr[10];
    int varsta;

}persoana;

void citire(persoana *p)
{

    cout<<"Numele: ";
    cin>>p->nume;
    cout<<"Prenumele: ";
    cin>>p->prenume;
    cout<<"Varsta: ";
    cin>>p->varsta;
    cout<<"Adresa: ";
    cin>>p->adresa;
    cout<<"Nr de telefon: ";
    cin>>p->nr;
}

void afisare(persoana *p)
{
    cout<<"Nume si prenume: "<<p->nume<<" "<<p->prenume<<endl;
    cout<<"Varsta: "<<p->varsta<<endl<<"Adresa: "<<p->adresa<<endl<<"Nr de telefon: "<<p->nr<<endl;
}

int main()
{
    persoana *p;
    p=new persoana;
    citire(p);
    afisare(p);
    return 0;
}