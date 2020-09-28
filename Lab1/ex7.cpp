#include<iostream>

using namespace std;

inline int minim(int x,int y)
{
    return x<y? x:y;
}

int main()
{
    int x,y;
    cout<<"Dati cele 2 numere: ";
    cin>>x>>y;
    cout<<"Minimul este: "<<minim(x,y)<<endl;
    return 0;
}