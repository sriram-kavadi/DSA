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

Node *insert(Node *root,int node){
    if(root==NULL){
        return new Node(node);
    }

    if(root->data>node){
        root->left=insert(root->left,node);
    }else{
        root->right=insert(root->right,node);
    }

    return root;

}


bool searchNode(Node *root,int node){
    if(root==NULL){
        return false;
    }

    if(root->data==node){
        return true;
    }

    if(root->data>node){
        return searchNode(root->left,node);
    }else{
        return searchNode(root->right,node);
    }

}

void inOrder(Node *root){
    if(root==NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

Node *inorderSuccessor(Node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node *deleteNode(Node *root,int node){
    if(root==NULL){
        return NULL;
    }

    if(root->data==node){
        return root;
    }else if(root->data>node){
        root->left=deleteNode(root->left,node);
    }else if(root->data<node){
        root->right=deleteNode(root->right,node);
    }else{
        if(root->left==NULL&&root->right==NULL){
            Node *temp=root;
            delete temp;
            return NULL;
        }

        if(root->left!=NULL&&root->right!=NULL){
            Node *is=inorderSuccessor(root->right);
            root->data=is->data;
            root->right=deleteNode(root->right,is->data);
            return root;
        }

        if(root->left!=NULL){
            Node *temp=root;
            delete temp;
            return root->left;
        }

        if(root->right!=NULL){
            Node *temp=root;
            delete temp;
            return root->right;
        }


    }
}

void printInRange(Node *root,int start,int end){
    if(root==NULL){
        return;
    }
    
    printInRange(root->left,start,end);
    if(root->data>=start &&root->data<=end){
        cout<<root->data<<" ";
    }
    printInRange(root->right,start,end);
}

void printINRange(Node *root,int start,int end){
    if(root==NULL){
        return;
    }
    if(root->data>=start&&root->data<=end){
        printINRange(root->left,start,end);
        cout<<root->data<<" ";
        printINRange(root->right,start,end);
    }else if(root->data<start){
        printINRange(root->right,start,end);
    }else{
        printINRange(root->left,start,end);
    }
}

void printPath(Node *root,vector<int>&path){
    if(root==NULL){
        return;
    }

    path.push_back(root->data);
    printPath(root->left,path);
    path.pop_back();
    printPath(root->right,path); 
}

bool validate(Node *root,int min,int max){
    if(root==NULL){
        return true;
    }

    if(min!=NULL&& root->data<min){
        return false;
    }
    if(max!=NULL&&root->data>max){
        return false;
    }

    return validate(root->left,min,root->data) && validate(root->right,root->data,max);
}

Node * sortedArray(Node *root,vector<int>arr,int start,int end){
    root=insert((start+end)/2);
    sortedArray(Node *root,arr,start,(start+end)/2-1);
    sortedArray(Node *root,(start+end)/2+1,end);
    return root;
}

int main(){
    vector<int> vec = {8, 5, 10, 3, 6, 11, 1, 4, 14};

    Node *root=NULL;
    for(int i:vec){
        root=insert(root,i);
    }

    inOrder(root);
    cout<<endl;

    if(searchNode(root,9)){
        cout<<"Found :)"<<endl;
    }else{
        cout<<"Not Found :/"<<endl;
    }

    printInRange(root,5,12);
    cout<<endl;

    deleteNode(root,5);
    inOrder(root);
    cout<<endl;

    printINRange(root,5,12);
    cout<<endl;

    vector<int>path;
    printPath(root,path);


    cout<<"Is valid bst : "<<validate(root,NULL,NULL)<<endl;

    vector<int>arr={3,4,5,6,7,8,9};
    
    return 0;

}