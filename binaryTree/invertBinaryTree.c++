#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node* right;
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

Node *invertBinaryTree(Node *root){
    if(root==NULL){
        return NULL;
    }

    
    Node *leftNode=invertBinaryTree(root->left);
    Node *rightNode=invertBinaryTree(root->right);

    root->left=rightNode;
    root->right=leftNode;

    return root;
    
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node *root=NULL;

    vector<int>vec={4,2,7,1,3,6,9}

}