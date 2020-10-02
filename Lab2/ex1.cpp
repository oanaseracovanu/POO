#include<iostream>

using namespace std;

class dreptunghi
{
    int lungime,latime;
    public:
    dreptunghi(int, int);
    int arie(void)
    {
        return lungime*latime;
    }
};

dreptunghi::dreptunghi(int x,int y)
{
    lungime=x;
    latime=y;
}

int main()
{
    dreptunghi dr1(2,3);
    dreptunghi dr2(5,2);
    cout<<"Aria primului dreptunghi: "<<dr1.arie()<<endl;
    cout<<"Aria celui de-al doielea dreptunghi: "<<dr2.arie()<<endl;
    return 0;
}