#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    string key;
    int value;
    Node *next;
    Node(string key,int value){
        this->key=key;
        this->value=value;
        this->next=NULL;
    }
};

int main(){
    vector<Node*> vec(6, NULL);

    vec[2] = new Node("nikhil", 34);
    Node* temp = new Node("sriram", 88);
    vec[2]->next = temp;

    Node* temp1 = vec[2];
    while (temp1 != NULL) {
        cout << temp1->key << " " << temp1->value << endl;
        temp1 = temp1->next;
    }

    return 0;

}