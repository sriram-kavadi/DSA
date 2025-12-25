#include<iostream>
#include <algorithm>
#include<climits>
using namespace std;

int trapping_rainwater(int *arr,int n){
    int leftMax[n],rightMax[n];
    leftMax[0]=arr[0];
    for(int i=1;i<n;i++){
        leftMax[i]=max(leftMax[i-1],arr[i]);
    }
    rightMax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        rightMax[i]=max(rightMax[i+1],arr[i]);
    }
    int area=0;
    for(int i=1;i<n-1;i++){
        int temp=min(leftMax[i],rightMax[i])-arr[i];
        if(temp>0){
            area+=temp;
        }
    }
    return area;
}

int main(){
    int arr[]={4,2,0,3,2,5};
    int n=7;
    int area=trapping_rainwater(arr,n);
    cout<<"amount of water : "<<area<<endl;
    return 0;
}