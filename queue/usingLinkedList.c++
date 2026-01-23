#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

class Queue{
    public:
    Node *head;
    Node *tail;
    Queue(){
        head=NULL;
        tail=NULL;
    }

    void push(int value){
        Node *newNode= new Node(value);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
    }

    void pop(){
        if(head==NULL){
            return;
        }
        Node *temp=head;
        head=head->next;
        delete temp;

        if(head==NULL){
            tail=NULL;

        }
    }

    int front(){
        if(head==NULL){
            throw runtime_error("Queue is empty");
        }
        return head->data;
    }

    bool isEmpty(){
        return head==NULL;
    }

    ~Queue(){
        while(!isEmpty()){
            pop();
        }
    }
}