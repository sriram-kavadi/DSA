#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
    public:
    unordered_map<char,Node *>children;
    bool endOfWord;

    Node(){
        endOfWord=false;
    }
};

class Trie{
    public:
    Node *root;

    Trie(){
        root=new Node();
    }

    void insert(string word){
        Node *temp=root;
        for(auto i:word){
            if(temp->children.count(i)==0){
                temp->children[i]=new Node();
            }
            temp=temp->children[i];
        }
        temp->endOfWord=true;
    }

    bool startsWith(string word){
        Node *temp=root;

        for(auto i:word){
            if(temp->children.count(i)==0){
                return false;
            }
            temp=temp->children[i];
        }

        return true;
    }
};

int main(){
    vector<string>words={"apple","app","mango","man","woman"};
    Trie trie;
    for(auto s:words){
        trie.insert(s);
    }

    cout<<trie.startsWith("moon")<<endl;

    return 0;
}