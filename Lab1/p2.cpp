#include<iostream>
#include<string.h>

using namespace std;

class sofer
{
    char nume[20],adresa[20],cnp[10];
    int varsta;
    public:
    void citire_s(char n[20],char cn[10],int v,char ad[20])
    {
        strcpy(nume,n);
        strcpy(cnp,cn);
        varsta=v;
        strcpy(adresa,ad);
    }

    void afisare_s()
    {
        cout<<"Numele soferului: "<<nume<<endl<<"Cnp-ul: "<<cnp<<endl<<"Varsta: "<<varsta<<endl<<"Adresa: "<<adresa<<endl;
    }
   
};

class masina
{
    char producator[20],model[10],sofer[20];
    int an;
    public:
    void citire_m(char p[20],char m[20],int a,char s[20])
    {
        strcpy(producator,p);
        strcpy(model,m);
        an=a;
        strcpy(sofer,s);
    }

    void afisare_m()
    {
        cout<<"Producatorul: "<<producator<<endl<<"Modelul: "<<model<<endl<<"Anul fabricatiei: "<<an<<endl<<"Numele soferului: "<<sofer<<endl;
    }
    
};

int main()
{
    sofer s;
    masina m;
    char n[20],ad[20],p[20],ma[20],so[20],c[10];
    int v,a;
    cout<<"Nume sofer: "; cin>>n;
    cout<<"Cnp: "; cin>>c;
    cout<<"Varsta: "; cin>>v;
    cout<<"Adresa: "; cin>>ad;
    cout<<"Producator masina: "; cin>>p;
    cout<<"Model: "; cin>>ma;
    cout<<"An: "; cin>>a;
    cout<<"Sofer: "; cin>>so;
    s.citire_s(n,c,v,ad);
    s.afisare_s();
    m.citire_m(p,ma,a,so);
    m.afisare_m();
    return 0;

}
