#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Student{
    public:
    string name;
    int marks;

    Student(string name,int marks){
        this->name=name;
        this->marks=marks;
    }

    bool operator < (const Student &obj)const {
        return this->marks<obj.marks;
    }
};


int main(){
    priority_queue<Student>pq;
    pq.push(Student("nikhil",100));
    pq.push(Student("sriram",22));
    pq.push(Student("madhu",166));
    pq.push(Student("alekhya",89));
    pq.push(Student("akhila",999));

    while(!pq.empty()){
        cout<<pq.top().name<<" "<<pq.top().marks<<endl;
        pq.pop();
    }

    return 0;
}

