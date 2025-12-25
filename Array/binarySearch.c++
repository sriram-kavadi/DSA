#include<iostream>
using namespace std;

int binarySearch(int *arr,int n,int key){
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=(end-start)/2+start;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]<key){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[7]={1,2,5,34,45,66,99};
    int size=7;
    int key=66;
    int index=binarySearch(arr,size,key);
    if(index!=-1){
        cout<<"Found at: "<<index<<endl;
    }else{
        cout<<"Not Found:/"<<endl;
    }
    return 0;
}