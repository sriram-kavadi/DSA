#include<iostream>
#include<string>
using namespace std;

class Teacher{
    public:
    int salary;
    string subject;
};

class Student{
    public:
    int rollNo;
    float cgpa;
};

class Ta:public Teacher, public Student{
    public:
    string name;
};

int main(){
    Ta ta1;
    ta1.name="nikhil";
    ta1.salary=23000;
    ta1.rollNo=47;
    ta1.cgpa=9.2;
    ta1.subject="DSA";
    return 0;
}