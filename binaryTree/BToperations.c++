#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

int dia1(Node *root){//o(n^2)
    if(root==NULL){
        return 0;
    }

    int currDia=mxHeight(root->left)+mxHeight(root->right)+1;//o(n)
    int leftDia=dia1(root->left);
    int rightDia=dia1(root->right);
    
    return max(currDia, max(leftDia, rightDia));
}

pair<int,int>dia2(Node *root){
    if(root==NULL){
        return make_pair(0,0);
    }

    //(diameter,height)
    pair<int,int>leftInfo=dia2(root->left);
    pair<int,int>rightInfo=dia2(root->right);
    int currDia=leftInfo.second+rightInfo.second+1;
    int finalDia=max(currDia,max(leftInfo.first,rightInfo.first));
    int finalHt=max(leftInfo.second,rightInfo.second)+1;

    return make_pair(finalDia,finalHt);
}

bool check(Node *root,Node *find){
    if(root==NULL){
        return false;
    }

    if(root->data==find->data){
        return true;
    }

    return (check(root->left,find)||check(root->right,find));
}

bool isIdentical(Node *root1,Node *root2){
    if(root1==NULL && root2==NULL){
        return true;
    }else if(root1==NULL || root2==NULL){
        return false;
    }

    if(root1->data!=root2->data){
        return false;
    }

    return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
}

bool subTreeCheck(Node *root,Node *subTree){
    if(root==NULL && subTree==NULL){
        return true;
    }else if(root==NULL || subTree==NULL){
        return false;
    }

    if(root->data==subTree->data){
        if(isIdentical(root,subTree)){
            return true;
        }
    }

    if(!subTreeCheck(root->left,subTree)){
        return subTreeCheck(root->right,subTree);
    }

    return true; 
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

    cout<<"Diameter Of A Tree: "<<dia1(root)<<endl;

    pair<int,int>final=dia2(root);
    cout<<"Height of the tree: "<<final.second<<" Diameter of a tree: "<<final.first<<endl;

    //trial node exist or not
    Node *newNode=new Node(2);
    if(check(root,newNode)){
        cout<<"Found :)"<<endl;
    }else{
        cout<<"Not Found :/"<<endl;
    }

    //subTree
    Node *subTree=new Node(2);
    subTree->left=new Node(4);
    subTree->right=new Node(5);
    if(subTreeCheck(root,newNode)){
        cout<<"Found :)"<<endl;
    }else{
        cout<<"Not Found:/"<<endl;
    }


    return 0;
}