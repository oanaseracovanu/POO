#include<iostream>

using namespace std;

class forma
{
    public:
    
    void latime(int l)
    {
        lat=l;
    }
    
    void inaltime(int i)
    {
        inal=i;
    }

    protected:
    int lat,inal;
};

class dreptunghi:public forma
{
    public:
    int aria()
    {
        return lat*inal;
    }
};

int main()
{
    dreptunghi d;
    d.inaltime(5);
    d.latime(6);
    cout<<"Aria: "<<d.aria()<<endl;
    return 0;
}
