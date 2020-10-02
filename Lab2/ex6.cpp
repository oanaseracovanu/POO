#include<iostream>

using namespace std;

class dreptunghi
{
    int lungime,latime;
    public:
    dreptunghi();
    dreptunghi(int,int);
    int aria(void)
    {
        return lungime*latime;
    }
};

dreptunghi::dreptunghi()
{
    lungime=3;
    latime=5;
}

dreptunghi::dreptunghi(int x,int y)
{
    lungime=x;
    latime=y;
}

int main()
{
    dreptunghi dr(1,2);
    dreptunghi dr1;
    cout<<"Aria primului dreptunghi: "<<dr.aria()<<endl;
    cout<<"Aria celui de-al doilea dreptunghi: "<<dr1.aria()<<endl;
    return 0;
}