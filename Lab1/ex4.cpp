#include<iostream>

using namespace std;

typedef struct 
{
    char marca[20],model[20];
    float consum,pret;
}masina;

void citire(masina *m)
{
    cout<<"Marca: ";
    cin>>m->marca;
    cout<<"Modelul: ";
    cin>>m->model;
    cout<<"Consumul: ";
    cin>>m->consum;
    cout<<"Pretul: ";
    cin>>m->pret;
}

void afisare(masina *m)
{
    cout<<"Marca: "<<m->marca<<endl<<"Modelul: "<<m->model<<endl;
    cout<<"Consumul: "<<m->consum<<endl<<"Pretul: "<<m->pret<<endl;
}

int main()
{
    masina *m;
    m=new masina;
    citire(m); 
    afisare(m);
    return 0;   
}
