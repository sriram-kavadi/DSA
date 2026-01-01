#include<iostream>
using namespace std;

int count(int mat[][3],int n,int m){
    int counts=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==7){
                counts++;
            }
        }
    }
    return counts;
}
int sum(int mat[][3],int n,int m){
    int sums=0;
    for(int i=0;i<n;i++){
        sums+=mat[1][i];
    }
    return sums;
}

int main(){
    int arr[][3]={{4,7,8},{8,8,7}};
    cout<<"count of 7 is : "<<count(arr,2,3)<<endl;
    int nums[][3]={{1,4,9},{11,4,3},{2,2,3}};
    cout<<"sum of the 2nd row is :"<<sum(nums,3,3)<<endl;

    return 0; 
}