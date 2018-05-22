#include <iostream>
#include <complex.h>
#include <vector_complex.h>
#include <stiva.h>
#include <coada.h>
using namespace std;

int main()
{
    stiva *a;
    coada *b;

    int n,i;
    cout<<"n stive si cozi: "<<endl;
    cin>>n;

    a=new stiva[n];
    b=new coada[n];

    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++)
        cout<<a[i]<<endl;

    for(i=0;i<n;i++)
        cin>>b[i];

    for(i=0;i<n;i++)
        cout<<b[i]<<endl;
}

//virtuale la vector
//main cu n stive si cozi
//citire si afisare la stive si cozi
