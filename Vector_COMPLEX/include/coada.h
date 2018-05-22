#ifndef COADA_H
#define COADA_H
#include <vector_complex.h>

class coada : public vector_complex
{
    public:
        coada(int a=0):vector_complex(a){};
        coada(const coada&a):vector_complex(a){};
        virtual void adaugare(complex a);
        virtual complex stergere();
        friend istream& operator>>(istream &,coada &);
        friend ostream& operator<<(ostream &,const coada );
        bool pur_imaginar();
        ~coada(){};
        coada& operator=(const coada &b );
    protected:

    private:
};

#endif // COADA_H
