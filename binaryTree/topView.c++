#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int value){
        data=value;
        left=right=NULL;
    }
};

static int idx=-1;

Node * insert(vector<int>nodes){
    idx++;
    if(idx<nodes.size() && nodes[idx]==-1){
        return NULL;
    }

    Node *newNode=new Node(nodes[idx]);

    newNode->left=insert(nodes);
    newNode->right=insert(nodes);

    return newNode;
};

void topView(Node * root){
    queue<pair<Node*,int>>q;//node,hd
    map<int,int>mp;//hd,data
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node *,int>curr=q.front();
        q.pop();
        if(curr.first->left!=NULL) q.push(make_pair(curr.first->left,(curr.second)-1));
        if(curr.first->right!=NULL) q.push(make_pair(curr.first->right,(curr.second)+1));
        if(mp.count(curr.second)==0){
            mp[curr.second]=curr.first->data;
        }
    }

    for(auto it:mp){
        cout<<it.second<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node *root=insert(nodes);
    topView(root);
    
    return 0;
}