#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    int bigCount=0;
    int smallCount=0;
    for(int i=0;i<n-1;i++){
        bigCount++;
        for(int j=0;j<n-i-1;j++){
            smallCount++;
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
        cout<<smallCount<<endl;
        smallCount=0;
    }
    cout<<bigCount<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[5]={5,4,1,3,2};
    bubbleSort(arr,5);
    return 0;
}