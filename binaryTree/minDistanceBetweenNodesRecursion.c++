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

Node *LCA(Node * root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node *leftSubTree=LCA(root->left,n1,n2);
    Node *rightSubTree=LCA(root->right,n1,n2);

    if(leftSubTree!=NULL&&rightSubTree!=NULL){
        return root;
    }

    if(leftSubTree!=NULL){
        return root;
    }

    if(rightSubTree!=NULL){
        return root;
    }
    return NULL;
}
//timecomplexity : o(n)
//space complexity : o(1)

int distance(Node *root,int n){
    if(root==NULL){
        return -1;
    }

    if(root->data==n){
        return 0;
    }

    int leftCheck=distance(root->left,n);
    int rightCheck=distance(root->right,n);
    
    if(leftCheck==-1&&rightCheck==-1){
        return -1;
    }

    return leftCheck==-1?rightCheck+1:leftCheck+1;
}


int minDistance(Node *root,int n1, int n2){ //o(n)
    Node *lca=LCA(root,n1,n2);//o(n)
    int distance1=distance(root,n1);
    int distance2=distance(root,n2);
    
    return distance1+distance2;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node *root=insert(nodes);

    cout<<minDistance(root,4,6)<<endl;

    return 0;

}