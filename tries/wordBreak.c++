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
    Node *root;

    Trie(){
        root=new Node();
    }

    void insert(string word){
        Node *temp=root;
        for(auto s:word){
            if(temp->children.count(s)==0){
                temp->children[s]=new Node();
            }
            temp=temp->children[s];
        }
        temp->endOfWord=true;
    }

    bool search(string word){
        Node *temp=root;
        for(auto s:word){
            if(temp->children[s]==0){
                return false;
            }
            temp=temp->children[s];
        }
        return temp->endOfWord;
    }

};

bool helper(string key,Trie trie){
    if(key.size()==0){
        return true;
    }

    for(int i=0;i<key.size();i++){
        string first=key.substr(0,i+1);
        string secound=key.substr(i+1);
        if(trie.search(first)&&helper(secound,trie)){
            return true;
        }
    }

    return false;
}

bool wordBreak(vector<string>dict,string key){
    Trie trie;
    for(auto s:dict){
        trie.insert(s);
    }

    return helper(key,trie);
}

int main(){
    vector<string>dict={"i","like","sam","samsung","mobile","ice"};
    cout<<wordBreak(dict,"ilikesag")<<endl;

    return 0;
}
