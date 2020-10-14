#include<iostream>

using namespace std;

class persoana
{
    string nume,prenume;
    int varsta;
    public:
    persoana(){}
    persoana(string n,string pr,int v)
    {
        persoana::nume=n;
        persoana::prenume=pr;
        persoana::varsta=v;
    }
    void afisare_persoana()
    {
        cout<<endl<<"Nume: "<<nume<<endl;
        cout<<"Varsta: "<<varsta<<endl;
        cout<<"Prenume: "<<prenume<<endl;
    }
    string returnare_nume()
    {
        return persoana::nume;
    }
    string returnare_prenume()
    {
        return persoana::prenume;
    }
};

class student:public persoana
{
    int nr_mat;
    public:
    student(){}
    student(string n,string pr,int v,int m):persoana(n,pr,v)
    {
        student::nr_mat=m;
    }
    void afisare_student()
    {
       persoana::afisare_persoana();
        cout<<"Numar matricol: "<<nr_mat<<endl;
    }

};

class licenta: public student
{
    string specializare;
    int an;
    public:
    licenta(){}
    licenta(string n,string pr,int v,int m,string s,int a):student(n,pr,v,m)
    {
        licenta::specializare=s;
        licenta::an=a;
    }
    void afisare_licenta()
    {
        student::afisare_student();
        cout<<"Specializare: "<<specializare<<endl<<"An de studiu: "<<an<<endl;
    }
   string returnare_specializare()
   {
       return licenta::specializare;
   }
};

class master:public student
{
    string program;
    public:
    master(){}
    master(string n,string pr,int v,int m,string p):student(n,pr,v,m)
    {
        master::program=p;
    }
    void afisare_master()
    {
       student::afisare_student();
        cout<<"Program de master: "<<program<<endl;
    }
    string returnare_program()
    {
        return master::program;
    }
};

class doctorand:public student
{
    string titlu;
    public:
    doctorand(){}
    doctorand(string n,string pr,int v,int m,string t):student(n,pr,v,m)
    {
        doctorand::titlu=t;
    }
    void afisare_doctorand()
    {
        student::afisare_student();
        cout<<"Titlu lucrare de doctorat: "<<titlu<<endl;
    }
    string returnare_doctorand()
    {
        return doctorand::titlu;
    }
};

