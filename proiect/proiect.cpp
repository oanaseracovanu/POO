#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class lista;

class telefoane //clasa de baza
{
    private:
    int pret,tip;
    string model;
    telefoane *urm;
    public:
    telefoane(int t,int pr,string m) //constructorul clasei de baza
    {
        tip=t;
        pret=pr;
        model=m;
    }
    virtual void afisare() //functia de afisare a elementelor din clasa de baza
    {
        cout<<"Pretul: "<<pret<<endl;
        cout<<"Modelul: "<<model<<endl;
    }
    friend class lista; //clasa lista este declarata friend la clasa de baza pentru a-i putea accesa campurile 
};

class samsung:public telefoane //prima clasa derivata
{
    private:
    string culoare;
    int dimensiune;
    public:
    samsung(int t,int pr,string m,string c,int d):telefoane(t,pr,m) //constructorul clasei derivate, ce contine atat elementele sale cat si elementele clasei de baza
    {
        culoare=c;
        dimensiune=d;
    }
    void afisare() //afisarea clasei de baza
    {
        telefoane::afisare(); //apelarea functiei virtuale de afisare din clasa de baza, pt a afisa elementele ei
        cout<<"Culoarea: "<<culoare<<endl;
        cout<<"Dimensiunea: "<<dimensiune<<endl;
    }
    friend class lista;
};

class iphone:public telefoane //a doua clasa derivata
{
    private:
    iphone *urmat;
    int an,garantie;
    public:
    iphone(int t,int pr,string m,int a,int g):telefoane(t,pr,m) //constructorul clasei derivate
    {
        an=a;
        garantie=g;
    }
    void afisare() //functia de afisare 
    {
        telefoane::afisare();
        cout<<"Anul aparitiei: "<<an<<endl;
        cout<<"Perioada de garantie: "<<garantie<<endl;
    }
    friend class lista;
};

class huawei:public telefoane //a treia clasa derivata
{
    private:
    int baterie,frecventa;
    public:
    huawei(int t,int pr,string m,int b,int f):telefoane(t,pr,m) //constructorul clasei derivate
    {
        baterie=b;
        frecventa=f;
    }
    void afisare() //functia de afisare
    {
        telefoane::afisare();
        cout<<"Capacitatea bateriei: "<<baterie<<endl;
        cout<<"Frecventa: "<<frecventa<<endl;
    }
    friend class lista;
};

class nokia:public telefoane //a patra clasa derivata
{
    private:
    string so;
    int camera;
    public:
    nokia(int t,int pr,string m,string os,int c):telefoane(t,pr,m) //constructorul clasei derivate
    {
        so=os;
        camera=c;
    }
    void afisare() //functia de afisare
    {
        telefoane::afisare();
        cout<<"Sistem de operare: "<<so<<endl;
        cout<<"Rezolutie camera: "<<camera<<endl;
    }
    friend class lista;
};

class lista //clasa lista unde declaram functiile ce urmeaza a fi folosite 
{
    public:
    telefoane *head; //capul listei
    void adaugare(telefoane *tel); 
    void citire(lista &l); //citire date din fisier
    void afisare(int x); //afisarea pe categorii a datelor
    void afisare_tot(); //afisarea tuturor datelor
    void stergere(); //stergerea unui element
    void ordonare(); 
    void salvare(); //salvarea datelor in fisier
    void schimba(); //modificarea unei inregistrari
    void afisare_sters(telefoane *t,int x); //afisarea inregistrarii ce urmeaza a fi stearsa
};

class overload //overload pentru operatorul +
{
    public:
    int pret=30; //pretul de inceput
    overload operator+(overload op) //cand apare + in main se executa functia de overload
    {
        overload oper; //variabila intoarsa dupa overload
        oper.pret=pret+sizeof(pret)+op.pret; //pret= 30+4+30
        return oper; //returnam variabila in care am facut overload
    }
};

class myexception //prima exceptie 
{
    public: 
    string str_what;
    int what;
    myexception() //constructor
    {
        this->str_what=""; //string
        what=0; //integer
    }
    myexception(string s,int e) //constructor -> incapsulare
    {
        str_what=s; 
        what=e;
    }
};

