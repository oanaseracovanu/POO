#include<iostream>
#include<fstream>
 
using namespace std; 

class lista;

class electronice
{
    private:
    int dimensiune,tip;
    electronice *urm;
    public:
    electronice(int t,int dim)
    {
        tip=t;
        dimensiune=dim;
    }
    virtual void afisare()
    {
        cout<<"Dimensiunea: "<<dimensiune<<endl;
    }
    friend class lista;
};

class tablete:public electronice
{
    private:
    int pret;
    public:
    tablete(int t,int dim,int pr):electronice(t,dim)
    {
        pret=pr;
    }
    void afisare()
    {
        electronice::afisare();
        cout<<"Pret: "<<pret<<endl;
    }
    friend class lista;
    
};

class smartphone:public electronice
{
    private:
    string so;
    public:
    smartphone(int t,int dim,string s):electronice(t,dim)
    {
        so=s;
    }
    void afisare()
    {
        electronice::afisare();
        cout<<"Sistem de operare: "<<so<<endl;
    }
    friend class lista;

};

class lista
{
    public:
    electronice *head;
    void adaugare(electronice *el);
    void citire(lista &l);
    void afisare();
    void afisare_fisier();
    void interval();
    void stergere();
};

void lista::adaugare(electronice *el)
{
    electronice *e=head;
    if(e) 
    {
        if(!el)
    {
		el->urm=head;
        head=el;
    }
	else 
    {
        while(e->urm)
        e=e->urm;
		el->urm=e->urm;
        e->urm=el;
	}
    }
    else
    head=el;
}

class supraincarcare
{
    public:
    int dimensiune; 
    friend ostream &operator<<(ostream &out, supraincarcare &a);
    friend istream &operator>>(istream &in,supraincarcare &a);

};

ostream &operator<<(ostream &out,supraincarcare &a)
{
    cout<<"Datele vor fi citite"<<endl;
    return out;
}

istream &operator>>(istream &in,supraincarcare &a)
{
    cout<<"Dimensiunea: ";
    cin>>a.dimensiune;
    return in;
}

void introducere(lista &l,int x)
{
    int pr;
    string s;
    supraincarcare sp;
    cout<<sp;
    cin>>sp;
    electronice *el;
    if(x==0)
    {
        tablete *tb;
        cout<<"Pretul tabletei: "; 
        cin>>pr;
        tb=new tablete(0,sp.dimensiune,pr);
        el=tb;
        l.adaugare(el);
    }
    if(x==1)
    {
        smartphone *sm;
        cout<<"Sistemul de operare al smartphone-ului: ";
        cin>>s;
        sm=new smartphone(1,sp.dimensiune,s);
        el=sm;
        l.adaugare(el);
    }
}

void lista::afisare_fisier()
{
    electronice *el=head;
    tablete *tb;
    smartphone *sm;
    ofstream fis;
    fis.open("Fisier.txt");
    if(fis.is_open())
    {
        while(el)
        {
        if(el->tip==0)
            {
                tb=(tablete *)el;
                fis<<"Dimensiunea: "<<tb->dimensiune<<endl;
                fis<<"Pretul: "<<tb->pret<<endl;
            }
        if(el->tip==1)
        {
            sm=(smartphone *)el;
            fis<<"Dimensiunea: "<<sm->dimensiune<<endl;
            fis<<"Sistemul de operare: "<<sm->so<<endl;
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

void lista::afisare()
{
    electronice *el;
    el=head;
    if(!el)
    cout<<"Lista este vida!"<<endl;
    else
    {
        while(el)
        {
        el->afisare();
        cout<<endl;
        el=el->urm;
        }
    } 
}

void lista::interval()
{
    int dim_min,dim_max;
    cout<<"Care este dimensiunea minima? ";
    cin>>dim_min;
    cout<<"Care este dimensiunea maxima? ";
    cin>>dim_max;
    electronice *el=head;
    while(el)
    {
        if(el->dimensiune>dim_min && el->dimensiune<dim_max)
        el->afisare();
        el=el->urm;
    }

}

void lista::stergere()
{
    electronice *p, *q;
    int dim;
    cout<<"Dimensiunea dupa care doriti sa stergeti: ";
    cin>>dim;
	p=q=head;
	if(p)
	{
		while(p && p->dimensiune!=dim)
		{
			q=p;
			p=p->urm;
		}
		if(p)
		{
			if(p!=q)
			{
				q->urm=p->urm;
				delete p;
			}

			else
			{
				head=p->urm;
				delete p;
			}
		}
		else
			cout<<"Dimensiunea nu exista in lista!";
	}
	else
		cout<<"Lista este vida!";
}

int main()
{
    int opt;
    lista l;
    l.head=NULL;
    do
    {
        cout<<endl;
        cout<<"1.Introducere tableta lista"<<endl;
        cout<<"2.Introducere smartphone in lista"<<endl;
        cout<<"3.Afisare in fisier"<<endl;
        cout<<"4.Afisare ecran"<<endl;
        cout<<"5.Afisare produse din interval"<<endl;
        cout<<"6.Stergere in functie de dimensiune"<<endl;
        cout<<"0.Iesire"<<endl;
        cout<<"Optiunea dumneavoastra: ";
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
            l.afisare_fisier();
            break;
            case 4:
            l.afisare();
            break;
            case 5:
            l.interval();
            break;
            case 6:
            l.stergere();
            break;
            case 0:
            exit(0);
            break;
        }
    }while(1);
    return 0;
}