#include<iostream>
#include<vector>
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

class LinkedList{
    public:
    Node * head;
    Node * tail;
    LinkedList(){
        head=tail=NULL;
    }

    void insert(int value){
        Node *newNode=new Node(value);
        if(head==NULL){
            head=tail=newNode;
            return;
        }

        tail->next=newNode;
        tail=newNode;
    }
};

void print(Node *root){
    Node *temp=root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node *reverse(Node *root){
    Node *temp=root;
    Node *rev=NULL;
    while(temp!=NULL){
        Node *next=temp->next;
        temp->next=rev;
        rev=temp;
        temp=next;
    }
    return rev;
}

int main(){
    vector<int>vec={1,2,3,4,5};
    LinkedList l1;
    for(auto i:vec){
        l1.insert(i);
    }

    print(l1.head);

    Node *root=reverse(l1.head);

    print(root);

    return 0;
    
}