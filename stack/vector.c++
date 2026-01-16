#include<iostream>
#include<vector>
using namespace std;

class stack{
    public:
    vector<int>stacks;
    
    void push(int value){
        stacks.push_back(value);
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        stacks.pop_back();
    }

    int top(){
        return stacks[stacks.size()-1];
    }

    bool isEmpty(){
        return stacks.size()==0;
    }
};

int main(){
    stack s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.pop();
    cout<<s.isEmpty()<<endl;
    cout<<s.top()<<endl;
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}