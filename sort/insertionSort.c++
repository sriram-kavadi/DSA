#include<iostream>
using namespace std;

void sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int current=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>current){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[5]={5,4,1,3,2};
    sort(arr,5);
    return 0;
}