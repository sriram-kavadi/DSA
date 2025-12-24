#include<iostream>
using namespace std;

class Student{
    //properties || attributes
    string name;
    float cgpa;
    //methods || functions
    void getPrecentage(){
        cout<<(cgpa*10)<<endl;
    }
};

class User{
    int id;
    string name;
    int follower;
    int following;
    void edit_username(){

    }
    void delete_post(){

    }
};

int main(){
    Student s1;
    cout<<sizeof(s1);
    return 0;
}