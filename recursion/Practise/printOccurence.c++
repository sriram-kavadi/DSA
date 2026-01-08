#include<iostream>
#include<vector>
using namespace std;

void occurence(vector<int>&vec,int key,int i){
    if(i>=vec.size()){
        return;
    }
    if(vec[i]==key){
        cout<<i<<" ";
    }
    occurence(vec,key,i+1);
}

int main(){
    vector<int>vec={3,2,4,5,6,2,7,2,2};
    int key=2;
    occurence(vec,key,0);
    return 0;
}