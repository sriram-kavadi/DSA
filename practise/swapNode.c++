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

void swap(Node *temps,int key1,int key2){
    Node *head=temps;
    Node *prev1;//1
    Node *prev2;//3
    while(head!=NULL&&head->data!=key1){
        prev1=head;
        head=head->next;
    }

    while(head!=NULL&&head->data!=key2){
        prev2=head;
        head=head->next;
    }

    cout<<prev1->data<<" <-> "<<prev2->data<<endl;

    Node *temp=prev1->next; //2
    Node *next1=prev1->next->next; //3
    Node *next2=prev2->next->next;//5
    prev1->next=prev2->next;//1->4
    prev1->next->next=next1;//1->4->3
    prev2->next=temp;//3->2
    prev2->next->next=next2; //3->2->5

    while(temps!=NULL){
        cout<<temps->data<<"->";
    }
    cout<<endl;
    
}

int main(){
    List li;
    li.push_back(1);
    li.push_back(2);
    li.push_back(3);
    li.push_back(4);
    li.push_back(5);
    swap(li.head,2,4);
    return 0;
}