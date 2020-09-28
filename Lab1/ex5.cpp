#include<iostream>

using namespace std;

int negativ(int &i)
{
    return -i;
}

int main()
{
    int nr;
    cout<<"Dati nr: ";
    cin>>nr;
    cout<<"Valoarea negativa: "<<negativ(nr)<<endl;
    return 0;
}