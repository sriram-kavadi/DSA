#include<iostream>
using namespace std;

void transpose(int arr[][3],int n, int m){
    int mat[m][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mat[j][i]=arr[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int mat[2][3]={{1,2,3},{4,5,6}};
    transpose(mat,2,3);
    return 0; 
}