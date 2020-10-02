#include<iostream>

using namespace std;

class student
{
    string nume,rol,adresa;
    int cod;
    public:
    student(string n,string r,string ad,int c);
    ~student();
    void afisare();
};

student::student(string n,string r,string ad,int c)
{
    nume=n;
    rol=r;
    adresa=ad;
    cod=c;
}

void student::afisare()
{
    cout<<"Nume: "<<nume<<endl;
    cout<<"Rol: "<<rol<<endl;
    cout<<"Adresa: "<<adresa<<endl;
    cout<<"Cod postal: "<<cod<<endl;
}

student::~student()
{
    cout<<"Deconstructorul- se elibereaza memoria"<<endl;
}

int main()
{
    string n,r,ad; int c;

    cout<<"Numele studentului: "; cin>>n;
    cout<<"Rolul: "; cin>>r;
    cout<<"Adresa: "; cin>>ad;
    cout<<"Cod: "; cin>>c;
    student s(n,r,ad,c);
    s.afisare();
    //s.~student();
    return 0;
    
}

