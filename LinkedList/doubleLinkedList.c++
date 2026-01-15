#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int value){
        data=value;
        next=NULL;
        prev=NULL;
    }
};

class List{
    public:
    Node *head;
    Node *tail;
    List(){
        head=NULL;
        tail=NULL;
    }

    ~List(){
        Node *curr=head;
        while(curr!=NULL){
            Node *nextNode=curr->next;
            delete curr;
            curr=nextNode;
        }
        head=tail=NULL;
    }

    void push_back(int value){
        if(head==NULL){
            head=tail=new Node(value);
            return;
        }

        Node *newNode=new Node(value);
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }

    void push_front(int value){
        if(head==NULL){
            head=tail=new Node(value);
            return;
        }

        Node *newNode =new Node(value);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }

    void pop_front(){
        if(head==NULL){
            return;
        }

        if(head==tail){
            delete head;
            head=tail=NULL;
            return;
        }

        Node *free=head;
        head=head->next;
        head->prev=NULL;
        delete free;
    }

    void pop_back(){
        if(head==NULL){
            return;
        }

        if(head==tail){
            delete head;
            head=tail=NULL;
            return;
        }

        Node *free=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete free;
    }

    
}