int main()
{
    string n,t,p,s,pr;
    int v,m,a,opt,nr,nr1=0,nr2=0,nr3=0,i,tip;
    licenta lic[20]; master mas[20]; doctorand doc[20];
    do
    {
        cout<<endl<<"1.Introducere studenti "<<endl;
        cout<<"2.Afisare "<<endl;
        cout<<"3.Cautare "<<endl;
        cout<<"4.Stergere "<<endl;
        cout<<"0.Iesire "<<endl;
        cout<<"Optiunea dumneavoastra: ";
        cin>>opt;
        switch(opt)
        {
            case 1:
            cout<<endl<<"Cati studenti doriti sa introduceti? "; cin>>nr;
            for(i=0;i<nr;i++)
            {
                cout<<endl<<"Numele: "; cin>>n;
                cout<<"Prenumele: "; cin>>pr;
                cout<<"Varsta "; cin>>v;
                cout<<"Nr matricol: "; cin>>m;
                cout<<"1-Licenta, 2-Master, 3-Doctorand "; cin>>tip;
                switch(tip)
                {
                    case 1:
                    cout<<"Specializarea: "; cin>>s;
                    cout<<"Anul de studiu: "; cin>>a;
                   lic[nr1]=licenta(n,pr,v,m,s,a);
                   nr1++;
                    break;
                    case 2:
                    cout<<"Programul de master: "; cin>>p;
                    mas[nr2]=master(n,pr,v,m,p);
                    nr2++;
                    break;
                    case 3:
                    cout<<"Titlul lucrarii de doctorat: "; cin>>t;
                    doc[nr3]=doctorand(n,pr,v,m,t);
                    nr3++;
                    break;
                }
                
            }
            break;

            case 2:
            for(i=0;i<nr1;i++)
            lic[i].afisare_licenta();
            for(i=0;i<nr2;i++)
            mas[i].afisare_master();
            for(i=0;i<nr3;i++)
            doc[i].afisare_doctorand();
            break;

            case 3:
            cout<<"Din ce domeniu doriti sa cautati? "<<endl<<"1-Licenta 2-Master 3-Doctorand "<<endl;
            cin>>tip;
            switch(tip)
            {
                case 1:
                cout<<"Numele si prenumele persoanei pe care o cautati? "; cin>>n; cin>>pr;
                for(i=0;i<nr1;i++)
                if((n.compare(lic[i].returnare_nume())==0)&&(pr.compare(lic[i].returnare_prenume()))==0)
                {
                    cout<<"Studentul a fost gasit! "<<endl;
                    lic[i].afisare_licenta();
                }
                else
                cout<<"Studentul nu a fost gasit! "<<endl;
                break;
                case 2:
                cout<<"Numele si prenumele persoanei pe care o cautati? "; cin>>n; cin>>pr;
                for(i=0;i<nr2;i++)
                if((n.compare(mas[i].returnare_nume())==0)&&(pr.compare(mas[i].returnare_prenume())==0))
                {
                    cout<<"Studentul a fost gasit! "<<endl;
                    mas[i].afisare_master();
                }
                else
                    cout<<"Studentul nu a fost gasit! "<<endl;
                
                break;
                case 3:
                cout<<"Numele si prenumele persoanei pe care o cautati? "; cin>>n; cin>>pr;
                for(i=0;i<nr3;i++)
                if((n.compare(doc[i].returnare_nume())==0)&&(pr.compare(doc[i].returnare_prenume()))==0)
                {
                    cout<<"Studentul a fost gasit! "<<endl;
                    doc[i].afisare_doctorand();
                }
                else
                cout<<"Studentul nu a fost gasit! "<<endl;
                break;
            }
            break;
            
            case 4:
            cout<<"Din ce domeniu doriti sa stergeti? "<<endl<<"1-Licenta 2-Master 3-Doctorand "<<endl;
            cin>>tip;
            switch(tip)
            {
                case 1:
                cout<<"Numele si prenumele persoanei pe care o stergeti "; cin>>n; cin>>pr;
                for(i=0;i<nr1;i++)
                if((n.compare(lic[i].returnare_nume())==0)&&(pr.compare(lic[i].returnare_prenume())==0))
                {
                    for (int j=i;j<nr1;j++)
                    lic[j]=lic[j + 1]; 
                    nr1--;
                }
                else
                    cout<<"Studentul nu a fost gasit, nu s-a efectuat stergere! "<<endl;
                break;
                case 2:
                cout<<"Numele si prenumele persoanei pe care o stergeti "; cin>>n; cin>>pr;
                for(i=0;i<nr2;i++)
                if((n.compare(mas[i].returnare_nume())==0)&&(pr.compare(mas[i].returnare_prenume())==0))
                {
                    for (int j=i;j<nr2;j++)
                    mas[j]=mas[j + 1]; 
                    nr2--;
                }
                else
                    cout<<"Studentul nu a fost gasit, nu s-a efectuat stergere! "<<endl;
                break;
                case 3:
                cout<<"Numele si prenumele persoanei pe care o stergeti "; cin>>n; cin>>pr;
                for(i=0;i<nr3;i++)
                if((n.compare(doc[i].returnare_nume())==0)&&(pr.compare(doc[i].returnare_prenume())==0))
                {
                    for (int j=i;j<nr3;j++)
                    doc[j]=doc[j + 1]; 
                    nr3--;
                }
                else
                    cout<<"Studentul nu a fost gasit, nu s-a efectuat stergere! "<<endl;
                break;
            }
            break;
            case 0:
            exit(0);
            break;
        }

    } while (1);
    return 0;
    
}