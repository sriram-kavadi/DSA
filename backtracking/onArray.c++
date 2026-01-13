#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>&arr){
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

void changeArray(vector<int>&arr,int i){
    if(i==arr.size()){
        print(arr);
        return ;
    }
    arr[i]=i+1;
    changeArray(arr,i+1);
    arr[i]-=2;
}

int main(){
    vector<int>vec(5,0);
    changeArray(vec,0);
    print(vec);
    return 0;
}