#include<iostream>
#include<vector>
#include<string>
using namespace std;

int gridWays(int row,int col,int n,int m,string ans){
    if(row==n-1&&col==m-1){
        cout<<ans<<endl;
        return 1;
    }
    if(row>=n||col>=m){
        return 0;
    }

    //right
    int val1=gridWays(row,col+1,n,m,ans+"R");
    //down
    int val2=gridWays(row+1,col,n,m,ans+"D");
    return val1+val2;
}

int main(){
    cout<<"No of ways: "<<gridWays(0,0,3,3,"");
    return 0;
}