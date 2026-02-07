#include<iostream>
using namespace std;

class Node{
    public:
    string key;
    int value;
    Node *next;
    Node(string key,int value){
        this->key=key;
        this->value=value;
        next=NULL;
    }

    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

class hashFunction{
    int tatSize;
    int curSize;
    Node ** table;
    int hashFunc(string key){
        int id=0;

        for(int i=0;i<key.size();i++){
            id = (id + key[i] * key[i]) % tatSize;

        }

        return id;
    }
    void rehash(){// o(n)
        Node **oldTable=table;
        int oldSize=tatSize;

        tatSize=(2*tatSize);
        curSize=0;
        table=new Node*[tatSize];

        for(int i=0;i<tatSize;i++){
            table[i]=NULL;
        }

        for(int i=0;i<oldSize;i++){
            Node *temp=table[i];
            while(temp!=NULL){
                insert(temp->key,temp->value);
                temp=temp->next;
            }
            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
        }
        
        delete [] oldTable;

    }
    public:
    hashFunction(int size){
        tatSize=size;
        curSize=0;
        table=new Node*[tatSize];
        
        for(int i=0;i<tatSize;i++){
            table[i]=NULL;
        }
    }

    void insert(string key,int value){//o(1)
        int idx=hashFunc(key);
        Node *newNode=new Node(key,value);
        newNode->next=table[idx];
        table[idx]=newNode;
        curSize++;

        double lamda=(double)curSize/tatSize;
        if(lamda>1){
            rehash();//o(n) worst case
        }
    }

    void remove(string key){
        int idx=hashFunc(key);
        Node *temp=table[idx];
        Node *prev=temp;
        while(temp!=NULL){
            if(temp->key==key){
                if(temp==prev){
                    table[idx]=temp->next;
                }else{
                    prev->next=temp->next;
                }
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }

    bool exists(string key){
        int idx=hashFunc(key);
        Node *temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    int search(string key){
        int idx=hashFunc(key);
        Node *temp=table[idx];
        while(temp!=NULL &&temp->key!=key){
            temp=temp->next;
        }

        if (temp == NULL) {
            throw runtime_error("Key not found");
        }
        return temp->value;
    }

    void print(){
        for(int i=0;i<tatSize;i++){
            cout<<"Idx: "<<i<<"-> ";
            Node *temp=table[i];
            while(temp!=NULL){
                cout<<"(Key: "<<temp->key<<","<<"Value: "<<temp->value<<") -> ";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }
};

int main(){
    hashFunction h1(5);
    h1.insert("India",150);
    h1.insert("China",150);
    h1.insert("US",50);
    h1.insert("Nepal",10);
    h1.insert("UK",20);

    if(h1.exists("India")){
        cout<<"India found"<<endl;
        cout<<h1.search("India")<<endl;
    }

    h1.print();
    cout<<"-----"<<endl;
    h1.remove("China");
    h1.print();
    return 0;
}