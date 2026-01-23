#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int>q1;
    queue<int>q2;
    public:

    void push(int value){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(value);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is Empty "<<endl;
            return;
        }

        q1.pop();
    }

    int top(){

        if(isEmpty()){
            cout<<"Stack is Empty "<<endl;
            return;
        }

        return q1.front();

    }

    bool isEmpty(){
        return q1.empty();
    }
}