#include<iostream>


using namespace std;

int main()
{
    int nr,s=0,p=1;
    cout<<"Dati numarul: "; 
    cin>>nr;
    while(nr!=0)
    {
        if(nr%2==0)
        s=s+nr;
        else
        p=p*nr;
        cout<<"Dati numarul: ";
        cin>>nr;
    }
    cout<<"Suma nr pare: "<<s<<endl<<"Produsul nr impare: "<<p;

    return 0;
}