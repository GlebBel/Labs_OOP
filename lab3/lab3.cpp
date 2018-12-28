#include <iostream>
#include <ctime>
using namespace std;

class Numbers{
    protected:
    double n1;
    double n2;
    public:
    virtual void add() = 0;
    virtual void minus()=0;
    virtual void mult()=0;
    virtual void dev()=0;
};

class Integers:public Numbers{
    public:
    Integers(int newN1, int newN2){
        n1 = newN1;
        n2 = newN2;
        cout<<"Integers are "<<n1<<" and "<<n2<<endl;
    }

    virtual void add(){
        cout<<"Add Integers "<<n1+n2<<endl;
    }

    virtual void minus(){
        cout<<"Minus Integers "<<n1-n2<<endl;
    }

    virtual void mult(){
        cout<<"Multiple Integers "<<n1*n2<<endl;
    }

    virtual void dev(){
        cout<<"Devide Integers "<<n1/n2<<endl;
    }
};

class Floats:public Numbers{
    public:
    Floats (float newN1, float newN2){
        n1 =  newN1;
        n2 = newN2;
        cout<<"Floats are "<<n1<<" and "<<n2<<endl;
    }

    virtual void add(){
        cout<<"Add Floats "<<n1+n2<<endl;
    }

    virtual void minus(){
        cout<<"Minus Floats "<<n1-n2<<endl;
    }

    virtual void mult(){
        cout<<"Multiple Floats "<<n1*n2<<endl;
    }

    virtual void dev(){
        cout<<"Devide Floats "<<n1/n2<<endl;
    }
};

class Complexs:public Numbers{
    float img1;
    float img2;
    public:
    Complexs(float newN1, float newIm1, float newN2, float newIm2){
        n1 =  newN1;
        n2 = newN2;
        img1 = newIm1;
        img2 = newIm2;
        cout<<"Complex numbers are: real part "<<n1<<" ,imagine part "<<img1<<" , real part "<<n2<<" ,imagine part "<<img2<<endl;
    }

    virtual void add(){
        cout<<"Add Complex numbers real part "<<n1+n2<<" ,imagine part "<<img1+img2<<endl;
    }

    virtual void minus(){
        cout<<"Minus Complex numbers real part "<<n1-n2<<" ,imagine part "<<img1-img2<<endl;
    }

    virtual void mult(){
        cout<<"Multiple Complex numbers real part "<<n1*n2-img1*img2<<" ,imagine part "<<n1*img2+img1*n2<<endl;
    }

    virtual void dev(){
        double r = img2 * img2 + n2 * n2;
        cout<<"Devide Complex numbers real part "<<(n1*n2+img1*img2)/r<<" ,imagine part "<<(n2*img1-img2*n1)/r<<endl;
    }
};

int main(){
    cout<<"Bilous Glib 2 variant B"<<endl;
    cout<<endl;
    Numbers* n = new Integers(5, 6);
    n->add();
    n->minus();
    n->mult();
    n->dev();
    cout<<endl;
    Numbers* f = new Floats(3.5, 6.3);
    f->add();
    f->minus();
    f->mult();
    f->dev();
    cout<<endl;
    Numbers* c = new Complexs(1.3, 2.3, 3.6, 4.3);
    c->add();
    c->minus();
    c->mult();
    c->dev();
    return 0;
}