#include<iostream>
using namespace std;

void sort(int arr[],int n){
    int freq[n]={0};
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    int idx=0;
    for(int i=0;i<n;i++){
        while(freq[i]>0){
            arr[idx]=i;
            freq[i]--;
            idx++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[8]={1,4,1,3,2,4,3,7};
    sort(arr,8);
    return 0;
}