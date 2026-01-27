#include<iostream>
#include<queue>
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

void kthLevel(Node *root,int k){
    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    int i=1;
    while(!q.empty()){
        Node *curr=q.front();
        q.pop();
        if(curr==NULL){
            if(q.empty()){
                break;
            }
            q.push(NULL);
            i++;
        }else{
            if(i==k){
            cout<<curr->data<<" ";
            }
            if(curr->left!=NULL ) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
    }
    cout<<endl;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node *root=insert(nodes);

    kthLevel(root,4);
    return 0;
}