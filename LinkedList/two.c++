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

class List{
    public:
    Node *head;
    Node *tail;

    List(){
        head=NULL;
        tail=NULL;
    }
    ~List(){
        Node *temp=head;
        while(temp!=NULL){
            Node *free=temp;
            temp=temp->next;
            delete free;
        }
        head=tail=NULL;
    }
    void push_front(int value){
        Node *newNode=new Node(value);
        newNode->next=head;
        head=newNode;
    }

    void push_back(int value){
        Node *newNode=new Node(value);
        tail->next=newNode;
        tail=newNode;
    }

    void insert(int value,int pos){
        if(pos==1){
            push_front(value);
            return;
        }

        Node *temp=head;
        int i=1;
        while(temp!=NULL&&i<pos-1){
            temp=temp->next;
            i++;
        }
        if(temp==NULL){
            cout<<"Out of range"<<endl;
            return;
        }
        Node *newNode=new Node(value);
        newNode->next=temp->next;
        temp->next=newNode;
        if(newNode->next==NULL){
            tail=newNode;
        }
    }

    void print(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void pop_front(){
        Node *temp=head;
        head=head->next;
        delete temp;
    }

    void pop_back(){
        Node *temp1=head;
        Node *temp2=tail;
        while(temp1->next!=tail){
            temp1=temp1->next;
        }
        Node *last=temp1->next;
        temp->next=NULL;
        delete last;
        tail=temp;
    }

    int interativeSearch(int key){
        Node *temp=head;
        int count=0;
        while(temp!=NULL){
            if(temp->data==key){
                return count;
            }
            count++;
            temp=temp->next;
        }
        return -1;
    }
    int helper(Node *h,int value,int idx){
        if(h->data=value){
            return idx;
        }
        if(h==NULL){
            return -1;
        }

        return helper(h->next,value,idx+1);

    }
    int recursiveSearch(int value){
        Node *temp=head;
        return helper(temp,value,0);
    }

    void reverse(){
        Node *temp=head;
        Node *prev=NULL;
        while(temp!=NULL){
            Node *next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }

    }

    int size(){
        int count=0;
        Node *temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }

    void removeNthNode(int n){
        int sizeOfList=size();
        if(n>sizeOfList||n<0){
            return;
        }
        if(n==size){
            pop_front();
            return;
        }
        Node *temp=head;
        for(int i=0;i<(size=n);i++){
            temp=temp->next;
            if(temp==NULL){
                return;
            }
        }
        Node *prev=temp->next;
        temp->next=temp->next->next;
        delete prev;
        if(temp->next==NULL){
            tail=temp;
        }
    }

    bool isCycle(){
        Node *s=head;
        Node *f=head;
        while(f->next!=NULL&&f->next->next!=NULL){
            f=f->next->next;
            s=s->next;
            if(f==s){
                return true;
            }
        }
        return false;
    }
}