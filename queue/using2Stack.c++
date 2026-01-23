#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int>st1;
    stack<int>st2;
    public:
    void push(int value){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(value);
        while(!st2.empty()){
            st1.push(st2.top());
            st1.pop();
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        st1.pop();
    }

    int front(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return st1.top();
    }

    bool isEmpty(){
        return st1.empty();
    }
}