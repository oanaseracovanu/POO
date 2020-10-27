#include<iostream>
#include<string>

using namespace std;

class lista;

class produse
{
    private:
    int tip_derivat;
    string producator;
    int pret,rezolutie;
    produse *urm;
    public:
    produse(int t,string pro, int pr, int rez)
    {
        tip_derivat=t;
        producator=pro;
        pret=pr;
        rezolutie=rez;
        urm=NULL;
    }
    virtual void afisare()
    {
        cout<<"Producator: "<<producator<<endl;
        cout<<"Pret: "<<pret<<endl;
        cout<<"Rezolutie: "<<rezolutie<<endl;
    }
    friend class lista;
};

class rama:public produse
{
    private:
    int diagonala;
    string format;
    public:
    rama(int t,string pro, int pr, int rez, int diag, string f):produse(t,pro,pr,rez)
    {
        diagonala=diag;
        format=f;
    }
    void afisare()
    {
        produse::afisare();
        cout<<"Diagonala: "<<diagonala<<endl;
        cout<<"Format: "<<format<<endl;
    }
    friend class lista;
};

class aparat:public produse
{
    private:
    string t_ap,senzor;
    public:
    aparat(int t,string pro, int pr, int rez, string ap, string sz):produse(t,pro,pr,rez)
    {
        t_ap=ap;
        senzor=sz;
    }
    void afisare()
    {
        produse::afisare();
        cout<<"Tip aparat: "<<t_ap<<endl;
        cout<<"Tip senzor: "<<senzor<<endl;
    }
    friend class lista;
};

class lista
{
    public:
    produse *head;
    void adaugare(produse *prod);
    void afisare_lista(int x);
};

void lista::adaugare(produse *prod)
{
    produse *p;
    p=head;
    if(p)
    {
        if(prod->producator==p->producator)
        {
            prod->urm=head;
            head=prod;
        }
        else
        {
            while(p->urm&&(p->urm)->producator==prod->producator)
            p=p->urm;
            prod->urm=p->urm;
            p->urm=prod;
        }  
    }
    else
    head=prod;
}

void introducere(lista &l, int x)
{
    string pro,form,t_ap,sz;
    int pr,rez,diag;
    produse *prod;

    cout<<"Producatorul: "; cin>>pro;
    cout<<"Pretul: "; cin>>pr;
    cout<<"Rezolutia: "; cin>>rez;
    if(x==0)
    {
        rama *rm;
        cout<<"Diagonala: "; cin>>diag;
        cout<<"Formatul de afisare: "; cin>>form;
        rm=new rama(1,pro,pr,rez,diag,form);
        prod=rm;
        l.adaugare(prod);
    }
    else if(x==1)
    {
        aparat *ap;
        cout<<"Tipul aparatului: "; cin>>t_ap;
        cout<<"Tipul senzorului: "; cin>>sz;
        ap=new aparat(2,pro,pr,rez,t_ap,sz);
        prod=ap;
        l.adaugare(prod);
    }
}

void lista::afisare_lista(int x)
{
    produse *prod;
    prod=head;
    if(!prod)
    cout<<"Lista este vida!"<<endl;
    else
    while(prod)
    {
        if(prod->tip_derivat==0)
        {
        prod->afisare();
        }
        prod=prod->urm;
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
        cout<<"1.Adaugare rame"<<endl;
        cout<<"2.Adaugare aparate"<<endl;
        cout<<"3.Afisare rame"<<endl;
        cout<<"4.Afisare aparate"<<endl;
        cout<<"5.Iesire"<<endl<<endl;
        cout<<"Optiunea dumneavoastra este: ";
        cin>>opt;
        switch(opt)
        {
            case 1:
            introducere(l,0);
            break;
            case 2:
            introducere(l,1);
            break;
            case 3:
            l.afisare_lista(0);
            break;
            case 4:
            l.afisare_lista(1);
            break;
            case 5:
            exit(0);
            break;
        }
    } while(1);
    
    return 0;
}