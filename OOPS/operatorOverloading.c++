#include<iostream>
using namespace std;

class ComplexNumber{
    float real;
    float imaginary;
    public:
    ComplexNumber(float r,float i){
        real=r;
        imaginary=i;
    }
    void show(){
        cout<<real<<"+"<<imaginary<<"i"<<endl;
    }
    ComplexNumber operator +(ComplexNumber &obj){
        float real=this->real+obj.real;
        float imaginary=this->imaginary+obj.imaginary;
        ComplexNumber c3(real,imaginary);
        return c3;
    }
    ComplexNumber operator -(ComplexNumber &obj){
        float real=this->real-obj.real;
        float imaginary=this->imaginary-obj.imaginary;
        ComplexNumber c3(real,imaginary);
        return c3;
    }
};

int main(){
    ComplexNumber c1(1,2);
    ComplexNumber c2(3,4);
    c1.show();
    c2.show();
    ComplexNumber c3= c1+c2;
    c3.show();
    ComplexNumber c4=c1-c2;
    c4.show();
    return 0;
}