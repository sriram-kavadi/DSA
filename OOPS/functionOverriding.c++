#include<iostream>
using namespace std;

class Parent{
    public:
    void show(){
        cout<<"Parent show function"<<endl;
    }
};

class Child:public Parent{
    public:
    void show(){
        cout<<"Child show function"<<endl;
    }
};

int main(){
    Child c1;
    c1.show();
    return 0;
}