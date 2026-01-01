#include<iostream>
using namespace std;

bool search(int arr[][4],int n,int m,int target){
    for(int i=0;i<n;i++){
        int start=0;
        int end=m-1;
        if(arr[i][start]<=target && arr[i][k]>=target){
            while(j<=m){
                int mid=(j-i)/2+i;
                if(arr[i][mid]==target){
                    return true;
                }else if(arr[i][mid]<target){
                    j=mid+1;
                }else{
                    k=mid-1;
                }
            }
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