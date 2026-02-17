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
        head=NULL;
        tail=NULL;
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
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->next;
    }
    cout<<endl;
}

int size(Node *root){
    Node *temp=root;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

Node * middleLinkedList(Node *root){
    int n=size(root);
    Node *temp=root;
    int i=0;
    while(i<n/2){
        temp=temp->next;
        i++;
    }

    return temp;
}


int main(){
    vector<int>vec={1,2,3,4,5,6};
    LinkedList l1;

    for(auto i:vec){
        l1.insert(i);
    }

    print(l1.head);

    Node *root=middleLinkedList(l1.head);
    print(root);

    return 0;

}