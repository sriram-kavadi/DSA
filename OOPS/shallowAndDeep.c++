#include<iostream>
#include<string>
using namespace std;

class Car{
    public:
    string name;
    string color;
    int *mileage;
    
    Car(string name,string color){
        this->name=name;
        this->color=color;
        mileage=new int;
        *mileage=12;
    }

    Car(Car &c){
        name=c.name;
        color=c.color;
        mileage=new int;
        *mileage=*c.mileage;
    }

    void getDetails(){
        cout<<name<<" "<<color<<" "<<*mileage<<endl;
    }
};

int main(){
    Car c1("maruti","white");
    Car c2(c1);
    c2.getDetails();
    *c2.mileage=10;
    c2.getDetails();
    c1.getDetails();
    return 0;
}