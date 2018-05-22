#include "vector_complex.h"
#include <complex.h>

vector_complex::vector_complex(int a)
{
    dim=a;
    elem=new complex[a];
}

vector_complex::~vector_complex()
{
    delete []elem;
}

vector_complex::vector_complex(const vector_complex& a)
{
    int i;
    dim=a.dim;
    elem=new complex[dim];
    for(i=0;i<dim;i++)
        elem[i]=a.elem[i];
}

istream& operator>>(istream &s,vector_complex &a)
{
  int i;
  cout<<"dimensiune vector: ";
  cin>>i;
  a.~vector_complex();
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

ostream& operator<<(ostream &o, vector_complex &a)
{
  int i;
  for(i=0;i<a.dim;i++)
    o<<a.elem[i]<<" ";
  return o;
}

void vector_complex::operator=(const vector_complex &b )
{
    int i;
    this->~vector_complex();
    dim=b.dim;
    elem=new complex[dim];
    for(i=0;i<dim;i++)
        this->elem[i]=b.elem[i];
}
