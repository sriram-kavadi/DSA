#include<iostream>
#include<string>
using namespace std;

class Student{

    string name;
    float cgpa;

    public:

    //setter
    void setName(string name1){
        name=name1;
    }
    void setCgpa(float cgpa1){
        cgpa=cgpa1;
    }

    //getter
    string getName(){
        return name;
    }
    float getCgpa(){
        return cgpa;
    }

    //methods
    void studentDetails(){
        cout<<name<<" "<<cgpa<<endl;
    }

};

int main(){
    Student s1;
    s1.setName("nikhil");
    s1.setCgpa(9.92);
    s1.studentDetails();
    return 0;
}