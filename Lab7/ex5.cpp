#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class lista;

class electrocasnice
{
    private:
    string producator;
    int pret,tip_derivat;
    electrocasnice *urm;
    public:
    electrocasnice(int t, string prod,int pr)
    {
        tip_derivat=t;
        producator=prod;
        pret=pr;
    }
    virtual void afisare()
    {
        cout<<"Producator: "<<producator<<endl;
        cout<<"Pret: "<<pret<<endl; 
    }
    friend class lista;
};

class masina:public electrocasnice
{
    private:
    int nr;
    public:
    masina(int t,string prod,int pr,int n):electrocasnice(t,prod,pr)
    {
        nr=n;
    }
    void afisare()
    {
        electrocasnice::afisare();
        cout<<"Nr programe: "<<nr<<endl;
    }
    friend class lista;
};

class aragaz:public electrocasnice
{
    private:
    string tip;
    int t;
    public:
    aragaz(int t,string prod,int pr,string tp):electrocasnice(t,prod,pr)
    {
        tip=tp;
    }
    void afisare()
    {
        electrocasnice::afisare();
        cout<<"Tip arzatoare: "<<tip<<endl;
    }
    friend class lista;
};

class lista
{
    public:
    electrocasnice *head;
    void adaugare(electrocasnice *el);
    void citire(lista &l);
    void afisare();
    void cautare();
    void fisier();
};

void lista::adaugare(electrocasnice *el)
{
    electrocasnice *e;
    e=head;
    if(e)
    {
        if(el->producator==e->producator)
        {
            el->urm=head;
            head=el;
        }
        else
        {
            while(e->urm&&(e->urm)->producator==el->producator)
            e=e->urm;
            el->urm=e->urm;
            e->urm=el;
        }
    }
    else
    {
        head=el;
    }
}

void lista::citire(lista &l)
{
    masina *m;
    aragaz *a;
    electrocasnice *e;
    string prod,t;
    int pr,n,x;
    ifstream fis("Electr.txt");
    if(fis.is_open())
    {
        while(!fis.eof())
        {
            fis>>x;
            if(x==0)
            {
            fis>>prod>>pr>>n;
            m=new masina(0,prod,pr,n);
            e=m;
            l.adaugare(e);
            }
            if(x==1)
            {
            fis>>prod>>pr>>t;
            a=new aragaz(1,prod,pr,t);
            e=a;
            l.adaugare(e);
            }
        }
        if(fis.eof())
        {
            cout<<"Datele au fost incarcate in lista"<<endl;
        }
        else
        cout<<"Datele nu au fost incarcate in lista!"<<endl;
    }
    else
    {
        cout<<"Nu s-a putut deschide fisierul!"<<endl;
    }
    
}

void introducere(lista &l,int x)
{
    string prod,tp;
    int pr,n;
    electrocasnice *el;
    cout<<"Producatorul: "; cin>>prod;
    cout<<"Pretul: "; cin>>pr;
    if(x==0)
    {
        masina *m;
        cout<<"Numar programe: "; cin>>n;
        m=new masina(0,prod,pr,n);
        el=m;
        l.adaugare(el);
    }
    if(x==1)
    {
        aragaz *a;
        cout<<"Tip arzatoare: "; cin>>tp;
        a=new aragaz(1,prod,pr,tp);
        el=a;
        l.adaugare(a);
    }
}

void lista::afisare()
{
    electrocasnice *el;
    el=head;
    if(!el)
    cout<<"Lista este vida!"<<endl;
    else
    {
        while(el)
        {
        el->afisare();
        el=el->urm;
        }
    } 
}

void lista::cautare()
{
    electrocasnice *el=head;
    aragaz *a;
    string tip_arz,tp;
    cout<<"Tipul de arzatoare dupa care doriti sa cautati: ";
    cin>>tip_arz;
    while(el)
    {
        if(el->tip_derivat==1)
        {
            a=(aragaz *)el;
            if(a->tip==tip_arz)
            a->afisare();
        }
        el=el->urm;
    }

}

void lista::fisier()
{
    electrocasnice *el=head;
    masina *m;
    aragaz *a;
    ofstream fis;
    fis.open("Iesiri.txt");
    if(fis.is_open())
    {
        while(el)
        {
            if(el->tip_derivat==0)
            {
                m=(masina *)el;
                fis<<"Producator: "<<m->producator<<endl;
                fis<<"Pret: "<<m->pret<<endl;
                fis<<"Nr de programe: "<<m->nr<<endl;
            }

            if(el->tip_derivat==1)
            {
                a=(aragaz *)el;
                fis<<"Producator: "<<a->producator<<endl;
                fis<<"Pret: "<<a->pret<<endl;
                fis<<"Tip arzator: "<<a->tip<<endl;
            }
            el=el->urm;
        }
        fis.close();
    }
    else
    {
        cout<<"Nu s-a putut deschide fisierul!"<<endl;
    }
    
}

int main()
{
    int opt;
    lista l;
    l.head=NULL;
    do
    {
        cout<<endl;
        cout<<"1.Citire fisier"<<endl;
        cout<<"2.Introducere 0"<<endl;
        cout<<"3.Introducere 1"<<endl;
        cout<<"4.Afisare"<<endl;
        cout<<"5.Cautare"<<endl;
        cout<<"6.Salvare in fisier"<<endl;
        cout<<"0.Iesire"<<endl;
        cout<<"Optiunea dvs: ";
        cin>>opt;
        switch(opt)
        {
            case 1:
            l.citire(l);
            break;
            case 2:
            introducere(l,0);
            break;
            case 3:
            introducere(l,1);
            break;
            case 4:
            l.afisare();
            break;
            case 5:
            l.cautare();
            break;
            case 6:
            l.fisier();
            break;
        }
    }while(1);
}