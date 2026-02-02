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



Node *insert(Node *root,int value){
    if(root==NULL){
        return new Node(value);
    }

    if(root->data>value){
        root->left=insert(root->left,value);
    }else{
        root->right=insert(root->right,value);
    }

    return root;

}


Node *builtBstFromSorted(int arr[],int st,int end){
    if(st>end){
        return NULL;
    }

    int mid=st+(end-st)/2;
    Node *curr=new Node(arr[mid]);
    curr->left=builtBstFromSorted(arr,st,mid-1);
    curr->right=builtBstFromSorted(arr,mid+1,end);

    return curr;
}

void call(Node * &root,vector<int>vec,int start,int end){
    if(start<=end){
        int mid=(start+end)/2;
        root=insert(root,vec[mid]);
        cout<<vec[mid]<<" ";
        call(root,vec,start,mid-1);
        call(root,vec,mid+1,end);
    }
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void sortedBst(Node *root,vector<int>&sorted){
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    sorted.push_back(root->data);
    inorder(root->right);
}


int main(){
    int arr[]={3,4,5,6,7,8,9};
    Node *root=builtBstFromSorted(arr,0,6);
    inorder(root);

    vector<int>sorted1;
    sortedBst(root1,sorted1);
    vector<int>sorted2;
    sortedBst(root2,sorted2);
    vector<int>merge;
    int i=0,j=0;
    while(i<sorted1.size()&&j<sorted2.size()){
        if(sorted1[i]<sorted2[j]){
            merge.push_back(sorted1[i]);
            i++;
        }else{
            merge.push_back(sorted2[j]);
            j++;
        }
    }

    while(i<sorted1.size()){
        merge.push_back(sorted1[i]);
        i++;
    }

    while(j<sorted2.size()){
        merge.push_back(sorted2[j]);
        j++;
    }

    Node *mergeRoot=builtBstFromSorted(merge,0,merge.size()-1);
    inorder(mergeRoot);



    Node *root=builtBstFromSorted(arr,0,6);


    return 0;
}