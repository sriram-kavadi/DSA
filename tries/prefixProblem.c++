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
            if(temp->children.count(s)==0){
                return false;
            }
        }
        return true;
    }
 
    string prefixs(string word){
        Node *temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->children.size()==1){
                return word.substr(0,i);
            }
            temp=temp->children[word[i]];
        }
        return word;
    }
};

vector<string>preFix(Trie trie,vector<string>words){
    vector<string>ans;
    for(auto s:words){
        ans.push_back(trie.prefixs(s));
    }

    return ans;

}


int main(){
    vector<string>words={"zebra","dog","duck","dove"};
    Trie trie;
    for(auto s:words){
        trie.insert(s);
    }

    vector<string>ans=preFix(trie,words);
    
    for(auto s:ans){
        cout<<s<<" ";
    }
    cout<<endl;

    return 0;
}