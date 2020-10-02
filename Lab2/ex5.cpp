#include<iostream>

using namespace std;

class dreptunghi
{
    int lungime,latime;
    public:
    void valori(int x,int y)
    {
        lungime=x;
        latime=y;
    }
    int aria(void)
    {
        return lungime*latime;
    }
};

int main()
{
    dreptunghi a,*b,*c;
    dreptunghi *d=new dreptunghi[2];
    a.valori(2,3);
    b=new dreptunghi;
    c=new dreptunghi;
    b->valori(1,1);
    c->valori(10,1);
    d->valori(1,2);
    d[1].valori(0,0);

    cout<<"Aria lui a: "<<a.aria()<<endl;
    cout<<"Aria lui b: "<<b->aria()<<endl;
    cout<<"Aria lui c: "<<c->aria()<<endl;
    cout<<"Aria lui d[0]: "<<d[0].aria()<<endl;
    cout<<"Aria lui d[1]: "<<d[1].aria()<<endl;
    return 0;
}