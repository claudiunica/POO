#include "stiva.h"


void stiva::adaugare(complex t)
{
    stiva s(dim+1);
    int i;
    for(i=0; i<dim; i++) s.elem[i]=elem[i];
    s.elem[i]=t;
    *this=s;
}

complex stiva::stergere()
{
    complex a;
    if(dim)
    {
    stiva s(dim-1);
    int i;
    for(i=0; i<dim-1; i++) s.elem[i]=elem[i];
    a=elem[i];
    *this=s;
    return a;
    }
    else
        cout<<"Stiva e vida nu se poate sterge"<<endl;
    return a;
}

bool stiva::pur_imaginar()
{
    int i;
    for(i=0;i<dim;i++)
        if(elem[i].getre()!=0)
            return 0;
    return 1;

}

istream& operator>>(istream &s,stiva &a)
{
  int i;
  cout<<"dimensiune stiva: ";
  cin>>i;
  a.~stiva();
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

ostream& operator<<(ostream &o,const stiva a)
{
  int i;
  for(i=0;i<a.dim;i++)
    o<<a.elem[i]<<" ";
  return o;
}

stiva& stiva::operator=(const stiva &b )
{
    int i;
    this->~stiva();
    dim=b.dim;
    elem=new complex[dim];
    for(i=0;i<dim;i++)
        this->elem[i]=b.elem[i];
    return *this;
}
