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


int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node *root=insert(nodes);

    Node *lca=LCA(root,4,6);
    cout<<lca->data<<endl;

    return 0;

}