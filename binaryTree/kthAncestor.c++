#include<iostream>
#include<vector>
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
}

bool found(Node *root,int n,vector<int>&path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }

    bool leftCheck=found(root->left,n,path);
    bool rightCheck=found(root->right,n,path);
    if((!leftCheck)&&(!rightCheck)){
        path.pop_back();
    }

    return rightCheck||leftCheck;

}
bool found1(Node *root,int n,int &k,int &value){
    if(root==NULL){
        return false;
    }
    if(root->data==n){
        return true;
    }

    bool leftCheck=found1(root->left,n,k,value);
    bool rightCheck=found1(root->right,n,k,value);
    if((!leftCheck)&&(!rightCheck)){
        return false;
    }
    k--;
    if(k==0){
        value=root->data;
    }
    return rightCheck||leftCheck;

}

int foundValue(Node *root,int n,int k){
    int value=-1;
    found1(root,n,k,value);
    return value;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node *root=insert(nodes);

    vector<int>path;

    // found(root,5,path);

    // int k=2;
    // for(int i=0;i<path.size();i++){
    //     if(i==k-2){
    //         cout<<path[i]<<endl;
    //         break;
    //     }
    // }

    cout<<foundValue(root,5,0)<<endl;

    return 0;
}