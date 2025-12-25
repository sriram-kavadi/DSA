#include<iostream>
using namespace std;

void reverseArray(int *arr,int n){
    int temp=n-1;
    for(int i=0;i<n/2;i++){
        int temp1=arr[i];
        arr[i]=arr[temp];
        arr[temp]=temp1;
        temp--;
    }
}
void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[7]={2,5,34,1,66,45,99};
    int size=7;
    int key=66;
    reverseArray(arr,size);
    printArray(arr,size);
    return 0;
}