#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
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

void  preOrder(Node *root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root){
    if(root==NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node *root){
    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node *root){
    if(root==NULL){
        cout<<"Empty Tree";
        return;
    }
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        Node *curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
    }
}

int mxHeight(Node *root){
    if(root==NULL){
        return 0;
    }

    int leftHeight=mxHeight(root->left);
    int rightHeight=mxHeight(root->right);

    return leftHeight>rightHeight? leftHeight+1 : rightHeight+1;
}

int count(Node *root){
    if(root==NULL){
        return 0;
    }

    int leftCount=count(root->left);
    int rightCount=count(root->right);

    return leftCount+rightCount+1;
}

int sum(Node *root){
    if(root==NULL){
        return 0;
    }

    int leftSum=sum(root->left);
    int rightSum=sum(root->right);

    return leftSum+rightSum+root->data;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node *root=insert(nodes);

    cout<<"PreOrder: ";
    preOrder(root);
    cout<<endl;

    cout<<"InOrder: ";
    inOrder(root);
    cout<<endl;

    cout<<"PostOrder: ";
    postOrder(root);
    cout<<endl;

    cout<<"LevelOrder: ";
    levelOrder(root);
    cout<<endl;

    cout<<"Max height: "<<mxHeight(root)<<endl;

    cout<<"Count No Of Nodes: "<<count(root)<<endl;

    cout<<"Sum Of Nodes: "<<sum(root)<<endl;

    return 0;
}