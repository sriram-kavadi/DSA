#include<iostream>
using namespace std;

void sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int mins=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mins]){
                mins=j;
            }
        }
        swap(arr[i],arr[mins]);
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