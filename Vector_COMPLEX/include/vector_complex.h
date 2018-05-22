#ifndef VECTOR_COMPLEX_H
#define VECTOR_COMPLEX_H
#include <complex.h>

class vector_complex
{
    protected:
    int dim;
    complex *elem;

    public:
        vector_complex(int a=0);
        ~vector_complex();
        vector_complex(const vector_complex&);
        virtual void adaugare(complex a)=0;
        virtual complex stergere()=0;
        friend istream& operator>>(istream &,vector_complex &);
        friend ostream& operator<<(ostream &,vector_complex &);
        void operator=(const vector_complex &b );
};

#endif // VECTOR_COMPLEX_H
