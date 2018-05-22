#include "complex.h"

complex::complex(double a,double b)
{
    re=a;im=b;
}

complex::complex(const complex& a)
{
    re=a.re;im=a.im;
}

void complex::setre(double x){re=x;}
void complex::setim(double x){im=x;}
double complex::getre(){return re;}
double complex::getim(){return im;}

complex operator*(double a, complex b)
{
  complex c;
  c.re=a*b.re; c.im=a*b.im;
  return c;
}
complex operator*(complex a, complex b)
{
  complex c;
  c.re=a.re*b.re-a.im*b.im; c.im=a.im*b.re+a.re*b.im;
  return c;
}
complex operator*(complex a, double b)
{
  complex c;
  c.re=a.re*b; c.im=a.im*b;
  return c;
}

complex operator/(double a, complex b)
{
  complex c;
  if(b==c)
    return c;
    c.re=(a*b.re)/(b.re*b.re+b.im*b.im); c.im=(-a*b.im)/(b.re*b.re+b.im*b.im);
  return c;
}
complex operator/(complex a, complex b)
{
  complex c;
  if(b==c)
    return c;
  c.re=(a.re*b.re+a.im*b.im)/(b.re*b.re+b.im*b.im); c.im=(a.im*b.re-a.re*b.im)/(b.re*b.re+b.im*b.im);
  return c;
}
complex operator/(complex a, double b)
{
  complex c;
  if(b==0)
    return c;
  c.re=a.re/b; c.im=a.im/b;
  return c;
}


complex operator+(complex a)
{
  complex c;
  c.re=a.re; c.im=a.im;
  return c;
}
complex operator-(complex a)
{
  complex c;
  if(a==c)
    return c;
  c.re=-a.re; c.im=-a.im;
  return c;
}
complex operator+(double a, complex b)
{
  complex c;
  c.re=a+b.re; c.im=b.im;
  return c;
}
complex operator+(complex a, complex b)
{
  complex c;
  c.re=a.re+b.re; c.im=a.im+b.im;
  return c;
}
complex operator+(complex a, double b)
{
  complex c;
  c.re=a.re+b; c.im=a.im;
  return c;
}

complex operator-(double a, complex b)
{
  complex c;
  c.re=a-b.re; c.im=-b.im;
  return c;
}
complex operator-(complex a, complex b)
{
  complex c;
  c.re=a.re-b.re; c.im=a.im-b.im;
  return c;
}
complex operator-(complex a, double b)
{
  complex c;
  c.re=a.re-b; c.im=a.im;
  return c;
}

complex& operator+=(complex&a,complex b)
{
    a=a+b;
    return a;
}

complex& operator+=(complex&a,double b)
{
    a=a+b;
    return a;
}

complex& operator-=(complex&a,complex b)
{
    a=a-b;
    return a;
}

complex& operator-=(complex&a,double b)
{
    a=a-b;
    return a;
}

complex& operator*=(complex&a,complex b)
{
    a=a*b;
    return a;
}

complex& operator*=(complex&a,double b)
{
    a=a*b;
    return a;
}

complex& operator/=(complex&a,complex b)
{
    a=a/b;
    return a;
}

complex& operator/=(complex&a,double b)
{
    a=a/b;
    return a;
}

int fact(int a)
{
    int p=1;
    if(a>=1)
    {
        for(int i=1;i<=a;i++)
            p=p*i;
        return p;
    }
    else return 1;
}

int comb(int n,int k)
{
    int result = fact(n) / (fact(n-k) * fact(k));
    return result;
}

complex operator^(complex a,int b)
{
    int i;
    complex c(0,0);
    for(i=0;i<=b;i=i+2)
        c.re=c.re+comb(b,i)*pow(-1,i/2)*pow(a.re,b-i)*pow(a.im,i);
    for(i=1;i<=b;i=i+2)
        c.im=c.im+comb(b,i)*pow(-1,(i-1)/2)*pow(a.re,b-i)*pow(a.im,i);
    a=c;
    return c;
}

bool operator==(complex a,complex b)
{
    if(a.re==b.re && a.im==b.im)
        return 1;
    return 0;
}

bool operator==(complex a,double b)
{
    if(a.re==0 && a.im==b)
        return 1;
    return 0;
}

bool operator!=(complex a,complex b)
{
    if(a.re==b.re && a.im==b.im)
        return 0;
    return 1;
}

bool operator!=(complex a,double b)
{
    if(a.re==0 && a.im==b)
        return 0;
    return 1;
}

double abs(complex a)
{
    return sqrt(a.re*a.re+a.im*a.im);
}

complex sqrt(complex a)
{
    complex c;
    c.re=sqrt((a.re+sqrt(a.re*a.re+a.im*a.im))/2);
    if(a.im<0)
    c.im=-sqrt((-a.re+sqrt(a.re*a.re+a.im*a.im))/2);
    else
    c.im=sqrt((-a.re+sqrt(a.re*a.re+a.im*a.im))/2);
    return c;
}

istream& operator>>(istream &s, complex &a){
  double x,y;
  s>>x>>y; a.re=x; a.im=y;
  return s;
}

ostream& operator<<(ostream &s,const complex &a){
  if(a.re)
  {
     if(a.im<0)
     {
         if(a.im==-1)
         {
             s<<a.re<<"-i";
             return s;
         }
         s<<a.re<<"-i*"<<-a.im;
         return s;
     }
     if(a.im>0)
     {
        if(a.im==1)
         {
             s<<a.re<<"+i";
             return s;
         }
         s<<a.re<<"+i*"<<a.im;
         return s;
     }
  }
     if(a.im<0)
     {
         if(a.im==-1)
         {
             s<<"-i";
             return s;
         }
         s<<"-i*"<<-a.im;
         return s;
     }
     if(a.im>0)
     {
        if(a.im==1)
         {
             s<<"i";
             return s;
         }
         s<<"i*"<<a.im;
         return s;
     }
  s<<a.re;
  return s;
}

void complex::operator=(complex a)
{
    re=a.re;
    im=a.im;
}

