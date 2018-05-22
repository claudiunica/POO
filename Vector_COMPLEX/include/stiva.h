#ifndef STIVA_H
#define STIVA_H
#include <vector_complex.h>

class stiva : public vector_complex
{
    public:
        stiva(int a=0):vector_complex(a){};
        stiva(const stiva&a):vector_complex(a){};
        ~stiva(){};
        virtual void adaugare(complex a);
        virtual complex stergere();
        friend istream& operator>>(istream &,stiva &);
        friend ostream& operator<<(ostream &,const stiva );
        bool pur_imaginar();
        stiva& operator=(const stiva &b );
    protected:

    private:
};

#endif // STIVA_H
