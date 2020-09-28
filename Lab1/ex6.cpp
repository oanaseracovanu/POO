#include<iostream>

using namespace std;

class dreptunghi
{
    int lungime, latime;
    public:
    void setare_valori(int,int);
    int aria(void);
};

void dreptunghi::setare_valori(int x,int y)
{
    lungime=x;
    latime=y;
}

int dreptunghi::aria(void)
{
    return lungime*latime;
}

int main()
{
    dreptunghi d;
    int x,y;
    cout<<"Dati lungimea si latimea: ";
    cin>>x>>y;
    d.setare_valori(x,y);
    cout<<"Aria: "<<d.aria()<<endl;
    return 0;
}