#include<iostream>
using namespace std;

bool search(int arr[][4],int n,int m,int target){
    int row=0,col=m-1;
    while(row<n&&col>=0){
        if(arr[row][col]==target){
            return true;
        }else if(arr[row][col]<target){
            row++;
        }else{
            col--;
        }
    }
    return false;
}

int main(){
    int mattrix[4][4]={{10, 20, 30, 40},
    {15, 25, 35, 45},
    {27, 29, 37, 48},
    {32, 33, 39, 50}};
    if(search(mattrix,4,4,37)){
        cout<<"found"<<endl;
    }else{
        cout<<"not found"<<endl;
    }
    return 0;
}