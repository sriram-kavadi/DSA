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

bool rootToNodePath(Node *root,int n,vector<int>&path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }

    int isLeft=rootToNodePath(root->left,n,path);
    int isRight=rootToNodePath(root->right,n,path);

    if(isLeft || isRight){
        return true;
    }

    path.pop_back();
    return false;
}

int minDistanceBetweenNodes(Node *root,int n1,int n2){
    vector<int>path1;
    vector<int>path2;

    rootToNodePath(root,n1,path1);
    rootToNodePath(root,n2,path2);

    int lca=-1;
    int count=0;
    for(int i=0,j=0;i<path1.size()&&j<path2.size();i++,j++){
        if(path1[i]!=path2[j]){
            break;
        }
        count++;
        lca=path1[i];
    }

    int size1=path1.size();
    int size2=path2.size();
    return size1+size2-count*2;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node *root=insert(nodes);

    cout<<minDistanceBetweenNodes(root,4,6);

    return 0;

}