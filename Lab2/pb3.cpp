#include<iostream>

using namespace std;

class profesor
{
    string nume,departament;
    int grad, vechime;
    public:
    profesor(string n,string d,int g,int v);
    ~profesor();
    void afisare();
};

profesor::profesor(string n,string d,int g,int v)
{
    nume=n;
    departament=d;
    grad=g;
    vechime=v;
}

void profesor::afisare()
{
    cout<<"Nume: "<<nume<<endl;
    cout<<"Departament: "<<departament<<endl;
    cout<<"Grad: "<<grad<<endl;
    cout<<"Vechime: "<<vechime<<endl;
}

profesor::~profesor()
{
    cout<<"Destructor- se elibereaza memoria"<<endl;
}

int main()
{
    string n,d; int g,v;
    cout<<"Numele profesorului: "; cin>>n;
    cout<<"Departamentul: "; cin>>d;
    cout<<"Gradul: "; cin>>g;
    cout<<"Vechimea: "; cin>>v;
    profesor p(n,d,g,v);
    p.afisare();
    //p.~profesor(); 
    return 0;
}