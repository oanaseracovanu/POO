#include<iostream>

using namespace std;

class dreptunghi
{
    int *lungime,*latime;
    public:
    dreptunghi (int,int);
    ~dreptunghi();
    int arie()
    {
        return *lungime**latime;
    }

};

dreptunghi::dreptunghi(int x,int y)
{
    lungime=new int;
    latime=new int;
    *lungime=x;
    *latime=y;
}

dreptunghi::~dreptunghi()
{
    delete lungime;
    delete latime;
    cout<<"Am eliberat memoria"<<endl;
}

int main()
{
    dreptunghi dr1(2,3),dr2(4,9);
    cout<<"Aria primului dreptunghi este: "<<dr1.arie()<<endl;
    cout<<"Aria celui de-al doilea dreptunghi este: "<<dr2.arie()<<endl;
    dr1.~dreptunghi();
    dr2.~dreptunghi();
    return 0;
}

