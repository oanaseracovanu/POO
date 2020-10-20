#include <iostream>
#include <string>

using namespace std;

class Monitor 
{
public:
	string producator;
	float diagonala, pret;
	Monitor(string pro, float d, float p)
	{
		producator = pro;
		diagonala = d;
		pret = p;
	}
	virtual void display() = 0;
};

class MonitoareLCD:public Monitor 
{
public:
	string tip_ecran, conectori;
	unsigned int timp;
	MonitoareLCD *head;
	MonitoareLCD *next;
	MonitoareLCD(string pro, float d, float p, string tip, string c, unsigned int t):Monitor(pro, d, p)
	{
		head = NULL;
		tip_ecran = tip;
		conectori = c;
		timp = t;
	}
	virtual void display();
	void adaugare();
    void stergere();
    void cautare();
};

class MonitoareLED:public Monitor 
{
public:
	string format, iluminare, boxe;
	MonitoareLED *head;
	MonitoareLED *next;
	MonitoareLED(string pro, float d, float p, string f, string il, string b) :Monitor(pro, d, p)
	{
		head = NULL;
		format = f;
		iluminare = il;
		boxe = b;
	}
	void display();
	void adaugare();
    void stergere_led();
    void cautare_led();
};

void MonitoareLCD::adaugare() 
{
	string producator, tip_ecran, conectori;
	float diagonala, pret;
	unsigned int timp;
	cin.get();
	cout << "Introduceti producatorul: "; getline(cin, producator);
	cout << "Introduceti tipul de ecran: "; getline(cin, tip_ecran);
	cout << "Introduceti conectorii: "; getline(cin, conectori);
	cout << "Introduceti diagonala: "; cin >> diagonala;
	cout << "Introduceti pret: "; cin >> pret;
	cout << "Introduceti timpul: "; cin >> timp;
	MonitoareLCD *p = new MonitoareLCD(producator, diagonala, pret, tip_ecran, conectori, timp);
	p->next = head;
	head = p;
}

void MonitoareLED::adaugare()
{
	string producator, iluminare, boxe, format;
	float diagonala, pret;
	cin.get();
	cout << "Introduceti producatorul: "; getline(cin, producator);
	cout << "Introduceti tipul de iluminare: "; getline(cin, iluminare);
	cout << "Introduceti boxele: "; getline(cin, boxe);
	cout << "Introduceti formatul: "; getline(cin, format);
	cout << "Introduceti diagonala: "; cin >> diagonala;
	cout << "Introduceti pret: "; cin >> pret;
	MonitoareLED *p = new MonitoareLED(producator, diagonala, pret, format, iluminare, boxe);
	p->next = head;
	head = p;
}

void MonitoareLCD::display()
{
	MonitoareLCD *p = head;
	while (p != NULL)
	{
		cout << "Producator: " << p->producator << endl;
		cout << "Tip ecran: " << p->tip_ecran << endl;
		cout << "Conectori: " << p->conectori << endl;
		cout << "Diagonala: " << p->diagonala << endl;
		cout << "Pretul: " << p->pret << endl;
		p = p->next;
	}
}

void MonitoareLED::display()
{
	MonitoareLED *p = head;
	while (p != NULL)
	{
		cout << "Producator: " << p->producator << endl;
		cout << "Iluminare: " << p->iluminare << endl;
		cout << "Boxe: " << p->boxe << endl;
		cout << "Diagonala: " << p->diagonala << endl;
		cout << "Pretul: " << p->pret << endl;
		p = p->next;
	}
}

void MonitoareLCD::stergere()
{
    MonitoareLCD *m=head,*sterg;
    float pr;
    cout<<"Pretul dupa care doriti sa stergeti: "; cin>>pr;
    if(head)
    {
        if(m->pret==pr)
        {
            sterg=head;
            head=sterg->next;
            delete sterg;
        }
        else
        {
        while(m->next&&((m->next)->pret!=pr))
        m=m->next;
        if(m->next==NULL) cout<<"Pretul nu exista in lista"<<endl;
        else if(m->next->pret==pr)
        {
            sterg=m->next;
            m->next=sterg->next;
            delete sterg;
        }
        }
    }
}

void MonitoareLED::stergere_led()
{
    MonitoareLED *m=head,*sterg;
    float pr;
    cout<<"Pretul dupa care doriti sa stergeti: "; cin>>pr;
    if(head)
    {
        if(m->pret==pr)
        {
            sterg=head;
            head=sterg->next;
            delete sterg;
        }
        else
        {
        while(m->next&&((m->next)->pret!=pr))
        m=m->next;
        if(m->next==NULL) cout<<"Pretul nu exista in lista"<<endl;
        else if(m->next->pret==pr)
        {
            sterg=m->next;
            m->next=sterg->next;
            delete sterg;
        }
        }
    }
}

void MonitoareLCD::cautare()
{
    MonitoareLCD *m=head;
    float pr;
    int i=1;
    cout<<"Pretul dupa care se cauta: "; cin>>pr;
    if(head)
    {
        if(m->pret==pr)
        cout<<"Pretul a fost gasit pe pozitia: "<<i<<endl;
        else
        {
            while(m->next)
            {
                i++;
                if(m->pret==pr)
                {
                cout<<"Pretul a fost gasit pe pozitia: "<<i<<endl;
                break;
                }
                else
                {
                    m=m->next;
                }
                if(m->next==NULL) cout<<"Pretul nu exista in lista"<<endl;
            }
        }
    }
}

void MonitoareLED::cautare_led()
{
    MonitoareLED *m=head;
    float pr;
    int i=1;
    cout<<"Pretul dupa care se cauta: "; cin>>pr;
    if(head)
    {
        if(m->pret==pr)
        cout<<"Pretul a fost gasit pe pozitia: "<<i<<endl;
        else
        {
            while(m->next)
            {
                i++;
                if(m->pret==pr)
                {
                cout<<"Pretul a fost gasit pe pozitia: "<<i<<endl;
                break;
                }
                else
                {
                    m=m->next;
                }
                if(m->next==NULL) cout<<"Pretul nu exista in lista"<<endl;
            }
        }
    }
}

int main()
{
	unsigned int opt,n;
	MonitoareLCD *lcd = new MonitoareLCD(" ", 0, 0, " ", " ", 0);
	MonitoareLED *led = new MonitoareLED(" ", 0, 0, " ", " ", " ");
	do {
		cout<< "1. Adaugare monitor LCD/LED"<<endl;
		cout<< "2. Afisare monitor LCD/LED"<<endl;
		cout<< "3. Stergere monitor LCD/LED"<<endl;
        cout<<"4. Cautare"<<endl;
		cout<<"0. Iesire"<<endl;
		cout<<"Optiunea: "; cin>>opt;
		switch (opt)
		{
		case 1:
			cout<<"1-LCD 2-LED"<<endl; cin>>n;
			if(n==1)
				lcd->adaugare();
			else
				led->adaugare();
			break;
		case 2:
			cout <<"1-LCD 2-LED"<<endl; cin>>n;
			if (n == 1)
				lcd->display();
			else
				led->display();
			break;
        case 3:
        cout<<"1-LCD 2-LED"<<endl; cin>>n;
        if(n==1)
        lcd->stergere();
        else
        led->stergere_led();
        break;
        case 4:
        cout<<"1-LCD 2-LED"<<endl; cin>>n;
        if(n==1)
        lcd->cautare();
        else
        led->cautare_led();
        break;
        case 0:
        exit(0);
        break;
        }

	} while (1);

	return 0;
}