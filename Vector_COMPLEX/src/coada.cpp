#include "coada.h"


void coada::adaugare(complex t)
{
    coada s(dim+1);
    int i;
    for(i=0; i<dim; i++) s.elem[i]=elem[i];
    s.elem[i]=t;
    *this=s;
}

complex coada::stergere()
{
    complex a;
    if(dim)
    {
    coada s(dim-1);
    int i;
    for(i=1; i<dim; i++) s.elem[i-1]=elem[i];
    a=elem[0];
    *this=s;
    return a;
    }
    else
        cout<<"Coada e vida nu se poate sterge"<<endl;
    return a;
}

bool coada::pur_imaginar()
{
    int i;
    for(i=0;i<dim;i++)
        if(elem[i].getre()!=0)
            return 0;
    return 1;
}

istream& operator>>(istream &s,coada &a)
{
  int i;
  cout<<"dimensiune coada: ";
  cin>>i;
  a.~coada();
  a.dim=i;
  a.elem=new complex[i];
  complex d;
  for(i=0;i<a.dim;i++)
    {
        s>>d;
        a.elem[i]=d;
    }
  return s;
}

ostream& operator<<(ostream &o,const coada a)
{
  int i;
  for(i=0;i<a.dim;i++)
    o<<a.elem[i]<<" ";
  return o;
}
coada& coada::operator=(const coada &b )
{
    int i;
    this->~coada();
    dim=b.dim;
    elem=new complex[dim];
    for(i=0;i<dim;i++)
        this->elem[i]=b.elem[i];
    return *this;
}
