#include<iostream>
using namespace std;

class Animal{
    public:
    void breath(){
        cout<<"Breathing..."<<endl;
    }
    void eating(){
        cout<<"Eating..."<<endl;
    }
};

class Mammel:public Animal{
    public:
    string BloodType="Warm";
};

class Dog:public Mammel{
    public:
    void tailwag(){
        cout<<"tailwaging..."<<endl;
    }
};

int main(){
    Dog d1;
    cout<<d1.BloodType<<endl;
    d1.breath();
    d1.tailwag();
    return 0;
}