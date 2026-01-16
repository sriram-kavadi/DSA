#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T value){
        data=value;
        next=NULL;
    }
};

template<class T>
class Stack{
    Node<T> *tops;
    public:
    Stack(){
        tops=NULL;
    }

    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }

    void push(T value){
        Node<T> *newNode=new Node<T>(value);
        if(tops==NULL){
            tops=newNode;
            return;
        }
        newNode->next=tops;
        tops=newNode;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
        }

        Node *temp=tops;
        tops=tops->next;
        delete temp;
    }

    T top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        return tops->data;
    }

    bool isEmpty(){
        return tops==NULL;
    }

    void print(){
        Node<T>* temp=tops;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
        }
    }

    void pushAtButton(int value){

    }
};

int main(){
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.print();
    return 0;
}