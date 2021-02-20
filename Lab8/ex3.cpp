#include <iostream>
#include <fstream>

using namespace std;

class Telefon
{
private:
    int tip;
    string producator;
    string culoare;
public:
    Telefon(int tip ,string producator, string culoare)
    {
        Telefon::tip = tip;
        Telefon::producator = producator;
        Telefon::culoare = culoare;
    }

    int getTip()
    {
        return tip;
    }

    string getProducator()
    {
        return producator;
    }

    string getCuloare()
    {
        return culoare;
    }

    virtual void afisare()
    {
        cout<<"Producator : "<<producator<<endl;
        cout<<"Culoare : "<<culoare<<endl;
    }
};

class Fix:public Telefon
{
private:
    double dimensiune;
public:
    Fix(int tip, string producator, string culoare,double dimensiune):Telefon(tip,producator,culoare)
    {
        Fix::dimensiune = dimensiune;
    }

    void afisare() override 
    {
        Telefon::afisare();
        cout<<"Dimensiune : "<<dimensiune<<endl;
    }


};

class Mobil:public Telefon
{
private:
    string OS;
public:
    Mobil(int tip, string producator, string culoare, string OS):Telefon(tip, producator, culoare)
    {
        Mobil::OS = OS;
    }

    void afisare() override 
    {
        Telefon::afisare();
        cout<<"OS : "<<OS<<endl;
    }

    string getOS()
    {
        return OS;
    }

};

template <class T>
class Nod
{
private:
    T *valoare;
    Nod <T> *urm;
public:
    Nod(T *valoare)
    {
        Nod<T>::valoare=valoare;
    }
    T *getValoare()
    {
        return valoare;
    }
    Nod<T> *getUrm()
    {
        return urm;
    }
    void setare_urm(Nod <T> *urm)
    {
        Nod<T>::urm=urm;
    }
};

template <class T>
class Lista
{
private:
    Nod<T>*head;
    Nod<T>*tail;
public:
    Lista()
    {
        head=NULL;
        tail=NULL;
    }
    void adaugare(T *valoare)
    {
        Nod<T> *newNod=new Nod<T>(valoare);
        if(head==NULL)
        {
            head = newNod;
            return;
        } 
        else if(tail==NULL)
        {
            tail=newNod;
            head->setare_urm(tail);
            tail->setare_urm(NULL);
            return;
        } 
        else 
        {
            tail->setare_urm(newNod);
            tail=newNod;
            tail->setare_urm(NULL);
        }
    }

    void adaugare_ordonata(T *valoare)
    {
        Nod <T> *temp=NULL;
        if(head==NULL || head->getValoare()->getProducator() > valoare->getProducator())
        {
            temp=new Nod<T>(valoare);
            temp->setare_urm(head);
            head=temp;
            return;
        }

        temp = head;
        while (temp->getUrm() != NULL && temp->getUrm()->getValoare()->getProducator() < value->getProducator())
        {
            temp = temp->getUrm(); 
        }
        Nod <T> *newNod=new Nod<T>(valoare);
        newNod->setare_urm(temp->getUrm());
        temp->setare_urm(newNod);

    }

    void afisare()
    {
        Nod <T> *temp = head;
        while(temp!=NULL)
        {
            temp->getValoare()->afisare();
            temp=temp->getUrm();
        }
    }

    void cautare(string SO)
    {
        Nod <T> *temp=head;
        while (temp!=NULL) 
        {
            if(temp->getValoare()->getTip()==2) 
            {
            Mobil *obj=(Mobil*)temp->getValoare();
            if(obj->getOS()==SO)
                obj->afisare();
        }
            temp=temp->getUrm();
        }
    }


};
void inserare(Lista <Telefon> &lista)
{
    int tip;
    string producator;
    string culoare;
    cout<<"Dati tipul: ";
    cin>>tip;
    cout<<"Dati producatorul: ";
    cin>>producator;
    cout<<"Dati culoarea: ";
    cin>>culoare;
    if (tip==1)
    {
        double dimensiune;
        cout<<"Dati dimensiunea: ";
        cin>>dimensiune;
        Fix *fix=new Fix(tip, producator, culoare, dimensiune);
        lista.adaugare(fix);
    } 
    else if(tip==2)
    {
        string OS;
        cout<<"Dati OS: ";
        cin>>OS ;
        Mobil *mobil=new Mobil(tip, producator, culoare, OS);
        lista.adaugare(mobil);
    }
}

void incarcare(Lista <Telefon> &lista)
{
    ifstream file("input.txt");
    while (!file.eof()) 
    {
        int tip;
        string producator;
        string culoare;
        file>>tip;
        file>>producator;
        file>>culoare;
        if(tip == 1) 
        { 
            double dimensiune;
            file>>dimensiune;
            Fix *fix=new Fix(tip, producator, culoare, dimensiune);
            lista.adaugare(fix);
        } 
        else if(tip==2) 
        {
            string OS;
            file>>OS;
            Mobil *mobil=new Mobil(tip, producator, culoare, OS);
            lista.adaugare(mobil);
        } 
        else 
        {
            cout<<"Nu se poate adauga!"<<endl;
        }
    }

}



int main() 
{

    Lista <Telefon> lista;
    Mobil *mobil1=new Mobil(2,"bb","red1","android");
    Mobil *mobil2=new Mobil(2,"cc","red2","android");
    Mobil *mobil3=new Mobil(2,"aa","red3","android");
    lista.adaugare_ordonata(mobil1);
    lista.adaugare_ordonata(mobil2);
    lista.adaugare_ordonata(mobil3);
    lista.afisare();
    int opt;
    string caut;

    do 
    {
        cout<<endl;
        cout<<"1.Incarcare"<<endl;
        cout<<"2.Adaugare"<<endl;
        cout<<"3.Afisare"<<endl;
        cout<<"4.Cautare"<<endl;
        cout<<"0.Iesire"<<endl;
        cout<<"Optiunea dumneavoastra: ";
        cin>>opt;
        switch(opt) 
        {
            case 1:
                incarcare(lista);
                break;
            case 2:
                inserare(lista);
                break;
            case 3:
                lista.afisare();
                break;
            case 4:
                cout<<"OS de gasit: ";
                cin>>caut;
                lista.cautare(caut);
                break;
            case 0:
                exit(0);
                break;
        }


    }while(1);
    return 0;
}
