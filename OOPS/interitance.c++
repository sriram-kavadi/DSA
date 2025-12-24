#include<iostream>
#include<string>
using namespace std;

class Animal{
    public:
    string color;
    void eat(){
        cout<<"eating.."<<endl;
    }

    void breath(){
        cout<<"breathing..."<<endl;
    }
};

class Fish :public Animal{
    public:
    int fins;
    void swim(){
        cout<<"swiming.."<<endl;
    }
};

int main(){
    Fish f1;
    f1.breath();
    f1.eat();
    f1.swim();
    return 0;
}