class myexception2 //exceptia 2
{
    public: 
    string str_what;
    string what;
    myexception2() //constructor
    {
        this->str_what=""; //string
        this->what=""; //string
    }
    myexception2(string s,string e) //constructor -> incapsulare
    {
        str_what=s;
        what=e;
    }
};

void lista::adaugare(telefoane *tel) 
{
    telefoane *t=head; 
    if(t) //daca lista nu e nula
    {
        if(tel->pret<t->pret) //sortam crescator dupa pret
        { 
            tel->urm=head; //nodul urmator ia valoarea nodului cu pretul mai mic
            head=tel; //head-ul -> nodul cu pretul mai mare
        }
        else
        {
            while(t->urm&&(t->urm)->pret<tel->pret) //daca mai avem nod si e mai mic decat nodul urmator iteram in lista
            t=t->urm; //daca sunt sortate iesim din while,daca nu trecem la nodul urmator
            tel->urm=t->urm;
            t->urm=tel; //nodul urmator este noul nod inserat
        }
    }
    else
    {
        head=tel; //daca lista este nula
    }
}

class supraincarcare 
{
    public:
    int pret;
    char model[20];
    friend ostream &operator<<(ostream &out,supraincarcare &a); //overload pentru afisare
    friend istream &operator>>(istream &in,supraincarcare &a); //overload pentru citire
};

ostream &operator<<(ostream &out,supraincarcare &a)
{
    cout<<"Datele vor fi citite"<<endl;
    return out;
}

istream &operator>>(istream &in,supraincarcare &a)
{
    int i;
    cout<<"Pret: ";
    cin>>a.pret;
    if(a.pret<0) //daca pretul introdus este negativ
    {
        //tratam exceptia
    try
    {
        throw myexception("Pretul trebuie sa fie pozitiv!\n",a.pret); //aruncam exceptia
    }
    catch(myexception e) //prindem exceptia
    { 
    do
    {
        cout<<"Pretul: ";
        cin>>a.pret;
    }while(a.pret<0); //repetam citirea pana se introduce un nr pozitiv
    }
    }
    cout<<"Modelul: "; 
    cin>>a.model;
    for(i=0;i<strlen(a.model);i++) //parcurgem fiecare caracter introdus
    if(a.model[i]=='0'||a.model[i]=='1'||a.model[i]=='2'||a.model[i]=='3'||a.model[i]=='4'||a.model[i]=='5'
    ||a.model[i]=='6'||a.model[i]=='7'||a.model[i]=='8'||a.model[i]=='9') //daca un caracter este cifra
    try 
    {
    throw myexception2("Modelul nu trebuie sa contina cifre!\n",a.model); //aruncam exceptia
    }
    catch(myexception2 e)
    {
       cout<<"Introduceti clasa modelului (doar litere): ";
       cin>>a.model; //introducem modelul cu mai multa grija
    }
    
    return in; //intoarcem datele citite 
}

