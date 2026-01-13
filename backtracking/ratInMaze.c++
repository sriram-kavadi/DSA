#include<iostream>
#include<vector>
using namespace std;

int ratInMaze(vector<vector<int>>vec,int row,int col,string ans){
    int n=vec.size();
    if(row>=n||col>=n||row<0||col<0){
        return 0;
    }

    if(vec[row][col]==0){
        return 0;
    }

    if(row==n-1&&col==n-1){
        cout<<ans<<endl;
        return 1;
    }
    vec[row][col]=0;
    //down
    int val1=ratInMaze(vec,row+1,col,ans+'D');
    //right
    int val2=ratInMaze(vec,row,col+1,ans+'R');
    //up
    int val3=ratInMaze(vec,row-1,col,ans+'U');
    //left
    int val4=ratInMaze(vec,row,col-1,ans+'L');
    vec[row][col]=1;
    return val1+val2+val3+val4;
}

int main(){

    vector<vector<int>>vec={
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    cout<<"no of ways : "<<ratInMaze(vec,0,0,"");
    return 0;
}