#include<iostream>
#include<string>
using namespace std;

class Car{
    string name;
    string color;
    public:
    //constructor without parameter
    Car(){
        cout<<"Object is initialised"<<endl;
    }
    // constructor with parameters
    Car(string name,string color){
        name=name;
        color=color;
    }
    void start(){
        cout<<"Car is started..."<<endl;
    }
    void stop(){
        cout<<"Car is stoped..."<<endl;
    }
};

int main(){
    Car c0;
    Car c1("Honda","red");
    c1.start();
    c1.stop();
    return 0;
}