#include <iostream>
#include <ctime>
using namespace std;

class Vector{
    int* arr;
    int n;
    public:
    int* getArr(){
        return arr;
    }
    Vector(int newN){
        arr = new int(newN);
        n=newN;
        srand(time(NULL));
        for(int i = 0; i<n;i++){
            arr[i]=rand()%10;
        }
    }

    void print(){
        for(int i = 0; i<n;i++){
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }

    void operator+(int number){
        for(int i = 0; i<n;i++){
            arr[i]+=number;
        }
    }
    void operator-(int number){
        for(int i = 0; i<n;i++){
            arr[i]-=number;
        }
    }
    void operator-(){
        for(int i = 0; i<n;i++){
            arr[i]-=(arr[i]*2);
        }
    }

    void operator=(Vector &newVector){
        delete arr;
        arr = newVector.getArr();
    }
};
int main(){
    Vector v1 = Vector(5);
    cout<<"First vector"<<endl;
    v1.print();
    cout<<"Add 3 to every element"<<endl;
    v1+3;
    v1.print();
    cout<<"Minus 5 to every element"<<endl;
    v1-5;
    v1.print();
    -v1;
    v1.print();
    cout<<"Second vector"<<endl;
    Vector v2 = Vector(5);
    v2.print();
    cout<<"First vector = Second vector"<<endl;
    v1=v2;
    cout<<"First vector   ";
    v1.print();
    return 0;
}

