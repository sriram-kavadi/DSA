#include<iostream>
using namespace std;

class Person{
    public:
    string name;
    int age;
    Person(string name,int age){
        this->name=name;
        this->age=age;
    }
};

class Student:public Person{
    public:
    int studentId;
    Student(string name,int age,int studentId):Person(name,age){
        this->studentId=studentId;
    }
    void displayStudentInfo(){
        cout<<"your details: "<<endl;
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<studentId<<endl;
    }

};

int main(){
    Student s1("nikhil",18,9138);
    s1.displayStudentInfo();
    return 0;
}