void lista::citire(lista &l)
{
    telefoane *t;
    samsung *s;
    iphone *i;
    huawei *h;
    nokia *n;
    int x,dim,a,gar,bat,fr,rez;
    string cul,os;
    supraincarcare sp;
    ifstream fis("Telefoane.txt"); //deschidem fisierul
    if(fis.is_open())
    {
        while(!fis.eof())
        {
            //citim datele in functie de clasa din care apartin
            fis>>x;
            if(x==1)
            {
                cout<<sp;
                cin>>sp;    
                fis>>cul>>dim;
                s=new samsung(1,sp.pret,sp.model,cul,dim);
                t=s;
                l.adaugare(t);
            }
            if(x==2)
            {
                cout<<sp;
                cin>>sp;
                fis>>a>>gar;
                i=new iphone(2,sp.pret,sp.model,a,gar);
                t=i;
                l.adaugare(t);
           }
           if(x==3)
           {
               cout<<sp;
               cin>>sp;
               fis>>bat>>fr;
               h=new huawei(3,sp.pret,sp.model,bat,fr);
               t=h;
               l.adaugare(t);
           }
           if(x==4)
           {
               cout<<sp;
               cin>>sp;
               fis>>os>>rez;
               n=new nokia(4,sp.pret,sp.model,os,rez);
               t=n;
               l.adaugare(t);
           }     
        }
        if(fis.eof()) //afisam mesaj la sfarsitul citirii pentru a stii ca s-a efectuat
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

void lista::afisare(int x) //afisarea in functie de categoria trimisa ca parametru
{
    telefoane *t=head; //se incepe cu primul nod
    if(!t) //daca t=null
    cout<<"Lista este vida!"<<endl; //lista nu contine niciun element 
    else
    while(t) //atata timp cat nu se ajunge la finalul listei
    {
        if(t->tip==x) //verificam daca nodul apartine categoriei dorite
        {
            t->afisare(); //se afiseaza
            cout<<endl;
        }
         t=t->urm; //se avanseaza la urmatorul nod
    }
}

void lista::afisare_tot()
{
    telefoane *t=head; //se incepe cu primul nod
    if(!t) //daca t=null
    cout<<"Lista este vida!"<<endl; //lista nu contine noduri
    else
    while(t) //pana nu se ajunge la sfarsitul listei
    {
        t->afisare(); //se afiseaza nodul
        cout<<endl;
        t=t->urm; //se trece la nodul urmator
    }
}

void lista::afisare_sters(telefoane *t,int x)
{
    samsung *s; iphone *i; huawei *h; nokia *n;
    ofstream fis;
    fis.open("Sters.txt"); //deschidem fisierul
    if(fis.is_open())
    {
        //in functie de clasa din care s-a sters, afisam datele
            if(t->tip==1)
            {
                s=(samsung*)t;
                fis<<"Pret: "<<s->pret<<endl;
                fis<<"Model: "<<s->model<<endl;
                fis<<"Culoare: "<<s->culoare<<endl;
                fis<<"Dimensiune: "<<s->dimensiune<<endl;
            }
            if(t->tip==2)
            {
                i=(iphone*)t;
                fis<<"Pret: "<<i->pret<<endl;
                fis<<"Model: "<<i->model<<endl;
                fis<<"Anul aparitiei: "<<i->an<<endl;
                fis<<"Perioada de garantie: "<<i->garantie<<endl;
            }
            if(t->tip==3)
            {
                h=(huawei*)t;
                fis<<"Pret: "<<h->pret<<endl;
                fis<<"Model: "<<h->model<<endl;
                fis<<"Capacitate baterie: "<<h->baterie<<endl;
                fis<<"Frecventa: "<<h->frecventa<<endl;
            }
            if(t->tip==4)
            {
                n=(nokia*)t;
                fis<<"Pret: "<<n->pret<<endl;
                fis<<"Model: "<<n->model<<endl;
                fis<<"Sistem de operare: "<<n->so<<endl;
                fis<<"Rezolutie camera: "<<n->camera<<endl;
            }  
        fis.close();
    }
    else
    cout<<"Nu s-a putut deschide fisierul!"<<endl;
}

void lista::stergere()
{
	telefoane *p, *q;
    int pr;
    cout<<"Pretul dupa care doriti sa stergeti: ";
    cin>>pr; //citim pretul elementului pe care dorim sa il stergem
	p=q=head;
	if(p) //daca avem noduri in lista
	{
		while(p&&p->pret!=pr) //atata timp cat nu se gaseste pretul se continua iterarea in lista
		{
			q=p;
			p=p->urm;
		}
		if(p) 
		{
			if(p!=q) 
			{
                afisare_sters(p,p->tip); //afisam elementul pe care il stergem
				q->urm=p->urm; //pasam nodurile urmatoare
				delete p; //stergem elementul
			}
			else //in cazul in care suntem la inceputul listei
			{
                afisare_sters(p,p->tip); //afisam elementul pe care il stergem
				head=p->urm; //head-ul devine elementul urmator
				delete p; //stergem nodul
			}
		}
		else
			cout<<"Pretul nu exista in lista!";
	}
	else
		cout<<"Lista este vida!";
}

void lista::schimba()
{
    telefoane *t=head;
    while(t) //atata timp cat avem noduri 
    {
        if(t->pret>2000) //daca pretul elementului este mai mare de 2000
        t->pret=t->pret+150; //adaugam 150 la pretul initial
        t=t->urm; //trecem la nodul urmator
    }
}

void lista::salvare()
{
    telefoane *t=head;
    samsung *s;
    iphone *i;
    huawei *h;
    nokia *n;
    ofstream fis;
    fis.open("Iesiri.txt"); //deschidem fisierul
    if(fis.is_open())
    {
        while(t)
        { 
            //afisam elementele in functie de clasa
            if(t->tip==1)
            {
                s=(samsung*)t;
                fis<<endl<<"Pret: "<<s->pret<<endl;
                fis<<"Model: "<<s->model<<endl;
                fis<<"Culoare: "<<s->culoare<<endl;
                fis<<"Dimensiune: "<<s->dimensiune<<endl;
            }
            if(t->tip==2)
            {
                i=(iphone*)t;
                fis<<endl<<"Pret: "<<i->pret<<endl;
                fis<<"Model: "<<i->model<<endl;
                fis<<"Anul aparitiei: "<<i->an<<endl;
                fis<<"Perioada de garantie: "<<i->garantie<<endl;
            }
            if(t->tip==3)
            {
                h=(huawei*)t;
                fis<<endl<<"Pret: "<<h->pret<<endl;
                fis<<"Model: "<<h->model<<endl;
                fis<<"Capacitate baterie: "<<h->baterie<<endl;
                fis<<"Frecventa: "<<h->frecventa<<endl;
            }
            if(t->tip==4)
            {
                n=(nokia*)t;
                fis<<endl<<"Pret: "<<n->pret<<endl;
                fis<<"Model: "<<n->model<<endl;
                fis<<"Sistem de operare: "<<n->so<<endl;
                fis<<"Rezolutie camera: "<<n->camera<<endl;
            }
            t=t->urm;
        }
        fis.close();
    }
    else
    cout<<"Nu s-a putut deschide fisierul!"<<endl;
}

void lista::ordonare()
{
    telefoane *t;
    int ord;
    do
    {
        t=head;
        ord=1;
        while(t->urm) //cat sunt noduri
        {
            if(t->pret==t->urm->pret) //daca elementele au acelasi pret
            if(t->model>t->urm->model) //dar modelul este mai mare (alfabetic) decat la nodul urmator
            {
                //interschimba
                string aux=t->model;
                t->model=t->urm->model;
                t->urm->model=aux;
                ord=0;
            }
            t=t->urm; //continua 
            
        }

    } while(ord==0); //pana cand totul este sortat
    
}

int main()
{
    lista l;
    l.head=NULL;
    int opt,var,x;
    overload obj1,obj2;
    overload obj3=obj1+obj2;
    cout<<"Pretul dupa overload: "<<obj3.pret<<endl; //overload-ul operatorului +
    do
    {
        cout<<endl;
        cout<<"0.Iesire"<<endl;
        cout<<"1.Introducere"<<endl;
        cout<<"2.Afisare"<<endl;
        cout<<"3.Stergere dupa pret"<<endl;
        cout<<"4.Adaugarea a 150 de lei la pretul telefoanelor>2000\n";
        cout<<"5.Ordonare dupa model a telefoanelor cu acelasi pret\n";
        cout<<"6.Afisare in fisier"<<endl;
        cout<<"Optiunea dumneavostra: ";
        cin>>opt; 
        switch(opt)
        {
            case 0:
            exit(0);
            break;
            case 1:
            l.citire(l);
            break;
            case 2:
            cout<<"Doriti sa afisati toate produsele -0 sau produsele dintr-o categorie -1? ";
            cin>>var;
            if(var==0)
            {
                l.afisare_tot();
            }
            if(var==1)
            {
                cout<<"Din ce categorie doriti sa afisati? "<<endl;
                cout<<"1-Samsung, 2-iPhone, 3-Huawei, 4-Nokia ";
                cin>>x;
                l.afisare(x);
            }
            break;
            case 3:
            l.stergere();
            break;
            case 4:
            l.schimba();
            break;
            case 5:
            l.ordonare();
            break;
            case 6:
            l.salvare();
            break;
            default:
            cout<<"Optiune gresita!"<<endl;
        }
    } while(1);
    return 0;
}