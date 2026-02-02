#include<iostream>
using namespace std;

class Student{
    public:
    string name;
    int age;
    int *salary;
    Student(string name,int age,int salary){
        this->name=name;
        this->age=age;
        this->salary=new int;
        *(this->salary)=salary;
    }

    void getData(){
        cout<<this->name<<endl;
        cout<<this->age<<endl;
        cout<<*(this->salary)<<endl;
    }

    Student(Student &s){
        this->name=s.name;
        this->age=s.age;
        this->salary=new int;
        *(this->salary)=*(s.salary);
    }

    ~Student(){
        delete salary;
    }
};

int main(){
    Student s("nikhil",18,1500);
    s.getData();
    Student s1(s);
    *(s.salary)=1000;
    s1.getData();
    return 0;
}