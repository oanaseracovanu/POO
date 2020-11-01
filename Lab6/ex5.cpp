#include<iostream>
#include<string.h>

using namespace std;

class lista;

class produse
{
    string producator,denumire;
    int tip;
    produse *urm;
    public:
    produse(int t,string prod,string denum)
    {
        producator=prod;
        denumire=denum;
        tip=t;
        urm=NULL;
    }
    virtual void afisare_prod()
    {
        cout<<"Producator: "<<producator<<endl;
        cout<<"Denumire: "<<denumire<<endl<<endl;
    }
    friend class lista;
};

class creioane:public produse
{
    int mina;
    public:
    creioane(int t,string prod,string denum,int m):produse(t,prod,denum)
    {
        mina=m;
    }
    void afisare_creioane()
    {
        produse::afisare_prod();
        cout<<"Tip mina: "<<mina<<endl; 
    }
    friend class lista;
};

class pixuri:public produse
{
    string culoare;
    public:
    pixuri(int t,string prod,string denum,string cul):produse(t,prod,denum)
    {
        culoare=cul;
    }
    void afisare_pixuri()
    {
        produse::afisare_prod();
        cout<<"Culoare: "<<culoare<<endl;
    }
    friend class lista;
};

class lista
{
    public:
    produse *head;
    void adaugare(produse *pr);
    void afisare_lista(int x);
};

void lista::adaugare(produse *pr)
{
    produse *p;
    p=head;
    if(p)
    {
        if(pr->producator<p->producator)
        {
        pr->urm=head;
        head=pr;
        }
        else
        {
            while(p->urm&&(p->urm)->producator<pr->producator)
            {
                p=p->urm;
                pr->urm=p->urm;
                p->urm=pr;
            }
        }
    }
    else
    head=pr;
}

void lista::afisare_lista(int x)
{
    produse *pr;
    pr=head;
    if(!pr)
    {
        cout<<"Lista este vida!"<<endl;
    }
    else
    {
        while(pr)
        {
            if(pr->tip==x)
            pr->afisare_prod();
            pr=pr->urm;
        }

    }
}

class supraincarcare
{
    string producator,denumire;
    public:
    friend ostream &operator<<(ostream &out,supraincarcare &a);
    friend istream &operator>>(istream &in,supraincarcare &a);
    string get_producator()
    {
        return producator;
    }
    string get_denumire()
    {
        return denumire;
    }
};

ostream &operator<<(ostream &out,supraincarcare &a)
{
    cout<<"Se vor citi datele"<<endl<<endl;
    return out;
}

istream &operator>>(istream &in,supraincarcare &a)
{
    cout<<"Producatorul: ";
    cin>>a.producator;
    cout<<"Denumirea: ";
    cin>>a.denumire;
    return in;
}

void introducere(lista &l,int x)
{
    int t,m;
    string cul;
    produse *pr;
    supraincarcare sp;
    cout<<sp;
    cin>>sp;
    if(x==0)
    {
        creioane *cr;
        cout<<"Tip mina: ";
        cin>>m;
        cr=new creioane(0,sp.get_producator(),sp.get_denumire(),m);
        pr=cr;
        l.adaugare(pr);
    }
    else if (x==1)
    {
        pixuri *px;
        cout<<"Culoare: ";
        cin>>cul;
        px=new pixuri(1,sp.get_producator(),sp.get_denumire(),cul);
        pr=px;
        l.adaugare(pr);
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
        cout<<"1.Adaugare creioane"<<endl;
        cout<<"2.Adaugare pixuri"<<endl;
        cout<<"3.Afisare creioane"<<endl;
        cout<<"4.Afisare pixuri"<<endl;
        cout<<"0.Iesire"<<endl;
        cout<<"Optiunea dumneavoastra: ";
        cin>>opt;
        cout<<endl;
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
            case 0:
            exit(0);
            break;
        }
    }while(1);
    return 0;
}