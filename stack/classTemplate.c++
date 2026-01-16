#include<iostream>
#include<vector>
using namespace std;

template <class T>
class Stack{
    vector<T>stacks;
    public:
    void push(T value){
        stacks.push_back(value);
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        stacks.pop_back();
    }

    T top(){
        return stacks[stacks.size()-1];
    }

    bool isEmpty(){
        return stacks.size()==0;
    }

    void pushAtButtom(T value){
        if(isEmpty()){
            push(value);
            return;
        }

        T topValue=top();
        pop();
        pushAtButtom(value);
        push(topValue);
    }

    void print(){
        for(int i=stacks.size()-1;i>=0;i--){
            cout<<stacks[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Stack<int>s;
    s.push(3);
    s.push(2);
    s.push(1);
    s.print();
    s.pushAtButtom(4);
    s.print();
    return 0;
}