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

int kthAncestor(Node *root,int node,int k){
    if(root==NULL){
        return -1;
    }

    if(root->data==node){
        return 0;
    }

    int leftDist=kthAncestor(root->left,node,k);
    int rightDist=kthAncestor(root->right,node,k);

    if(leftDist == -1 && rightDist == -1){
        return -1;  // node not found in either subtree
    }

    int validVal=leftDist==-1?rightDist:leftDist;

    if(validVal+1==k){
        cout<<"kth Ancestor is: "<<root->data<<endl;
    }

    return validVal+1;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node *root=insert(nodes);

    cout<<kthAncestor(root,6,2)<<endl;

    return 0;
}
