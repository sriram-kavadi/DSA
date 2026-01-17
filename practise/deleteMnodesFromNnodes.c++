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

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {   // empty list
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// void deleteMNodeFromNnodes(Node **head,int m,int n,int count){
//     int count=0;
//     Node *temp=*head;
//     while(temp!=NULL&&count<m-1){
//         temp=temp->next;
//         count++;
//     }
//     Node *free=temp->next;
//     count=0;
//     while(free!=NULL&&count<n){
//         Node *de=free;
//         free=free->next;
//         delete de;
//         count++;
//     }
//     temp->next=free;
    
//     Node *check=*head;
//     while(check!=NULL){
//         cout<<check->data<<"->";
//         check=check->next;
//     }
//     cout<<"NULL"<<endl;
// }

void deleteMNodeFromNnodes(Node *temp,int m,int n){
    if(temp==NULL){
        return;
    }
    int count=0;
    while(temp!=NULL&&count<m-1){
        temp=temp->next;
        count++;
    }
    Node *free=temp!=NULL?temp->next:NULL;
    count=0;
    while(free!=NULL&&count<n){
        Node *de=free;
        free=free->next;
        delete de;
        count++;
    }
    if(temp!=NULL){
        temp->next=free;
    }
    deleteMNodeFromNnodes(free,m,n);
}

int main(){
    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);
    l1.push_back(7);
    l1.push_back(8);
    l1.push_back(9);
    l1.push_back(10);
    l1.push_back(11);
    l1.push_back(12);


    deleteMNodeFromNnodes(l1.head,4,3);
    l1.print();
    return 0;
}