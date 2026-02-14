#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
    public:
    unordered_map<char,Node*>children;
    bool endOfWord;
    Node(){
        endOfWord=false;
    }
};

class Trie{
    public:
    Node * root;

    Trie(){
        root=new Node();
    }

    void insert(string key){
       Node * temp=root;
       for(auto i:key){
        if(temp->children.count(i)==0){
            temp->children[i]=new Node();
        }
        temp=temp->children[i];
       }

       temp->endOfWord=true;
    }

    bool search(string key){
        Node *temp=root;
        for(auto s:key){
            if( temp->children.count(s)==0){
                return false;
            }
            temp=temp->children[s];
        }
        return temp->endOfWord;
    }


};

int main(){
    vector<string>words={"the","a","there","their","any","three"};
    Trie trie;

    for(auto s:words){
        trie.insert(s);
    }

    cout<<trie.search("t")<<endl;

    return 0;

}

