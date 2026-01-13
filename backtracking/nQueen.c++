#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>>board,int row,int col){
    int n=board.size();
    //horizontal
    for(int j=0;j<n;j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
    //vertical
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    //diagonal left
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    //diagonal right
    for(int i=row,j=col;i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void print(vector<vector<char>>board){
    int n=board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-----------"<<endl;
}

bool nQueen(vector<vector<char>>board,int row){
    int n=board.size();
    if(row==n){
        return true;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(isSafe(board,row,i)){
            board[row][i]='Q';
            if(nQueen(board,row+1)){
                return true;
            }
            board[row][i]='.';
        }
    }
    return false;
}

int main(){
    vector<vector<char>>board;
    int n=2;
    for(int i=0;i<n;i++){
        vector<char>row;
        for(int j=0;j<n;j++){
            row.push_back('.');
        }
        board.push_back(row);
    }
    cout<<"No of possibles: "<<nQueen(board,0);
    return 0;
}