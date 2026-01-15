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

    // // Destructor to avoid memory leaks
    // ~List() {
    //     while (head != NULL) {
    //         pop_front();
    //     }
    // }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void push_front(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "Empty linked list\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) tail = NULL;
    }

    void pop_back() {
        if (head == NULL) {
            cout << "Empty linked list\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void insert(int val, int pos) {
        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        int i = 0;

        while (temp != NULL && i < pos - 1) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            delete newNode;
            cout << "Out of range\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    void search(int key) {
        Node* temp = head;
        int idx = 0;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Found at index " << idx << "\n";
                return;
            }
            temp = temp->next;
            idx++;
        }
        cout << "Not found\n";
    }

    int searchRec(Node* temp, int key, int idx) {
        if (temp == NULL) return -1;
        if (temp->data == key) return idx;
        return searchRec(temp->next, key, idx + 1);
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail = head;
        head = prev;
    }

    // Delete Nth node from end
    void deleteNthFromEnd(int n) {
        if (head == NULL) return;

        int size = 0;
        Node* temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        if (n > size) return;

        if (n == size) {
            pop_front();
            return;
        }

        Node* curr = head;
        for (int i = 1; i < size - n; i++) {
            curr = curr->next;
        }

        Node* del = curr->next;
        curr->next = del->next;
        if (del == tail) tail = curr;
        delete del;
    }
};

Node *merge(Node *left,Node *right){
    List li;
    Node *l=left;
    Node *r=right;
    int value;
    while(l!=NULL&&r!=NULL){
        if(l->data<r->data){
            value=l->data;
            li.push_back(value);
            l=l->next;
        }else{
            value=r->data;
            li.push_back(value);
            r=r->next;
        }
    }
    
    while(l!=NULL){
        value=l->data;
        li.push_back(value);
        l=l->next;
    }

    while(r!=NULL){
        value=r->data;
        li.push_back(value);
        r=r->next;
    }

    return li.head;
}

Node * splitAtMid(Node *head){
    Node *slow=head;
    Node *fast=head;
    Node *prev=NULL;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        prev=slow;
        slow=slow->next;
    }
    if(prev!=NULL){
        prev->next=NULL;
    }
    return slow;
}

Node* mergeSort(Node *head){
    if(head==NULL ||head->next==NULL){
        return head;
    }
    Node *rightHead=splitAtMid(head);

    Node *left=mergeSort(head);
    Node *right=mergeSort(rightHead);

    return merge(left,right);
}



int main(){
    List ll;
    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);
    ll.print();
    ll.head=mergeSort(ll.head);
    ll.print();
    return 0;
}