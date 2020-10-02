#include<iostream>

using namespace std;

class student
{
    string nume,prenume;
    int grupa,cod_postal;
    public:
    student();
    ~student();
    void citire();
    void afisare();
};

student::student()
{
    cout<<"Constructorul- dati informatiile despre student: "<<endl;
}

void student::citire()
{
    cout<<"Numele: "; cin>>nume;
    cout<<"Prenumele: "; cin>>prenume;
    cout<<"Grupa: "; cin>>grupa;
    cout<<"Codul postal: "; cin>>cod_postal;
}

void student::afisare()
 {
    cout<<"Nume: "<<nume<<endl<<"Prenume: "<<prenume<<endl;
    cout<<"Grupa: "<<grupa<<endl<<"Cod postal: "<<cod_postal<<endl;
}

student::~student()
{
    cout<<"Destructorul elibereaza memoria"<<endl;
}

int main()
{
    student s;
    s.citire();
    s.afisare();
    //s.~student();
    return 0;
}