#include<iostream>

using namespace std;

class exemplu
{
    int x,y;
    public:
    void initializare(int a,int b)
    {
        x=a;
        y=b;
    }
    
    void afisare()
    {
        cout<<"Nr sunt: "<<x<<" "<<y<<endl;
    }
};

int main()
{
    exemplu ex;
    int a,b;
    cout<<"Dati cele 2 nr: ";
    cin>>a>>b;
    ex.initializare(a,b);
    ex.afisare();
    return 0;
}