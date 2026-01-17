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

        if (head == NULL) {
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

    int size(){
        Node *temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }

    void modify(){
        Node *temp=head;
        int count=1;
        int n=size();
        Node *prev=head;
        while(temp!=NULL&&count<=n){
            if(temp->data%2!=0){
                tail->next=temp;
                temp=temp->next;
                prev->next=temp;
                tail=tail->next;
                tail->next=NULL;
            }else{
                prev=temp;
                temp=temp->next;
            }
            count++;
        }
    }
};

int main(){
    List li;
    li.push_back(1);
    li.push_back(3);
    li.push_back(5);
    li.push_back(7);

    li.modify();

    li.print();
    return 0;
}