#include<iostream>

using namespace std;

int suma(int x,int y)
{
    return x+y;
}

float suma(float x,float y)
{
    return x+y;
}

int main()
{
    int x,y;
    float a,b;
    cout<<"Dati cele 2 numere intregi: ";
    cin>>x>>y;
    cout<<"Suma lor este: "<<suma(x,y)<<endl;
    cout<<"Dati cele 2 numere reale: ";
    cin>>a>>b;
    cout<<"Suma lor este: "<<suma(a,b)<<endl;
    return 0;
}