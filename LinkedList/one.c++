#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        data=this->data;
    }
};

class List{
    Node *head;
    Node *tail;
    public:
    List(){
        head=NULL;
        tail=NULL;
    }
    void print(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void push_front(int data){
        Node *newNode=new Node(data);
        if(head==NULL&&tail==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
    void push_back(int data){
        Node *newNode=new Node(data);
        if(head==NULL&&tail==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    };
    void pop_front(){
        if(head==NULL&&tail==NULL){
            cout<<"Empty linked list"<<endl;
            return;
        }else{
            Node *temp=head;
            head=head->next;
            delete temp;
        }
    };
    
    void pop_back(){
        if(head==NULL){
            cout<<"Empty linked list"<<endl;
            return;
        }
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        Node *temp1=temp;
        delete temp->next;
        tail=temp1;
    }

    void insert(int val,int pos){
        if(pos==0){
            push_front(val);
            return;
        }
        Node *newNode=new Node(val);
        Node *temp=head;
        int i=0;
        while(temp!=NULL&&i<pos-1){
            temp=temp->next;
            i++;
        }
        if(temp==NULL){
            cout<<"Out of range:/"<<endl;
            return;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        if(newNode->next==NULL){
            tail=newNode;
        }
    };

    void search(int key){
        if(head==NULL){
            cout<<"Empty linked list"<<endl;
            return;
        }

        Node *temp =head;
        int i=0;
        while(temp!=NULL){
            if(temp->data==key){
                cout<<"Fount at : "<<i<<endl;
                return;
            }
            temp=temp->next;
            i++;
        }
        cout<<"Not found:/"<<endl;
    }

    int searchRec(Node *temp,int key,int idx){
        if(temp==NULL){
            return -1;
        }

        if(temp->data==key){
            return idx;
        }

        return searchRec(temp->next,key,idx+1);
    }

    void reverse(){
        Node *temp1=head;
        Node *rev=NULL;
        while(temp1!=NULL){
            Node *next=temp1;
            next->next=rev;
            rev=next;
            temp1=temp1->next;
        }
        head=rev;
    }

    void deleteNthNode(int n){
        int size=0;
        Node *temp=head;
        while(temp!=NULL){
            temp=temp->next;
            size++:
        }
        if(n>size){
            return;
        }
        Node *temp1=head;
        int i=0;
        while(temp1!=null&&i<=size-n){
            temp1=temp1->next;
        }
        Node *nthNode=temp1->next;
        temp1->next=temp1->next->next;
        delete nthNode;
        if(temp1->next==NULL){
            tail=temp1;
        }
    }
}