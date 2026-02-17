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
    Node *head;
    Node *tail;
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

Node *cycleNode(Node *root){
    bool checkOne=false;
    Node *ptr1=root;
    ptr1=ptr1->next;
    Node *ptr2=root;
    if(ptr1!=NULL){
        ptr2=ptr2->next->next;
    }
    while(ptr1!=NULL&&ptr2!=NULL){
        if(checkOne){
            if(ptr1==ptr2){
                return ptr1;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }else{
            if(ptr1==ptr2){
                checkOne=true;
                ptr1=root;
            }

            ptr1=ptr1->next;
            if(ptr1!=NULL){
                ptr2=ptr2->next->next;
            }
        }
    }

    return NULL;
}

int main(){
    vector<int>vec={3,2,0,-4};
    LinkedList l1;
    for(auto i: vec){
        l1.insert(i);
    }

    l1.tail->next=l1.head->next->next;

    Node *cycleN=cycleNode(l1.head);
    cout<<cycleN->data<<endl;

    return 0;

}