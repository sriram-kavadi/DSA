#include<iostream>
#include<vector>
using namespace std;

void perm(vector<int>vec){
    vector<int>ans;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if((i^j)==vec[0]){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }

    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>vec={3,1};
    perm(vec);
}