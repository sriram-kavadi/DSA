#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void greaterNumber(vector<int>arr){
    int n=arr.size();
    stack<int>s;
    vector<int>ans(n,-1);
    for(int i=n-1;i>=0;i--){
        while((!s.empty())&&(s.top()<=arr[i])){
            s.pop();
        }

        if(!s.empty()){
            ans[i]=s.top();
        }

        s.push(arr[i]);
    }

    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>arr={6,8,0,1,3};
    greaterNumber(arr);
    return 0;
}
