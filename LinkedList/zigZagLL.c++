#include<iostream>
#include<list>
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

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

Node* splitHead(Node *head){
    Node* slow=head;
    Node* fast=head;
    Node *prev=NULL;
    while(fast!=NULL&&fast->next!=NULL){
        prev=slow;
        fast=fast->next->next;
        slow=slow->next;
    }
    if(prev!=NULL){
        prev->next=NULL;
    }
    return slow;
}

Node* reverse(Node *head){
    Node *curr=head;
    Node *prev=NULL;
    while(curr!=NULL){
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Node *zigZag(Node *head){
    Node *rightHead=splitHead(head);
    Node *right=reverse(rightHead);
    Node *left=head;
    Node *tail=NULL;
    while(left!=NULL&&right!=NULL){
        Node * nextLeft=left->next;
        Node * nextRight=right->next;
        left->next=right;
        right->next=nextLeft;
        tail=right;
        left=nextLeft;
        right=nextRight;
    }
    if(right!=NULL){
        tail->next=right; 
    }
    return head;
}

int main(){
    List li;
    li.push_back(1);
    li.push_back(2);
    li.push_back(3);
    li.push_back(4);
    li.push_back(5);
    li.print();
    li.head=zigZag(li.head);
    li.print();
    return 0;
}